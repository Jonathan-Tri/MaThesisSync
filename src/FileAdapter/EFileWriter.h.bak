/*
 * EFileWriter.h
 *
 *  Created on: Mar 25, 2017
 *      Author: trivv
 */

#ifndef SRC_FILEADAPTER_EFILEWRITER_H_
#define SRC_FILEADAPTER_EFILEWRITER_H_

#include <fstream>
#include <string>

#include "IFileWriter.h"


class EFileWriter : public IFileWriter {
public:

	EFileWriter();

	EFileWriter(const char *fileName, const char *fileMode = "w");

	virtual void open(const char *fileName, const char *fileMode = "w");

	virtual void writeLine(char *line);

	virtual void writeLine(std::string line);

	virtual void write(char *buf);

	virtual void write(std::string buf);

	virtual bool isOpen();

	virtual void close();

	// The creator
	static IFileWriter* create(const char* fileName);
	static IFileWriter* create(const char* fileName, const char *fileMode);

	virtual ~EFileWriter();

private:
	char *FileName;
	std::ofstream oFile;
	bool Opened;
};


#endif /* SRC_FILEADAPTER_EFILEWRITER_H_ */
