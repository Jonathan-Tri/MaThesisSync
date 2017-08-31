/*
 * FileReaderFactory.cpp
 *
 *  Created on: Mar 23, 2017
 *      Author: trivv
 */

#include "FileReaderFactory.h"

#include "CFileReader.h"
#include "EFileReader.h"

FileReaderFactory::FileReaderFactory() {
	Register(OLD_FILE_TYPE, &CFileReader::create);
	Register(NEW_FILE_TYPE, &EFileReader::create);
}

IFileReader* FileReaderFactory::create(const char* fileType,
		const char* fileName) {
	return FactoryMap[fileType](fileName);
}

void FileReaderFactory::Register(const char* fileType,
		CreateFileReaderFn pfnCreate) {
	FactoryMap[fileType] = pfnCreate;
}

FileReaderFactory::~FileReaderFactory() {
	FactoryMap.clear();
}


