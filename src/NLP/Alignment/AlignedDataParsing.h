/*
 * AligedDataParsing.h
 *
 *  Created on: Apr 14, 2017
 *      Author: trivv
 */

#ifndef SRC_NLP_ALIGNMENT_ALIGNEDDATAPARSING_H_
#define SRC_NLP_ALIGNMENT_ALIGNEDDATAPARSING_H_

#include <string>

#include "../../FileAdapter/IFileReader.h"
#include "AlignedSentence.h"


class AlignedDataParsing {
public:
	AlignedDataParsing(const char *fileName);
	void skipHeader();
	AlignedSentence getAlignedPair();
	bool hasNext();
	~AlignedDataParsing();
private:
	IFileReader *reader;
	std::string FileName;

};


#endif /* SRC_NLP_ALIGNMENT_ALIGNEDDATAPARSING_H_ */
