/*
 * ISocket.h
 *
 *  Created on: Mar 28, 2017
 *      Author: trivv
 */

#ifndef SRC_COMUNICATION_ISOCKET_H_
#define SRC_COMUNICATION_ISOCKET_H_

#include <string>

#include "SocketException.h"


class ISocket {
public:
	~ISocket();
	std::string getLocalAddress() throw(SocketException);
	unsigned short getLocalPort() throw(SocketException);
	void setLocalPort(unsigned short localPort) throw(SocketException);
	void setLocalAddressAndPort(const std::string& localAddress,
			unsigned short localPort = 0) throw(SocketException);
	static unsigned short resolveService(const std::string& service,
			const std::string& protocol = "tcp") throw(SocketException);
private:
	ISocket(const ISocket &socket);
	void operator=(const ISocket &socket);
protected:
	int sockDesc;
	ISocket(int type, int protocol);
	ISocket(int socketDescription);
};


#endif /* SRC_COMUNICATION_ISOCKET_H_ */
