/*
 * ParserTreeReader.h
 *
 *  Created on: Apr 8, 2017
 *      Author: trivv
 */

#ifndef SRC_NLP_PARSEDTREE_PARSERTREEREADER_H_
#define SRC_NLP_PARSEDTREE_PARSERTREEREADER_H_

#include <string>

#include "../../FileAdapter/IFileReader.h"


class ParserTreeReader {
public:
	ParserTreeReader(const std::string& fileName);

	void skipAHeader();

	std::string getParsedTree();

	~ParserTreeReader();

private:
	IFileReader *reader;
	std::string FileName;
};


#endif /* SRC_NLP_PARSEDTREE_PARSERTREEREADER_H_ */
