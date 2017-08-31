/*
 * IFileWriter.h
 *
 *  Created on: Mar 25, 2017
 *      Author: trivv
 */

#ifndef SRC_FILEADAPTER_IFILEWRITER_H_
#define SRC_FILEADAPTER_IFILEWRITER_H_

#include <cstdio>
#include <string>


class IFileWriter {
public:

	virtual void open(const char *fileName, const char *fileMode = "w") = 0;

	virtual void writeLine(char *line) = 0;

	virtual void writeLine(std::string line) = 0;

	virtual void write(char *buf) = 0;

	virtual void write(std::string buf) = 0;

	virtual bool isOpen() = 0;

	virtual void close() = 0;

	virtual ~IFileWriter() {
		printf("gone out from IFileWriter\n");
	}
};

typedef IFileWriter* (*CreateFileWriterFn)(const char*, const char*);
#endif /* SRC_FILEADAPTER_IFILEWRITER_H_ */
