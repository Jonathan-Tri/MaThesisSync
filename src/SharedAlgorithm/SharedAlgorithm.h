/*
 * SharedAlgorithm.h
 *
 *  Created on: Aug 13, 2016
 *      Author: trivv
 */

#ifndef SHAREDALGORITHM_SHAREDALGORITHM_H_
#define SHAREDALGORITHM_SHAREDALGORITHM_H_

#include <stdarg.h>
#include <string>
#include <utility>
#include <vector>

#define END_OF_TEXT_UNIT	"( END_OF_TEXT_UNIT )"
#define BEGIN_UNIT_TOKEN	"("
#define END_UNIT_TOKEN 		")"
#define BEGIN_OF_SENTENCE	"( "
#define END_OF_SENTENCE		"(. .) )"
#define HEADER_TOKEN		"*x*"
#define LEVEL_BLOCK			"    "

// Aligned File Header
#define ENDCODING_TAG		"encoding:"
#define SRCLANG_TAG			"srclang:"
#define TGTLANG_TAG			"tgtlang:"

// Aligned File block tag name
#define NEWPAIR_TAG			"newpair"
#define SRCSENT_TAG			"srcsent:"
#define TGTSENT_TAG			"tgtsent:"
#define ALIGNED_TAG			"aligned:"
#define CONTEXT_TAG			"context:"
#define	COMMENT_TAG			"comment:"


class SharedAlgorithm {
public:

	/*
	 * String builder
	 */
	static std::string StringBuilder(const char *format, ...);
	static std::string StringBuilder(const char *format, va_list argList);

	/*
	 * get current date
	 */
	static char *getCurrDate();

	/*
	 * get current time into string
	 */
	static char *getCurrTime();

	/*
	 * correct directory path
	 */
	static char *correctDirectoryPath(char *path);

	/*
	 * check a input string whether is the END_OF_TEXT_UNIT token
	 */
	static bool isEndOfTextToken(char* str);
	static bool isEndOfTextToken(const std::string& str);

	/*
	 * check a input string whether is the begin of unit token
	 */
	static bool isBeginOfUnitToken(char* str);

	/*
	 * check a input string whether is a end of unit token
	 */
	static bool isEndOfUnitToken(char* str);

	/*
	 * check a input string whether is a end of sentence
	 */
	static bool isEndOfSentenceToken(char* str);

	/*
	 * split a string to some substrings by a token
	 */
	static int splitByToken(char* str, const char* token, char** substrs);

	/*
	 * remove all redundant spaces on the left of editable string
	 */
	static void trimLeft(char* str);
	static void trimLeft(std::string& str);

	/*
	 * remove all redundant spaces on the left of non-editable string
	 */
	static void trimLeft(char* str, char* result);

	/*
	 * remove all redundant spaces on the right of string
	 */
	static void trimRight(char* str);
	static void trimRight(std::string& str);

	/*
	 * remove all redundant spaces on both sides of string
	 */
	static void trimAll(char* str);
	static void trimAll(std::string& str);

	/*
	 * check whether a string starts with a substring
	 */
	static bool startsWith(char* str, const char* substr);
	static bool startsWith(const std::string& str, const char* substr);

	/*
	 * compress a parsed tree
	 */
	static int compressParsedTree(char* ptree, char* compressTree);

	/*
	 * check whether it is a text file
	 */
	static bool isTextFile(char *fileName);

	/*
	 * get the file name without extension
	 */
	static char *getFileName(char *filePath);

	/*
	 * get the path of file name
	 */
	static char *getPath(char *filePath);

	/*
	 * remove special character
	 */
	static void removeSpecialChar(char *str);

	/*
	 * convert from char array to std::string
	 */
	static std::string toString(char *str);

	/*
	 * convert from const char array to std::string
	 */
	static std::string toString(const char *str);

	/*
	 * convert from std::string to char array
	 */
	static const char *toCharArr(std::string str);

	/*
	 * get a word that cover the current char
	 */
	static void getThisWord(char *charPointer, char *result, char *startBuf, char *endBuf);

	/*
	 * check a line whether contain data (don't consider space character, special character)
	 */
	static bool isEmptyLine(const std::string& line);

	/*
	 * remove a decoration at the beginning and at the end of compress tree if there is
	 */
	static void removeTreeDecoration(std::string& compressTree);

	/*
	 * get node content information from the compress text
	 */
	static std::string getContentInfo(std::string& compressText);

	/*
	 * parsed the given sentence into a vector of words
	 */
	static std::vector<std::string> parsedSent2Vec(std::string sentence);

	/*
	 * parsed aligned string into vector of int-pair
	 */
	static std::vector<std::pair<int, int> > parsedAligned2Vec(std::string line);

	/*
	 * remove the tag name from given line
	 */
	static void removeTagName(std::string& line, std::string tagName);
};



#endif /* SHAREDALGORITHM_SHAREDALGORITHM_H_ */
