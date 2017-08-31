/*
 * FileWriterFactory.cpp
 *
 *  Created on: Mar 25, 2017
 *      Author: trivv
 */

#include "FileWriterFactory.h"

#include <cstdio>

#include "CFileWriter.h"
#include "EFileWriter.h"

void FileWriterFactory::Register(const char* fileType,
		CreateFileWriterFn pfnCreate) {
	FactoryMap[fileType] = pfnCreate;
}

IFileWriter* FileWriterFactory::create(const char* fileType,
		const char* fileName, const char *fileMode) {
	return FactoryMap[fileType](fileName, fileMode);
}

FileWriterFactory::~FileWriterFactory() {
	FactoryMap.clear();
	printf("Clear File Writer Factory Map\n");
}

FileWriterFactory::FileWriterFactory() {
	Register(OLD_FILE_TYPE, &CFileWriter::create);
	Register(NEW_FILE_TYPE, &EFileWriter::create);
	Register(OLD_APPD_FILE, &CFileWriter::create);
	Register(NEW_APPD_FILE, &EFileWriter::create);
}
