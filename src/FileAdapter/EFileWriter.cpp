/*
 * EFileWriter.cpp
 *
 *  Created on: Mar 25, 2017
 *      Author: trivv
 */

#include "EFileWriter.h"

#include <stdlib.h>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <string>

EFileWriter::EFileWriter() {
	FileName = NULL;
	Opened = false;
}

EFileWriter::EFileWriter(const char* fileName, const char* fileMode) {
	FileName = (char *) calloc(strlen(fileName) + 1, sizeof(char));
	strcpy(FileName, fileName);
	if (strcmp(fileMode, "w+") == 0 || strcmp(fileMode, "a") == 0) {
		oFile.open(FileName, std::fstream::out | std::fstream::app);
	}
	else {
		oFile.open(FileName, std::fstream::out);
	}
	if (oFile.is_open()) {
		Opened = true;
	}
	else {
		Opened = false;
	}
}

void EFileWriter::open(const char* fileName, const char* fileMode) {
	FileName = (char *) calloc(strlen(fileName) + 1, sizeof(char));
	strcpy(FileName, fileName);
	if (strcmp(fileMode, "w+") == 0 || strcmp(fileMode, "a") == 0) {
		oFile.open(FileName, std::fstream::out | std::fstream::app);
	}
	else {
		oFile.open(FileName, std::fstream::out);
	}
	if (oFile.is_open()) {
		Opened = true;
	}
	else {
		Opened = false;
	}
}

void EFileWriter::writeLine(char* line) {
	oFile << line << std::endl;
}

void EFileWriter::writeLine(std::string line) {
	oFile << line << std::endl;
}

void EFileWriter::write(char* buf) {
	oFile << buf;
}

void EFileWriter::write(std::string buf) {
	oFile << buf;
}

bool EFileWriter::isOpen() {
	return Opened;
}

void EFileWriter::close() {
	if (Opened) {
		oFile.flush();
		oFile.close();
	}
	Opened = false;
}

IFileWriter* EFileWriter::create(const char* fileName) {
	return new EFileWriter(fileName);
}

IFileWriter* EFileWriter::create(const char* fileName, const char *fileMode) {
	return new EFileWriter(fileName, fileMode);
}

EFileWriter::~EFileWriter() {
	close();
	printf("Gone out from EFileWriter\n");
}
