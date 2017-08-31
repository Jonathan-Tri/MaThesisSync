/*
 * CFileReader.h
 *
 *  Created on: Mar 19, 2017
 *      Author: trivv
 */

#ifndef SRC_FILEADAPTER_CFILEREADER_H_
#define SRC_FILEADAPTER_CFILEREADER_H_

#include <cstdio>
#include <string>

#include "IFileReader.h"

class CFileReader : public IFileReader {
public:
	CFileReader();
	CFileReader(const char *fileName);

	// File reader operator
	virtual void open(const char *filename);

	virtual int getLine(std::string& line);

	virtual int getLine(char* line);

	virtual int getBuffer(std::string& buffer, int bufsize);

	virtual int getBuffer(char* buffer, int bufsize);

	virtual bool isEOF();

	virtual bool isOpen();

	virtual void close();
	// end file reader operator

	// create CFileReader Instace
	static IFileReader* create(const char *fileName);

	virtual ~CFileReader();
private:
	FILE* pFile;
	char* FileName;
	//char* Mode;
	bool Opened;
};

#endif /* SRC_FILEADAPTER_CFILEREADER_H_ */
