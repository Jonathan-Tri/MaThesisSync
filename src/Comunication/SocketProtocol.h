/*
 * SocketProtocol.h
 *
 *  Created on: Mar 29, 2017
 *      Author: trivv
 */

#ifndef SRC_COMUNICATION_SOCKETPROTOCOL_H_
#define SRC_COMUNICATION_SOCKETPROTOCOL_H_

#include <string>

#include "ISocket.h"

#include "SocketException.h"


class SocketProtocol : public ISocket {
public:
	void connect(const std::string &foreignAddr, unsigned short foreignPort) throw(SocketException);
	void send(const void* buffer, int bufferLen) throw(SocketException);
	int recv(void* buffer, int bufferLen) throw(SocketException);
	std::string getForeignAddr() throw(SocketException);
	unsigned short getForeignPort() throw(SocketException);
protected:
	SocketProtocol(int type, int protocol) throw(SocketException);
	SocketProtocol(int newConnSD);
};


#endif /* SRC_COMUNICATION_SOCKETPROTOCOL_H_ */
