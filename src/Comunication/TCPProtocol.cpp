///*
// * TCPProtocol.cpp
// *
// *  Created on: Mar 29, 2017
// *      Author: trivv
// */
//
//#include "TCPProtocol.h"
//
//#ifdef _WIN32
//	#include <winsock.h>
//	#include <winsock2.h>
//#else
//	#include <netinet/in.h>
//	#include <sys/socket.h>
//#endif
//#include "SocketException.h"
//
//#pragma comment(lib, "WS2_32.lib")
//
///*********************TCP Socket Protocol Implementation**************/
//TCPSocket::TCPSocket() throw (SocketException) : SocketProtocol(SOCK_STREAM, IPPROTO_TCP) {
//}
//
//TCPSocket::TCPSocket(const std::string& foreignAddr, unsigned short foreignPort)
//		throw (SocketException) : SocketProtocol(SOCK_STREAM, IPPROTO_TCP) {
//	connect(foreignAddr, foreignPort);
//}
//
//TCPSocket::TCPSocket(int newConnSD) : SocketProtocol(newConnSD) {
//}
///********************************************************************/
//
///*************TCP Server Socket Protocol Implementation**************/
//TCPServerSocket::TCPServerSocket(unsigned short localPort, int queueLen)
//		throw(SocketException) : ISocket(SOCK_STREAM, IPPROTO_TCP) {
//	setLocalPort(localPort);
//	setListen(queueLen);
//}
//
//TCPServerSocket::TCPServerSocket(const std::string& localAddr,
//		unsigned short localPort, int queueLen) throw (SocketException)
//				: ISocket(SOCK_STREAM, IPPROTO_TCP) {
//	setLocalAddressAndPort(localAddr, localPort);
//	setListen(queueLen);
//}
//
//TCPSocket* TCPServerSocket::accept() throw (SocketException) {
//	int newConnSD;
//
//	if ((newConnSD = ::accept(sockDesc, NULL, 0)) < 0) {
//		throw SocketException("Accept failed <(accept()>", true);
//	}
//
//	return new TCPSocket(newConnSD);
//}
//
//void TCPServerSocket::setListen(int queueLen) throw (SocketException) {
//	if (listen(sockDesc, queueLen) < 0) {
//		throw SocketException("Set listening socket failed <listen()>", true);
//	}
//}
///********************************************************************/
