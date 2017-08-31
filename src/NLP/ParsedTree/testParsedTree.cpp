/*
 * testParsedTree.cpp
 *
 *  Created on: Apr 9, 2017
 *      Author: trivv
 */

#include <string>

#include "../../SharedAlgorithm/logging.h"
#include "ParserTree.h"
#include "ParserTreeReader.h"


std::string parsedFileTest = "resource/parsed.cmb";

void testParsedTree1() {
	ParserTreeReader parserReader(parsedFileTest);
	parserReader.skipAHeader();

	std::string parsedTree;
	for (int i = 0; i < 5; i++) {
		parsedTree = parserReader.getParsedTree();
		logging::logFatal("[testParserFileReader1]: the parserTree: %s", parsedTree.c_str());
		ParserTree parserTree(parsedTree);
		parserTree.traversal();
	}

//	ParserTree parserTree(parsedTree);
//	parserTree.traversal();
}


