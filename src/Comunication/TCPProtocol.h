/*
 * TCPProtocol.h
 *
 *  Created on: Mar 29, 2017
 *      Author: trivv
 */

#ifndef SRC_COMUNICATION_TCPPROTOCOL_H_
#define SRC_COMUNICATION_TCPPROTOCOL_H_

#include <string>

#include "SocketProtocol.h"
#include "SocketException.h"


class TCPSocket : public SocketProtocol {
public:
	TCPSocket() throw(SocketException);
	TCPSocket(const std::string &foreignAddr, unsigned short foreignPort) throw(SocketException);

private:
	friend class TCPServerSocket;
	TCPSocket(int newConnSD);
};


class TCPServerSocket : public ISocket {
public:
	TCPServerSocket(unsigned short localPort, int queueLen = 5) throw(SocketException);
	TCPServerSocket(const std::string &localAddr, unsigned short localPort,
			int queueLen = 5) throw(SocketException);
	TCPSocket *accept() throw(SocketException);
private:
	void setListen(int queueLen) throw(SocketException);
};


#endif /* SRC_COMUNICATION_TCPPROTOCOL_H_ */
