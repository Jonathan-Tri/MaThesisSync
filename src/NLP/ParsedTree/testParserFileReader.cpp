/*
 * testParserFileReader.cpp
 *
 *  Created on: Apr 8, 2017
 *      Author: trivv
 */

#include <string>

#include "../../SharedAlgorithm/logging.h"
#include "ParserTreeReader.h"

std::string parsedFile = "resource/parsed.cmb";

// test how to using a instance of ParserTreeReader
void testParserFileReader1() {
	ParserTreeReader parserReader(parsedFile);
	parserReader.skipAHeader();

	std::string parsedTree;
	for (int i = 0; i < 10; i++) {
		parsedTree = parserReader.getParsedTree();
		logging::logFatal("[testParserFileReader1]: the parserTree: %s", parsedTree.c_str());
	}
}

// test how to using a pointer to ParserTreeReader
void testParserFileReader2() {
	ParserTreeReader *parserReader = new ParserTreeReader(parsedFile);

	parserReader->skipAHeader();

	std::string parsedTree;
	for (int i = 0; i < 10; i++) {
		parsedTree = parserReader->getParsedTree();
		logging::logFatal("[testParserFileReader2]: the parserTree: %s", parsedTree.c_str());
	}
	delete parserReader;
}

void testParserFileReader3() {
	ParserTreeReader parserReader(parsedFile);
	parserReader.skipAHeader();

	std::string parsedTree;
	do {
		parsedTree = parserReader.getParsedTree();
		logging::logFatal("[testParserFileReader3]: the parserTree: %s", parsedTree.c_str());
	} while (parsedTree.size() > 0);
}

