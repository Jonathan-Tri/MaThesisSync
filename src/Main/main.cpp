/*
 * main.cpp
 *
 *  Created on: Mar 18, 2017
 *      Author: trivv
 */

#include <stdlib.h>
#include <cstdio>
#include <cstring>
#include <string>

#include "../NLP/Alignment/AlignedSentence.h"
#include "../NLP/ParsedTree/ParserTree.h"
#include "../SharedAlgorithm/logging.h"
#include "../SharedAlgorithm/SharedAlgorithm.h"

void initHistoryMsg();

void finalizeHistoryMsg();


void testMain();
/*
extern void testCFileReader();
extern void testEFileReader();
extern void testCFileWriter();
extern void testEFileWriter();
*/
//extern void testParserFileReader1();
//extern void testParserFileReader2();
//extern void testParserFileReader3();
extern void testParsedTree1();
extern AlignedSentence getAlignSentPair();
extern std::string getAParsedTree();
//extern void testAlignParser1();
//extern void testAlignParser2();
extern void testTreeletExt1(ParserTree ptree, AlignedSentence algsent);

void testTreeletExtAlgorithm();

int main() {
	initHistoryMsg();
	testMain();
	/*testCFileReader();
	testEFileReader();
	testCFileWriter();
	testEFileWriter();*/
	//testParserFileReader1();
	//testParserFileReader2();
	//testParserFileReader3();
//	testParsedTree1();

	testTreeletExtAlgorithm();

//	testAlignParser1();
//	testAlignParser2();
	finalizeHistoryMsg();
	return 0;
}


void initHistoryMsg() {

	char *log_fn = (char *) calloc(256, sizeof(char));

	printf("Current date: %s\n", SharedAlgorithm::getCurrDate());
	strcat(log_fn, "./log/");
	strcat(log_fn, SharedAlgorithm::getCurrDate());
	strcat(log_fn, "_messages.log");
	printf("the messages log is %s\n", log_fn);

	logging::createLogger(log_fn);

	logging::setLogLevel(LOG_DEBUG);
}

void finalizeHistoryMsg() {
	logging::finalizeLogging();

}
void testMain() {

	printf("+++++++++ RUNNING TESTING +++++++++!\n");
}

void testTreeletExtAlgorithm() {
	printf("**** TEST THE TREELET EXTRACTION ALGORITHM ****\n");

	std::string parsedTreeContent = getAParsedTree();

	ParserTree ptree(parsedTreeContent);

	AlignedSentence algsent = getAlignSentPair();

	// now we do the treelet extraction algorithm
	testTreeletExt1(ptree, algsent);
}
