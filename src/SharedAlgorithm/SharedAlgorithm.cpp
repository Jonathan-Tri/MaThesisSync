/*
 * SharedAlgorithm.cpp
 *
 *  Created on: Aug 13, 2016
 *      Author: trivv
 */

#include "SharedAlgorithm.h"

#include <stdlib.h>
#include <string.h>
#include <cctype>
#include <cstddef>
#include <cstdio>
#include <ctime>
#include <tr1/regex>


bool SharedAlgorithm::isEndOfTextToken(char* str) {
	if (strcmp(str, END_OF_TEXT_UNIT) == 0) {
		return true;
	}
	return false;
}

bool SharedAlgorithm::isEndOfTextToken(const std::string& str) {
	return str == END_OF_TEXT_UNIT;
}

bool SharedAlgorithm::isBeginOfUnitToken(char*str) {
	if (strcmp(str, BEGIN_UNIT_TOKEN) == 0) {
		return true;
	}
	return false;
}

bool SharedAlgorithm::isEndOfUnitToken(char* str) {
	if (strcmp(str, END_UNIT_TOKEN) == 0) {
		return true;
	}
	return false;
}

bool SharedAlgorithm::isEndOfSentenceToken(char* str) {
	if (strcmp(str, END_OF_SENTENCE) == 0) {
		return true;
	}

	return false;
}

int SharedAlgorithm::splitByToken(char* str, const char* token, char** substrs) {
	substrs = (char**) malloc(10 * sizeof(char*));
	int splitCount = 0;
	char* tokenize = strtok(str, token);
	while (tokenize != NULL) {
		splitCount++;
		substrs[splitCount - 1] = (char*)malloc(sizeof(char) * strlen(tokenize));
		strcpy(substrs[splitCount - 1], tokenize);
		// debug
		printf("[SharedAlgorithm][splitByToken]: tokenize %d = %s\n", splitCount, tokenize);
		tokenize = strtok(NULL, token);
	}
	return splitCount;
}

void SharedAlgorithm::trimLeft(char* str) {
	if (str == NULL) {
		return;
	}

	while(isspace((unsigned char)*str)) str++;

}

void SharedAlgorithm::trimRight(char* str) {
	if (str == NULL) {
		return;
	}
	char* pointer = str + strlen(str) - 1;
	while (pointer > str && isspace((unsigned char)*pointer)) {
		*pointer-- = 0;
	}
}

void SharedAlgorithm::trimAll(char* str) {
	trimLeft(str);
	trimRight(str);
}

bool SharedAlgorithm::startsWith(char* str, const char* substr) {
	if (str == NULL || substr == NULL) {
		return false;
	}
	if (strncmp(str, substr, strlen(substr)) == 0) {
		return true;
	}
	else {
		return false;
	}
}

bool SharedAlgorithm::startsWith(const std::string& str, const char* substr) {
	if (str.size() == 0 || strlen(substr) == 0) {
		return false;
	}
	return str.find(substr) == 0;
}

void SharedAlgorithm::trimLeft(char* str, char* result) {
	if (str == NULL) {
		return;
	}
	//*result = '\0';
	//memset(result, 0, sizeof(result));
	char* pointer = str;
	//printf("[SharedAlgorithm][trimLeft]: str = %s - %d\n", str, strlen(str));
	while (*pointer == ' '  && *pointer != '\0') {
		pointer++;
	}
	memcpy(result, pointer, strlen(pointer));
	*(result + strlen(pointer)) = '\0';
	//printf("[SharedAlgorithm][trimLeft]: result = %s - %d\n", result, strlen(result));
}

int SharedAlgorithm::compressParsedTree(char* ptree, char* compressTree) {
	char* result = (char*) malloc(10000 * sizeof(char));
	*result = '\0';
	strcpy(compressTree, ptree);
	char* token = strtok(compressTree, "\n");
	char* span = (char*) malloc(256 * sizeof(char));
	int cntToken = 0;
	while (token != NULL) {
		// debug
		//printf("[SharedAlgorithm][compressParsedTree] - token: %s\n", token);
		//strcpy(span, trimLeft(token));
		trimLeft(token, span);
		// debug
		printf("[SharedAlgorithm][compressParsedTree] - trimAll: %s\n", span);
		if (!isEndOfSentenceToken(span)) {
			strcat(result, span);
			//printf("token: %s\n", token);
			printf("result: %s\n", result);
			cntToken++;
		}
		token = strtok(NULL, "\n");
	}
	//*compressTree = '\0';
	strcpy(compressTree, result);
	free(result);
	return cntToken;
}

bool SharedAlgorithm::isTextFile(char* fileName) {
	char *extName = strstr(fileName, ".txt");
	if (extName !=0 && (extName - fileName) == (strlen(fileName) - 4)) {
		return true;
	}
	return false;
}

char* SharedAlgorithm::getFileName(char* filePath) {
	char *extName = strstr(filePath, ".txt");
	char *nameStarts = extName;
	while (nameStarts != filePath && *nameStarts != '/') {
		if (*nameStarts == '/' || nameStarts == filePath) {
			break;
		}
		nameStarts--;
	}
	if (*nameStarts == '/') {
		nameStarts++;
	}
	int len = extName - nameStarts;
	char *res = (char *) calloc(len, sizeof(char));
	strncpy(res, nameStarts, len);
	return res;
}

void SharedAlgorithm::removeSpecialChar(char* str) {
	int len = strlen(str);
	for (int i = len - 1; i >= 0; i--) {
		if (!(str[i] == '\n' || str[i] == '\r' || str[i] == '\t')) {
			memset(str + i + 1, 0, len - (i + 1));
			break;
		}
		if (i == 0 && (str[i] == '\n' || str[i] == '\r' || str[i] == '\t')) {
			memset(str, 0, len);
		}
	}
}

std::string SharedAlgorithm::toString(char* str) {
	return std::string(str);
}

const char *SharedAlgorithm::toCharArr(std::string str) {
	return str.c_str();
}

char* SharedAlgorithm::getCurrTime() {
	time_t rawtime;
	struct tm * timeinfo;
	char tmp[5];
	char *res = (char *)calloc(15, sizeof(char));
	time (&rawtime);
	timeinfo = localtime(&rawtime);
	sprintf(tmp, "%d", timeinfo->tm_hour);
	strcat(res, tmp);
	sprintf(tmp, ":%d", timeinfo->tm_min);
	strcat(res, tmp);
	sprintf(tmp, ":%d", timeinfo->tm_sec);
	strcat(res, tmp);
	return res;
}

char* SharedAlgorithm::correctDirectoryPath(char* path) {
	char *res = (char *) calloc(256, sizeof(char));
	int len = strlen(path);

	if ((path[0] == '.' && path[1] == '/') || path[0] == '/') {
		if (path[len-1] == '/') {
			sprintf(res, "%s", path);
		}
		else {
			sprintf(res, "%s/", path);
		}

	} else {
		if (path[0] == '/') {
			sprintf(res, "./%s", path);
		}
		else {
			sprintf(res, "./%s/", path);
		}
	}

	return res;
}

void SharedAlgorithm::getThisWord(char* charPointer, char * result, char *startBuf, char *endBuf) {
	if (*charPointer == ' ' || charPointer == 0) {
		return;
	}
	char *left = charPointer;
	char *right = left;
	while (left > startBuf  && *(left - 1) != ' ' && *(left - 1) != '('
			&& *(left - 1) != '"' && *(left - 1) != '\r' && *(left - 1) != '\n') {
			//&& *(left - 1) != '/' && *(left - 1) != '.') {
		left--;
		if (charPointer - left >= 15) {
			break;
		}
	}
	while (right < endBuf && *(right + 1) != ' ' && *(right + 1) != '('
			&& *(right + 1) != '"' && *(right + 1) != '\r' && *(right + 1) != '\n'
			&& *(right + 1) != '.') {
		right++;
		if (right - charPointer >= 5) {
			break;
		}
	}
	int len = (right - left + 1);
	strncpy(result, left, len);
}

char* SharedAlgorithm::getCurrDate() {
	time_t rawtime;
	struct tm * timeinfo;
	char tmp[5];
	char *res = (char *)calloc(20, sizeof(char));
	//char *res2 = (char *)calloc(30, sizeof(char));
	time (&rawtime);
	timeinfo = localtime(&rawtime);

	//itoa(timeinfo->tm_year, tmp, 10);
	sprintf(tmp, "%d-", timeinfo->tm_year + 1900);
	strcat(res, tmp);
	//itoa(timeinfo->tm_mon, tmp, 10);
	sprintf(tmp, "%d-", timeinfo->tm_mon + 1);
	strcat(res, tmp);
	//itoa(timeinfo->tm_mday, tmp, 10);
	if (timeinfo->tm_mday < 10) {
		sprintf(tmp, "0%d", timeinfo->tm_mday);
	}
	else {
		sprintf(tmp, "%d", timeinfo->tm_mday);
	}
	strcat(res, tmp);
//	sprintf(tmp, "_%d", timeinfo->tm_hour);
//	strcat(res, tmp);
//	sprintf(tmp, ":%d", timeinfo->tm_min);
//	strcat(res, tmp);
//	sprintf(tmp, ":%d", timeinfo->tm_sec);
//	strcat(res, tmp);
	//strftime(res2, 30 ,"%Y-%m-%d_I:%M:%S",timeinfo);

	return res;
}

char* SharedAlgorithm::getPath(char* filePath) {
	char *endOfPath = filePath + strlen(filePath) - 1;
	while (endOfPath != filePath && *endOfPath != '/' ) {
		endOfPath--;
	}
	if (endOfPath == filePath) {
		char *res = (char *) calloc(3, sizeof(char));
		strcpy(res, "./");
		return res;
	}
	else {
		char *res = (char *) calloc(endOfPath - filePath + 2, sizeof(char));
		memcpy(res, filePath, endOfPath - filePath);
		return SharedAlgorithm::correctDirectoryPath(res);
	}
}

std::string SharedAlgorithm::toString(const char* str) {
	return std::string(str);
}

std::string SharedAlgorithm::StringBuilder(const char* format, ...) {
	std::string result = "";
	std::string sformat = format;
	int start = 0, index = sformat.find("%", start), len = sformat.length();

	va_list argList;
	va_start(argList, format);
//	while (*format) {
//		switch (*format++) {
//		case 's':
//			result += va_arg(argList, char *);
//			break;
//		case 'i':
//		case 'u':
//		case 'd':
//			result += va_arg(argList, int);
//			break;
//		case 'c':
//			result += va_arg(argList, char);
//		}
//	}
	va_end(argList);
	while (index > 0) {
		if (start < index) {
			result += sformat.substr(start, index - start);
		}
		switch (sformat[index + 1]) {
		case 's':
			result += va_arg(argList, char *);
			break;
		case 'i':
		case 'u':
		case 'd':
			result += va_arg(argList, int);
			break;
		case 'c':
			result += va_arg(argList, int);
		}
		start = index + 2;
		index = sformat.find("%", start);
	}
	if (start < len) {
		result += sformat.substr(start, len - start);
	}

	return result;

	return result;
}

std::string SharedAlgorithm::StringBuilder(const char* format,
		va_list argList) {
	std::string result = "";
	std::string sformat = format;
	int start = 0, index = sformat.find("%", start), len = sformat.length();

	while (index > 0) {
		if (start < index) {
			result += sformat.substr(start, index - start);
		}
		switch (sformat[index + 1]) {
		case 's':
			result += va_arg(argList, char *);
			break;
		case 'i':
		case 'u':
		case 'd':
			result += va_arg(argList, int);
			break;
		case 'c':
			result += va_arg(argList, int);
		}
		start = index + 2;
		index = sformat.find("%", start);
	}
	if (start < len) {
		result += sformat.substr(start, len - start);
	}

	return result;
}

void SharedAlgorithm::trimLeft(std::string& str) {
	while (str[0] == ' ' || str[0] == '\n' || str[0] == '\r' || str[0] == '\t') {
		str.erase(0, 1);
	}
}

void SharedAlgorithm::trimRight(std::string& str) {
	while (str[str.size() - 1] == ' ' || str[str.size() - 1] == '\n' ||
			str[str.size() - 1] == '\r' || str[str.size() - 1] == '\t') {
		str.erase(str.size() - 1, 1);
	}
}

void SharedAlgorithm::trimAll(std::string& str) {
	trimLeft(str);
	trimRight(str);
}

bool SharedAlgorithm::isEmptyLine(const std::string& line) {
	int len = line.length();
	if (len == 0) {
		return true;
	}
	int i = len - 1;
	for (; i >= 0; i--) {
		if (!(line[i] == '\n' || line[i] == '\r' || line[i] == '\t' || line[i] == ' ')) {
			break;
		}
	}
	return i < 0;
}

void SharedAlgorithm::removeTreeDecoration(std::string& compressTree) {
	// remove the decoration/signal at the beginning of sentence
	if (compressTree.find(BEGIN_OF_SENTENCE) == 0) {
		compressTree.erase(0, 2);
	}

	// remove the decoration/signal at the end of sentence
	int index = compressTree.find(END_OF_SENTENCE);
	if (index > 0) {
		compressTree.erase(index, strlen(END_OF_SENTENCE));
	}
}

std::string SharedAlgorithm::getContentInfo(std::string& compressText) {
	std::string result = "";

	if (compressText[0] != '(') {
		return result;
	}

	int index = compressText.find_first_of("()", 1);
	result = compressText.substr(1, index - 1);
	// remove gotten content from tree
	compressText.erase(0, index);
	trimRight(compressText);
	compressText.erase(compressText.size() - 1, 1);
	trimAll(result);
	return result;
}

std::vector<std::string> SharedAlgorithm::parsedSent2Vec(
		std::string sentence) {
	std::vector<std::string> result;

	trimAll(sentence);
	int prevPos = 0, pos = 0;
	while (pos < sentence.size() && prevPos < sentence.size()) {
		pos = sentence.find(" ", prevPos);
		if (pos == std::string::npos) {
			pos = sentence.size();
		}
		std::string word = sentence.substr(prevPos, pos - prevPos);
		if (!word.empty()) {
			result.push_back(word);
		}
		prevPos = pos + 1;
	}

	return result;
}

std::pair<int, int> getPairIndex(std::string& line, int pos) {
	std::pair<int, int> res;
	int left = line.find('(', 0);
	int right = line.find(')', 0);
	std::string snum = line.substr(left + 1, pos - 1);
	std::string tnum = line.substr(pos + 1, right - pos -1);
	res.first = atoi(snum.c_str());
	res.second = atoi(tnum.c_str());
	right = (line.length() >= right + 2) ? right + 2 : line.length();
	line.erase(0, right);
	return res;
}

std::vector<std::pair<int, int> > SharedAlgorithm::parsedAligned2Vec(
		std::string line) {
	std::vector<std::pair<int, int> > result;

	//std::tr1::regex Pattern;//("([0-9]+,[0-9]+)");
	// will improve this function by using the regular expression

	int first = -1, last = -1, pos = -1;
	if ((first = line.find("((", 0)) >= 0) {
		line.erase(0, first + 1);
	}
	if ((last = line.find("))", 0)) >= 0) {
		line.erase(last + 1, line.length() - last - 1);
	}
	while ((pos = line.find(",", 0)) != std::string::npos) {
		std::pair<int, int> pair_of_index = getPairIndex(line, pos);
		result.push_back(pair_of_index);
	}

	return result;
}

void SharedAlgorithm::removeTagName(std::string& line, std::string tagName) {
	int removeSize = tagName.length();
	int removePos = line.find(tagName);
	if (removePos < 0) {
		return;
	}
	line.erase(removePos, removeSize);
}
