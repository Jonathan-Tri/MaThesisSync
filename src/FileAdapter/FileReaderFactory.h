/*
 * FileReaderFactory.h
 *
 *  Created on: Mar 23, 2017
 *      Author: trivv
 */

#ifndef SRC_FILEADAPTER_FILEREADERFACTORY_H_
#define SRC_FILEADAPTER_FILEREADERFACTORY_H_

#include <string>
#include <map>

#include "FileType.h"
#include "IFileReader.h"

class FileReaderFactory {
public:
	static FileReaderFactory& getInstance() {
		static FileReaderFactory INSTANCE;
		return INSTANCE;
	}
	IFileReader* create(const char* fileType, const char *fileName);
	void Register(const char* fileType, CreateFileReaderFn pfnCreate);
	FileReaderFactory &operator=(const FileReaderFactory &) {return *this;}
	~FileReaderFactory();
private:
	FileReaderFactory();
	FileReaderFactory(const FileReaderFactory&) {}
	std::map<std::string, CreateFileReaderFn> FactoryMap;
};



#endif /* SRC_FILEADAPTER_FILEREADERFACTORY_H_ */
