/*
 * ParserTreeReader.cpp
 *
 *  Created on: Apr 8, 2017
 *      Author: trivv
 */

#include "ParserTreeReader.h"

#include <cstdio>

#include "../../FileAdapter/FileReaderFactory.h"
#include "../../FileAdapter/FileType.h"
#include "../../SharedAlgorithm/logging.h"
#include "../../SharedAlgorithm/SharedAlgorithm.h"


ParserTreeReader::ParserTreeReader(const std::string& fileName) {
	FileName = fileName;
	reader = FileReaderFactory::getInstance().create(NEW_FILE_TYPE, FileName.c_str());
}

std::string ParserTreeReader::getParsedTree() {
	std::string result = "";

	while (!reader->isEOF()) {
		std::string line;
		reader->getLine(line);
		logging::logDebug("[ParserTreeReader::getParsedTree]: %s\n",line.c_str());
		if (SharedAlgorithm::isEndOfTextToken(line)) {
			reader->getLine(line);
			logging::logDebug("[ParserTreeReader::getParsedTree]: %s\n",line.c_str());
			if (SharedAlgorithm::isEndOfTextToken(line)) {
				// reaching end of parsed tree
				break;
			}
			else {
				SharedAlgorithm::trimAll(line);
				result += line;
			}
		}
		else {
			SharedAlgorithm::trimAll(line);
			result += line;
		}
	}

	return result;
}

void ParserTreeReader::skipAHeader() {
	while (!reader->isEOF()) {
		std::string line;
		reader->getLine(line);
		logging::logDebug("[ParserTreeReader::skipAHeader]: %s\n",line.c_str());
		if (SharedAlgorithm::isEmptyLine(line) && !SharedAlgorithm::startsWith(line, HEADER_TOKEN)) {
			break;
		}
	}
}

ParserTreeReader::~ParserTreeReader() {
	reader->close();
	printf("Cleaned the ParserTreeReader!\n");
}
