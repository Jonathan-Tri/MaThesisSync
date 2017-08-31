/*
 * FileWriterFactory.h
 *
 *  Created on: Mar 25, 2017
 *      Author: trivv
 */

#ifndef SRC_FILEADAPTER_FILEWRITERFACTORY_H_
#define SRC_FILEADAPTER_FILEWRITERFACTORY_H_


#include <map>
#include <string>

#include "IFileWriter.h"
#include "FileType.h"


class FileWriterFactory {
public:

	static FileWriterFactory& getInstance() {
		static FileWriterFactory instance;
		return instance;
	}

	FileWriterFactory& operator=(const FileWriterFactory&) {return *this;}

	void Register(const char *fileType, CreateFileWriterFn pfnCreate);

	IFileWriter* create(const char *fileType, const char *fileName, const char *fileMode = "w");

	~FileWriterFactory();

private:
	FileWriterFactory();
	FileWriterFactory(const FileWriterFactory&) {}
	std::map<std::string, CreateFileWriterFn> FactoryMap;
};


#endif /* SRC_FILEADAPTER_FILEWRITERFACTORY_H_ */
