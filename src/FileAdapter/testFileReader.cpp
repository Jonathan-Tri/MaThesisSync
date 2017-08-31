/*
 * testFileReader.cpp
 *
 *  Created on: Mar 24, 2017
 *      Author: trivv
 */

#include <cstdio>
#include <exception>
#include <string>

#include "FileReaderFactory.h"
#include "IFileReader.h"


const char *file1 = "resource/01.txt"; // a good file
const char *file2 = "resource/011.txt"; // a bad file

void testCFileReader() {
	printf("+++ STARTING TEST CFILEREADER +++\n");
	IFileReader *frd = FileReaderFactory::getInstance().create(OLD_FILE_TYPE, file1);

	std::string line;

	// test old file reader operation
	bool tc1, tc2, tc3, tc4, tc5, tc6, tc7, tc8;
	tc1 = frd->isOpen(); // test case 1: opening file
	if (tc1) {
		// test case 2: get the line into std::string

		tc2 = frd->getLine(line);
		printf("The first line: %s\n", line.c_str());
		tc2 = frd->getLine(line);
		printf("The second line: %s\n", line.c_str());
		// end test case 2

		// test case 3: get the line into char buffer
		char buffer[256] = {0};
		tc3 = frd->getLine(buffer);
		printf("The third line: %s\n", buffer);
		tc3 = frd->getLine(buffer);
		printf("The fourth line: %s\n", buffer);
		// end test case 3

		// test case 4: get the buffer into char buffer
		char buf[100] = {0};
		tc4 = frd->getBuffer(buf, 50);
		printf("The buffer with size 50: %s\n", buf);
		tc4 = frd->getBuffer(buf, 30);
		printf("The buffer with size 30: %s\n", buf);
		tc4 = frd->getBuffer(buf, 30);
		printf("The buffer with size 30: %s\n", buf);
		// end test case 4

		// test case 5: get the buffer into string buffer
		std::string nbuf;
		tc5 = frd->getBuffer(nbuf, 20);
		printf("The std:string buffer with size 20: %s\n", nbuf.c_str());
		tc5 = frd->getBuffer(nbuf, 40);
		printf("The std:string buffer with size 40: %s\n", nbuf.c_str());
		// end test case 5

		// test case 6: close file
		frd->close();
		tc6 = frd->isOpen();
		try {
			std::string line;
			if (tc6) {
				tc6 = frd->getLine(line);
				tc6 = false;
			}
			else {
				printf("Closing file successfully!\n");
				tc6 = true;
			}
		}
		catch (std::exception& ex) {
			tc6 = true;
			printf("Closing file successfully!\n");
		}
		delete frd;
		// end test case 6
	}

	// test case 7: check end-of-file
	IFileReader* reader = FileReaderFactory::getInstance().create(OLD_FILE_TYPE, file1);
	int lineCnt = 0;
	while (!reader->isEOF()) {
		reader->getLine(line);
		lineCnt++;
	}
	if (lineCnt > 444) {
		tc7 = true;
	}
	printf("There is %d line(s) in the file %s\n", lineCnt, file1);
	delete reader;
	// end test case 7

	// test case 8: try to open the bad file
	IFileReader* badReader = FileReaderFactory::getInstance().create(OLD_FILE_TYPE, file2);
	if (badReader->isOpen()) {
		tc8 = false;
	}
	else {
		tc8 = true;
		printf("The file %s does not exist!\n", file2);
	}
	delete badReader;
	// end test case 8
	if (tc1 && tc2 && tc3 && tc4 && tc5 && tc6 && tc7 && tc8) {
		printf("PASSED TEST!!!");
	}
	else {
		printf("FAILED TEST!!!");
	}
	printf("+++ ENDING TEST CFILEREADER +++\n");
}

void testEFileReader() {
	printf("+++ STARTING TEST EFILEREADER +++\n");
	IFileReader *frd = FileReaderFactory::getInstance().create(NEW_FILE_TYPE, file1);

	std::string line;

	// test old file reader operation
	bool tc1, tc2, tc3, tc4, tc5, tc6, tc7, tc8;
	tc1 = frd->isOpen(); // test case 1: opening file
	if (tc1) {
		// test case 2: get the line into std::string

		tc2 = frd->getLine(line);
		printf("The first line: %s\n", line.c_str());
		tc2 = frd->getLine(line);
		printf("The second line: %s\n", line.c_str());
		// end test case 2

		// test case 3: get the line into char buffer
		char buffer[256] = {0};
		tc3 = frd->getLine(buffer);
		printf("The third line: %s\n", buffer);
		tc3 = frd->getLine(buffer);
		printf("The fourth line: %s\n", buffer);
		// end test case 3

		// test case 4: get the buffer into char buffer
		char buf[100] = {0};
		tc4 = frd->getBuffer(buf, 50);
		printf("The buffer with size 50: %s\n", buf);
		tc4 = frd->getBuffer(buf, 30);
		printf("The buffer with size 30: %s\n", buf);
		// end test case 4

		// test case 5: get the buffer into string buffer
		std::string nbuf;
		tc5 = frd->getBuffer(nbuf, 20);
		printf("The std:string buffer with size 20: %s\n", nbuf.c_str());
		tc5 = frd->getBuffer(nbuf, 40);
		printf("The std:string buffer with size 40: %s\n", nbuf.c_str());
		// end test case 5

		// test case 6: close file
		frd->close();
		tc6 = frd->isOpen();
		try {
			std::string line;
			if (tc6) {
				tc6 = frd->getLine(line);
				tc6 = false;
			}
			else {
				printf("Closing file successfully!\n");
				tc6 = true;
			}
		}
		catch (std::exception& ex) {
			tc6 = true;
			printf("Closing file successfully!\n");
		}
		delete frd;
		// end test case 6
	}

	// test case 7: check end-of-file
	IFileReader* reader = FileReaderFactory::getInstance().create(NEW_FILE_TYPE, file1);
	int lineCnt = 0;
	while (!reader->isEOF()) {
		reader->getLine(line);
		lineCnt++;
	}
	if (lineCnt > 444) {
		tc7 = true;
	}
	printf("There is %d line(s) in the file %s\n", lineCnt, file1);
	delete reader;
	// end test case 7

	// test case 8: try to open the bad file
	IFileReader* badReader = FileReaderFactory::getInstance().create(NEW_FILE_TYPE, file2);
	if (badReader->isOpen()) {
		tc8 = false;
	}
	else {
		tc8 = true;
		printf("The file %s does not exist!\n", file2);
	}
	delete badReader;
	// end test case 8
	//assert(tc1 && tc2 && tc3 && tc4 && tc5 && tc6 && tc7 && tc8);
	if (tc1 && tc2 && tc3 && tc4 && tc5 && tc6 && tc7 && tc8) {
		printf("PASSED TEST!!!");
	}
	else {
		printf("FAILED TEST!!!");
	}
	printf("+++ ENDING TEST CFILEREADER +++\n");
}
