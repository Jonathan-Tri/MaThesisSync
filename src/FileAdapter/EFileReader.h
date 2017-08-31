/*
 * EFileReader.h
 *
 *  Created on: Mar 19, 2017
 *      Author: trivv
 */

#ifndef SRC_FILEADAPTER_EFILEREADER_H_
#define SRC_FILEADAPTER_EFILEREADER_H_

#include <fstream>
#include <string>

#include "IFileReader.h"

class EFileReader : public IFileReader {
public:
	EFileReader();
	EFileReader(const char *fileName);

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

	// create a instance
	static IFileReader* create(const char *fileName);

	virtual ~EFileReader();

private:
	std::ifstream iFile;
	char* FileName;
	bool Opened;
};



#endif /* SRC_FILEADAPTER_EFILEREADER_H_ */
