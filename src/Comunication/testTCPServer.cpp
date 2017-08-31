///*
// * testTCPServer.cpp
// *
// *  Created on: Mar 29, 2017
// *      Author: trivv
// */
//
//#include <cstdlib>
//#include <iostream>
//#include <string>
//
//#include "../SharedAlgorithm/SharedAlgorithm.h"
//#include "SocketException.h"
//#include "TCPProtocol.h"
//
//const unsigned int RCVBUFSIZE = 32;
//
//void HandleTCPClient(TCPSocket *sock);
///*
//int main(int agrc, char *agrv[]) {
//
//	if (agrc != 2) {
//		std::cerr << "Usage: " << agrv[0] << " <Server Port>" << std::endl;
//		exit(1);
//	}
//
//	unsigned short echoServPort = atoi(agrv[1]);
//	try {
//		TCPServerSocket servSock(echoServPort);
//		while (true) {
//			HandleTCPClient(servSock.accept()); // Waiter for a client to connect
//		}
//	}
//	catch (SocketException &ex) {
//		std::cerr << ex.what() << std::endl;
//		exit(1);
//	}
//
//	std::cout << "CLOSING TCP SERVER SOCKET TESTING!" << std::endl;
//	return 0;
//}*/
//
//void HandleTCPClient(TCPSocket *sock) {
//	std::cout << "Handling client ";
//	try {
//		std::cout << sock->getForeignAddr() << " : ";
//	}
//	catch (SocketException &ex) {
//		std::cerr << "Unable to get foreign address: ";
//		std::cerr << ex.what() << std::endl;
//	}
//
//	try {
//		std::cout << sock->getForeignPort() << " : ";
//	}
//	catch (SocketException &ex) {
//		std::cerr << "Unable to get foreign address: ";
//		std::cerr << ex.what() << std::endl;
//	}
//
//	// received string until the end of transmission
//	//const char *servPrefix = "[Server has gotten]: ";
//	char echoBuffer[RCVBUFSIZE];
//	int recvMsgSize;
//	while ((recvMsgSize = sock->recv(echoBuffer, RCVBUFSIZE)) > 0) {
//		echoBuffer[recvMsgSize] = '\0';
//		// echo the massage
//		std::cout << "[SERVER] :" << SharedAlgorithm::getCurrTime() <<
//				" - [received the buffer]: " << echoBuffer << std::endl;
//		// send the feedback to the client
//		//sock->send(servPrefix, strlen(servPrefix));
//		sock->send(echoBuffer, recvMsgSize);
//	}
//	delete sock;
//}
//
//
