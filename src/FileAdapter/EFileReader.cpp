/*
 * EFileReader.cpp
 *
 *  Created on: Mar 20, 2017
 *      Author: trivv
 */

#include "EFileReader.h"

#include <stdlib.h>
#include <cstring>

EFileReader::EFileReader() {
	FileName = NULL;
	Opened = false;
}

EFileReader::EFileReader(const char* fileName) {
	FileName = (char *)calloc(strlen(fileName) + 1, sizeof(char));
	strcpy(FileName, fileName);
	iFile.open(FileName, std::fstream::in);
	if (iFile.is_open()) {
		Opened = true;
	}
	else {
		Opened = false;
	}
}

void EFileReader::open(const char* filename) {
	FileName = (char *)calloc(strlen(filename) + 1, sizeof(char));
	strcpy(FileName, filename);
	iFile.open(FileName, std::fstream::in);
	if (iFile.is_open()) {
		Opened = true;
	}
	else {
		Opened = false;
	}
}

int EFileReader::getLine(std::string& line) {
	if (isEOF()) {
		return 0;
	}
	std::getline(iFile, line);
	return line.length();
}

int EFileReader::getLine(char* line) {
	if (isEOF()) {
		return 0;
	}
	std::string eline;
	getLine(eline);
	memset(line, 0, eline.length());
	strcpy(line, eline.c_str());
	return strlen(line);
}

int EFileReader::getBuffer(std::string& buffer, int bufsize) {
	char buf[bufsize];
	getBuffer(buf, bufsize);
	buffer = buf;
	return buffer.length();
}

int EFileReader::getBuffer(char* buffer, int bufsize) {
	memset(buffer, 0, bufsize);
	iFile.read(buffer, bufsize);
	return strlen(buffer);
}

bool EFileReader::isEOF() {
	return iFile.eof();
}

bool EFileReader::isOpen() {
	return iFile.is_open();
}

void EFileReader::close() {
	if (iFile.is_open()) {
		iFile.close();
	}
}

IFileReader* EFileReader::create(const char* fileName) {
	return new EFileReader(fileName);
}

EFileReader::~EFileReader() {
	// gone out EFileReader
	close();
	printf("gone out from EFileReader\n");
}
