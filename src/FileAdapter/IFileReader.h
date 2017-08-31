/*
 * IFileReader.h
 *
 *  Created on: Jan 3, 2017
 *      Author: trivv
 */

#ifndef SRC_FILEADAPTER_IFILEREADER_H_
#define SRC_FILEADAPTER_IFILEREADER_H_

#include <cstdio>
#include <string>


class IFileReader {
public:

	virtual void open(const char *filename) = 0;

	virtual int getLine(std::string& line) = 0;

	virtual int getLine(char* line) = 0;

	virtual int getBuffer(std::string& buffer, int bufsize) = 0;

	virtual int getBuffer(char* buffer, int bufsize) = 0;

	virtual bool isEOF() = 0;

	virtual bool isOpen() = 0;

	virtual void close() = 0;

	/*
	 * the virtual destructor
	 */
	virtual ~IFileReader() {printf("gone out from IFileReader\n");};
};

typedef IFileReader* (*CreateFileReaderFn)(const char *);
#endif /* SRC_FILEADAPTER_IFILEREADER_H_ */
