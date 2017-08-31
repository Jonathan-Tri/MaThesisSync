/*
 * testAlignmetParser.cpp
 *
 *  Created on: May 18, 2017
 *      Author: trivv
 */

#include "../../SharedAlgorithm/logging.h"
#include "AlignedDataParsing.h"
#include "AlignedSentence.h"


const char* alignFile = "align.txt";


void testAlignParser1() {
	AlignedDataParsing alignParser(alignFile);

	logging::logFatal("[testAlignParser1] skip the header of aligned file");
	alignParser.skipHeader();

	logging::logFatal("try to get 2 aligned sentence pairs:");
	int count = 0;
	while (alignParser.hasNext()) {
		AlignedSentence alignSentPair = alignParser.getAlignedPair();
		count++;
		alignSentPair.printMe();
	}

	logging::logFatal("There are %d aligned sentences pairs in %s", count, alignFile);
	//alignParser.~AlignedDataParsing();
}

void testAlignParser2() {
	logging::logFatal("We are define testAlignParser2 after");
}

