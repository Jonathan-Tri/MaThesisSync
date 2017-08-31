/*
 * testTCPClient.cpp
 *
 *  Created on: Mar 29, 2017
 *      Author: trivv
 */

/*
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>

#include "SocketException.h"
#include "TCPProtocol.h"

const int RCVBUFSIZE = 32;

int main(int argc, char *argv[]) {
	if (argc < 3 || argc >4) {
		std::cerr << "Usage: " << argv[0] <<
				" <Server> <Echo String> [<Server Port>]" << std::endl;
		exit(1);
	}

	std::string servAddr = argv[1];
	char *echoStr = argv[2];
	int echoStrLen = strlen(echoStr);
	unsigned short echoServPort = (argc == 4) ? atoi(argv[3]) : 7;

	try {
		// Establish connection with the echo server
		TCPSocket sock(servAddr, echoServPort);

		// send the string to the server
		sock.send(echoStr, echoStrLen);

		// receive buffer from the server
		char echoBuffer[RCVBUFSIZE + 1];
		int bytesReceived = 0;
		int totalBytesReceived = 0;
		do {
			if ((bytesReceived = sock.recv(echoBuffer, RCVBUFSIZE)) <= 0) {
				std::cerr << "Unable to read";
				exit(1);
			}
			totalBytesReceived += bytesReceived;
			echoBuffer[bytesReceived] = '\0';
			std::cout << echoBuffer;
		}while (1);
		std::cout << std::endl;
	}
	catch (SocketException &ex) {
		std::cerr << ex.what() << std::endl;
		exit(1);
	}

	return 0;
}
*/

