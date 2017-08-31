/*
 * testFileWriter.cpp
 *
 *  Created on: Mar 25, 2017
 *      Author: trivv
 */

#include "CFileWriter.h"
#include "EFileWriter.h"
#include "FileWriterFactory.h"

const char *ofile1 = "test01.txt";
const char *ofile2 = "test02.txt";

void testCFileWriter() {
	printf("+++ STARTING TEST CFILEWRITER +++\n");
	IFileWriter* writer = FileWriterFactory::getInstance().create(OLD_FILE_TYPE, ofile1);

	bool tc1, tc2;
	tc1 = writer->isOpen();
	if (tc1) {
		std::string line = "The first line!";
		writer->writeLine(line);
		char cline[100] = "The second line!";
		writer->writeLine(cline);
		const char *cbuf1 = "This is ";
		const char *cbuf2 = " a example for c-buffer!\n";
		writer->write(cbuf1);
		writer->write(cbuf2);
		std::string nbuf = "This is a example ";
		std::string nbuf2 = "for c++-buffer";
		writer->write(nbuf);
		writer->write(nbuf2);
	}
	writer->close();
	tc2 = !writer->isOpen();
	delete writer;

	if (tc1 && tc2) {
		printf("PASSED TEST!!!\n");
	}
	else {
		printf("FAILED TEST!!!\n");
	}
	printf("----ENDING TEST----\n");
}

void testEFileWriter() {
	printf("+++ STARTING TEST EFILEWRITER +++\n");
	IFileWriter* writer = FileWriterFactory::getInstance().create(NEW_FILE_TYPE, ofile2);

	bool tc1, tc2;
	tc1 = writer->isOpen();
	if (tc1) {
		std::string line = "The first line!";
		writer->writeLine(line);
		char cline[100] = "The second line!";
		writer->writeLine(cline);
		const char *cbuf1 = "This is ";
		const char *cbuf2 = " a example for c-buffer!\n";
		writer->write(cbuf1);
		writer->write(cbuf2);
		std::string nbuf = "This is a example ";
		std::string nbuf2 = "for c++-buffer";
		writer->write(nbuf);
		writer->write(nbuf2);
	}
	writer->close();
	tc2 = !writer->isOpen();
	delete writer;
	if (tc1 && tc2) {
		printf("PASSED TEST!!!\n");
	}
	else {
		printf("FAILED TEST!!!\n");
	}
	printf("----ENDING TEST----\n");
}

