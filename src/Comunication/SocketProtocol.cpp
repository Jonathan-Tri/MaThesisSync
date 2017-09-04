/*
 * SocketProtocol.cpp
 *
 *  Created on: Mar 29, 2017
 *      Author: trivv
 */

#ifdef WIN32
	#include <winsock.h>		// For socket(), connect(), send(), and recv()
	typedef int socklen_t;
	typedef char raw_type;
#else
	#include <sys/types.h>		// For data types
	#include <sys/socket.h>		// For socket(), connect(), send(), and recv()
	#include <netdb.h>			// For gethostbyname()
	#include <arpa/inet.h>		// For inet_addr()
	#include <unistd.h>			// For close()
	#include <netinet/in.h>		// For sockaddr_in
	typedef void raw_type;		// Type used for raw data on this platform
#endif

#include "SocketProtocol.h"

void SocketProtocol::connect(const std::string& foreignAddr,
		unsigned short foreignPort) throw (SocketException) {
	sockaddr_in destAddr;
	// Fill destination address with
	destAddr.sin_family = AF_INET;
	hostent *host;
	if ((host = gethostbyname(foreignAddr.c_str())) == NULL) {
		throw SocketException("Failed to resolve the name <gethostbyname()>");
	}
	destAddr.sin_addr.s_addr = *((unsigned long *)host->h_addr_list[0]);
	destAddr.sin_port = htons(foreignPort);

	// Try to connect to given address
	if (::connect(sockDesc, (sockaddr *) &destAddr, sizeof(destAddr)) < 0) {
		throw SocketException("Connect failed (connect())", true);
	}
}

void SocketProtocol::send(const void* buffer, int bufferLen)
		throw (SocketException) {
	if (::send(sockDesc, (raw_type *) buffer, bufferLen, 0) < 0) {
		throw SocketException("Send failed (send())", true);
	}
}

int SocketProtocol::recv(void* buffer, int bufferLen) throw (SocketException) {
	int rtn;

	if ((rtn = ::recv(sockDesc, (raw_type *) buffer, bufferLen, 0)) < 0) {
		throw SocketException("Received failed (recv())", true);
	}

	return rtn;
}

std::string SocketProtocol::getForeignAddr() throw (SocketException) {
	sockaddr_in addr;
	unsigned int addr_len = sizeof(addr);

	if (getpeername(sockDesc, (sockaddr *) &addr, (socklen_t *) &addr_len) < 0) {
		throw SocketException("Fetch of foreign port failed (getpeername())", true);
	}

	return inet_ntoa(addr.sin_addr);
}

unsigned short SocketProtocol::getForeignPort() throw (SocketException) {
	sockaddr_in addr;
	unsigned int addr_len = sizeof(addr);

	if (getpeername(sockDesc, (sockaddr *) &addr, (socklen_t *) &addr_len) < 0) {
		throw SocketException("Fetch of foreign port failed (getpeername())", true);
	}

	return ntohs(addr.sin_port);
}

SocketProtocol::SocketProtocol(int type, int protocol)
throw (SocketException) : ISocket(type, protocol) {
}

SocketProtocol::SocketProtocol(int newConnSD) : ISocket(newConnSD) {

}
