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

AlignedSentence getAlignSentPair() {
	logging::logFatal("***Obtain the alignment sentence***");
	AlignedSentence alignSentPair;
	AlignedDataParsing alignParser(alignFile);
	alignParser.skipHeader();
	int count = 0;
	while (alignParser.hasNext()) {
		alignSentPair = alignParser.getAlignedPair();
		count++;
		alignSentPair.printMe();
		if (count > 0) {
			break;
		}
	}
	return alignSentPair;
}

