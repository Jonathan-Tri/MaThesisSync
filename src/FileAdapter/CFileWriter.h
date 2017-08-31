/*
 * CFileWriter.h
 *
 *  Created on: Mar 25, 2017
 *      Author: trivv
 */

#ifndef SRC_FILEADAPTER_CFILEWRITER_H_
#define SRC_FILEADAPTER_CFILEWRITER_H_

#include <cstdio>
#include <string>

#include "IFileWriter.h"

class CFileWriter : public IFileWriter {
public:

	CFileWriter();

	CFileWriter(const char *fileName, const char *fileMode = "w");

	// File writer operators
	virtual void open(const char *fileName, const char *fileMode = "w");

	virtual void writeLine(char *line);

	virtual void writeLine(std::string line);

	virtual void write(char *buf);

	virtual void write(std::string buf);

	virtual bool isOpen();

	virtual void close();
	// End file writer operators

	// The creator
	static IFileWriter* create(const char *fileName);
	static IFileWriter* create(const char *fileName, const char *fileMode);

	virtual ~CFileWriter();

private:
	char* FileName;
	FILE* pFile;
	bool Opened;
};



#endif /* SRC_FILEADAPTER_CFILEWRITER_H_ */
