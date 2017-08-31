/*
 * AlignedDataParsing.cpp
 *
 *  Created on: Apr 14, 2017
 *      Author: trivv
 */

#include "AlignedDataParsing.h"

#include <string>

#include "../../FileAdapter/FileReaderFactory.h"
#include "../../FileAdapter/IFileReader.h"
#include "../../SharedAlgorithm/logging.h"
#include "../../SharedAlgorithm/SharedAlgorithm.h"

#include "AlignedSentence.h"

AlignedDataParsing::AlignedDataParsing(const char* fileName) {
	FileName = fileName;
	reader = FileReaderFactory::getInstance().create(NEW_FILE_TYPE, FileName.c_str());
}

void AlignedDataParsing::skipHeader() {
	while (!reader->isEOF()) {
		std::string line;
		reader->getLine(line);
		logging::logDebug("[AlignedDataParsing::skipAHeader]: %s\n",line.c_str());
		bool a = SharedAlgorithm::isEmptyLine(line);
		bool b = SharedAlgorithm::startsWith(line, ENDCODING_TAG);
		bool c = SharedAlgorithm::startsWith(line, SRCLANG_TAG);
		bool d = SharedAlgorithm::startsWith(line, TGTLANG_TAG);
		bool e = (!SharedAlgorithm::isEmptyLine(line) &&
				!SharedAlgorithm::startsWith(line, ENDCODING_TAG) &&
				!SharedAlgorithm::startsWith(line, SRCLANG_TAG) &&
				!SharedAlgorithm::startsWith(line, TGTLANG_TAG));
		if (!SharedAlgorithm::isEmptyLine(line) &&
				!SharedAlgorithm::startsWith(line, ENDCODING_TAG) &&
				!SharedAlgorithm::startsWith(line, SRCLANG_TAG) &&
				!SharedAlgorithm::startsWith(line, TGTLANG_TAG)) {
			break;
		}
	}
}

AlignedSentence AlignedDataParsing::getAlignedPair() {
	AlignedSentence result;
	while (!reader->isEOF()) {
		std::string line;
		reader->getLine(line);
		logging::logDebug("[AlignedDataParsing::getAlignedPair]: %s\n",line.c_str());
		if (SharedAlgorithm::isEmptyLine(line)) {
			break;
		}
		if (SharedAlgorithm::startsWith(line, SRCSENT_TAG)) {
			SharedAlgorithm::removeTagName(line, SRCSENT_TAG);
			result.setSrcSent(SharedAlgorithm::parsedSent2Vec(line));
		}
		if (SharedAlgorithm::startsWith(line, TGTSENT_TAG)) {
			SharedAlgorithm::removeTagName(line, TGTSENT_TAG);
			result.setTgtSent(SharedAlgorithm::parsedSent2Vec(line));
		}
		if (SharedAlgorithm::startsWith(line, ALIGNED_TAG)) {
			SharedAlgorithm::removeTagName(line, ALIGNED_TAG);
			std::vector<std::pair<int, int> > align = SharedAlgorithm::parsedAligned2Vec(line);
			result.setAligned(SharedAlgorithm::parsedAligned2Vec(line));
		}
	}
	return result;
}

bool AlignedDataParsing::hasNext() {
	return !reader->isEOF();
}

AlignedDataParsing::~AlignedDataParsing() {
	reader->close();
}
