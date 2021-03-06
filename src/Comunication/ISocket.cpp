/*
 * ISocket.cpp
 *
 *  Created on: Mar 28, 2017
 *      Author: trivv
 */

#include <cstdlib>
#include <cstring>
#include <string>

#include "SocketException.h"
#include <winsock.h>
//#include <winsock2.h>

#ifdef _WIN32
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

#include "ISocket.h"

ISocket::~ISocket() {
	if (sockDesc >= 0) {
#ifdef _WIN32
		closesocket(sockDesc);
#elif
		close(sockDesc);
#endif // _WIN32		
	}
	sockDesc = -1;
}

std::string ISocket::getLocalAddress() throw (SocketException) {
	sockaddr_in addr;
	unsigned int addr_len = sizeof(addr);

	if (getsockname(sockDesc, (sockaddr *) &addr, (socklen_t *) &addr_len) < 0) {
		throw SocketException("Fetch of local address failed <getsockname()>", true);
	}

	return inet_ntoa(addr.sin_addr);
}

unsigned short ISocket::getLocalPort() throw (SocketException) {
	sockaddr_in addr;
	unsigned int addr_len = sizeof(addr);

	if (getsockname(sockDesc, (sockaddr *) &addr, (socklen_t *) &addr_len) < 0) {
		throw SocketException("Fetch of local address failed <getsockname()>", true);
	}

	return ntohs(addr.sin_port);
}

void ISocket::setLocalPort(unsigned short localPort) throw (SocketException) {
	// bind the socket to its port
	sockaddr_in localAddr;
	memset(&localAddr, 0, sizeof(localAddr));
	localAddr.sin_family = AF_INET;
	localAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	localAddr.sin_port = htons(localPort);

	if (bind(sockDesc, (sockaddr *) &localAddr, sizeof(localAddr)) < 0) {
		throw SocketException("Set local port failed <bind()>", true);
	}
}

void ISocket::setLocalAddressAndPort(const std::string& localAddress,
		unsigned short localPort) throw (SocketException) {
	sockaddr_in localAddr;

	// fill address and port by given values
	memset(&localAddr, 0, sizeof(localAddr));
	localAddr.sin_family = AF_INET;
	hostent *host;
	if ((host = gethostbyname(localAddress.c_str())) == NULL) {
		throw SocketException("Failed to resolve the name <gethostbyname()>");
	}
	localAddr.sin_addr.s_addr = *((unsigned long *)host->h_addr_list[0]);
	localAddr.sin_port = htons(localPort);

	// bind the socket with given address and port
	if (bind(sockDesc, (sockaddr *) &localAddr, sizeof(localAddr)) < 0) {
		throw SocketException("Set of local address and port failed <bind()>", true);
	}
}

unsigned short ISocket::resolveService(const std::string& service,
		const std::string& protocol) throw (SocketException) {
	struct servent *serv; //Structure containing service information

	if ((serv = getservbyname(service.c_str(), protocol.c_str())) == NULL) {
		return atoi(service.c_str()); // Service is port number
	}
	else {
		return ntohs(serv->s_port); //Found port (network byte order) by name
	}
}

ISocket::ISocket(int type, int protocol) {
	// make new socket
	if ((sockDesc = socket(PF_INET, type, protocol)) < 0) {
		throw SocketException("Socket creation failed <socket()>", true);
	}
}

ISocket::ISocket(int socketDescription) {
	sockDesc = socketDescription;
}
