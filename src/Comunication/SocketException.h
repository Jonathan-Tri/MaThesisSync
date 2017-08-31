/*
 * SocketException.h
 *
 *  Created on: Mar 28, 2017
 *      Author: trivv
 */

#ifndef SRC_COMUNICATION_SOCKETEXCEPTION_H_
#define SRC_COMUNICATION_SOCKETEXCEPTION_H_

#include <string>


class SocketException {
public:
	SocketException(const std::string &message, bool inclSysMsg = false) throw();
	~SocketException() throw();
	const char *what() const throw();

private:
	std::string Message;  // Exception message
};


#endif /* SRC_COMUNICATION_SOCKETEXCEPTION_H_ */
