/*
 * CFileReader.cpp
 *
 *  Created on: Mar 19, 2017
 *      Author: trivv
 */

#include "CFileReader.h"

#include <stddef.h>
#include <stdlib.h>
#include <cstring>

CFileReader::CFileReader() {
	pFile = NULL;
	FileName = NULL;
	Opened = false;
}

CFileReader::CFileReader(const char* fileName) {
	FileName = (char *) calloc(strlen(fileName) + 1, sizeof(char));
	strcpy(FileName, fileName);
	pFile = fopen(FileName, "r");
	if (pFile) {
		Opened = true;
	}
	else {
		Opened = false;
	}
}

void CFileReader::open(const char* filename) {
	FileName = (char *) calloc(strlen(filename) + 1, sizeof(char));
	strcpy(FileName, filename);
	pFile = fopen(FileName, "r");
	if (pFile) {
		Opened = true;
	}
	else {
		Opened = false;
	}
}

int CFileReader::getLine(std::string& line) {
	char* cline = NULL;
	size_t len = 0;
	if (isEOF()) {
		return len;
	}
	getline(&cline, &len, pFile);
	line = cline;
	return len;
}

int CFileReader::getLine(char* line) {
	size_t len = 0;
	if (isEOF()) {
		return len;
	}
	getline(&line, &len, pFile);
	return len;
}

int CFileReader::getBuffer(std::string& buffer, int bufsize) {
	if (isEOF()) {
		return 0;
	}
	char buf[bufsize];
	fgets(buf, bufsize, pFile);
	buffer = buf;
	return buffer.length();
}

int CFileReader::getBuffer(char* buffer, int bufsize) {
	if (isEOF()) {
		return 0;
	}
	memset(buffer, 0, bufsize);
	fgets(buffer, bufsize, pFile);
	return strlen(buffer);
}

bool CFileReader::isEOF() {
	return feof(pFile);
}

bool CFileReader::isOpen() {
	return Opened;
}

void CFileReader::close() {
	if (Opened) {
		fclose(pFile);
	}
	Opened = false;
}

IFileReader* CFileReader::create(const char* fileName) {
	return new CFileReader(fileName);
}

CFileReader::~CFileReader() {
	// gone out CFileReader
	close();
	printf("gone out from CFileReader\n");
}
