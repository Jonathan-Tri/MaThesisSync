/*
 * CFileWriter.cpp
 *
 *  Created on: Mar 25, 2017
 *      Author: trivv
 */

#include "CFileWriter.h"

#include <stdlib.h>
#include <cstring>

CFileWriter::CFileWriter() {
	pFile = NULL;
	FileName = NULL;
	Opened = false;
}

CFileWriter::CFileWriter(const char* fileName, const char *fileMode) {
	FileName = (char *) calloc(strlen(fileName) + 1, sizeof(char));
	strcpy(FileName, fileName);
	pFile = fopen(FileName, fileMode);
	if (pFile) {
		Opened = true;
	}
	else {
		Opened = false;
	}
}

void CFileWriter::open(const char* fileName, const char *fileMode) {
	FileName = (char *) calloc(strlen(fileName) + 1, sizeof(char));
	strcpy(FileName, fileName);
	pFile = fopen(FileName, fileMode);
	if (pFile) {
		Opened = true;
	}
	else {
		Opened = false;
	}
}

void CFileWriter::writeLine(char* line) {
	fprintf(pFile, "%s\n", line);
}

void CFileWriter::writeLine(std::string line) {
	fprintf(pFile, "%s\n", line.c_str());
}

void CFileWriter::write(char* buf) {
	fputs(buf, pFile);
}

void CFileWriter::write(std::string buf) {
	fputs(buf.c_str(), pFile);
}

bool CFileWriter::isOpen() {
	return Opened;
}

void CFileWriter::close() {
	if (Opened) {
		fclose(pFile);
	}
	Opened = false;
}

IFileWriter* CFileWriter::create(const char* fileName) {
	return new CFileWriter(fileName);
}

IFileWriter* CFileWriter::create(const char* fileName, const char* fileMode) {
	return new CFileWriter(fileName, fileMode);
}

CFileWriter::~CFileWriter() {
	close();
	printf("Gone out from CFileWriter\n");
}
