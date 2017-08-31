///*
// * SocketException.cpp
// *
// *  Created on: Mar 28, 2017
// *      Author: trivv
// */
//
//#include <cstring>
//#include <errno.h>
//
//#include "SocketException.h"
//
//SocketException::SocketException(const std::string& message,
//		bool inclSysMsg) throw () : Message(message) {
//	if (inclSysMsg) {
//		Message.append(": ");
//		Message.append(strerror(errno));
//	}
//}
//
//SocketException::~SocketException() throw () {
//
//}
//
//const char* SocketException::what() const throw () {
//	return Message.c_str();
//}
