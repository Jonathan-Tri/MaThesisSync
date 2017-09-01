/*
 * AlignedSentence.cpp
 *
 *  Created on: Apr 9, 2017
 *      Author: trivv
 */

#include "AlignedSentence.h"
#include "../../SharedAlgorithm/logging.h"

#include <algorithm>
#include <string>
#include <utility>
#include <vector>

bool lowerCmp(const std::pair<int, int>& p, const int value) {
	return p.first < value;
}

bool upperCmp(const int value, const std::pair<int, int>& p) {
	return value < p.first;
}

bool lowerTgtCmp(const std::pair<int, int>& p, const int value) {
	return p.second < value;
}

bool upperTgtCmp(const int value, const std::pair<int, int>& p) {
	return value < p.second;
}


AlignedSentence::AlignedSentence() {
}

AlignedSentence::AlignedSentence(std::vector<std::string> srcSent,
		std::vector<std::string> tgtSent,
		std::vector<std::pair<int, int> > aligned) {
	setSrcSent(srcSent);
	setTgtSent(tgtSent);
	setAligned(aligned);
	AlignedSrcSorted = aligned;
	AlignedTgtSorted = aligned;

	// sort the align on the source side
	std::sort(AlignedSrcSorted.begin(), AlignedSrcSorted.end(), [](const std::pair<int, int> lhs,
			const std::pair<int, int> rhs) {
		return lhs.first < rhs.first;
	});

	// sort the align on the target side
	std::sort(AlignedTgtSorted.begin(), AlignedTgtSorted.end(), [](const std::pair<int, int> lhs,
			const std::pair<int, int> rhs) {
		return lhs.second < rhs.second;
	});
}



//std::vector<int> AlignedSentence::getTgtAlignedWords(int srcIndex) {
//	std::vector<int> result;
//	std::vector<std::pair<int, int> >::iterator left = std::lower_bound(Aligned.begin(), Aligned.end(), srcIndex, lowerCmp);
//
//	return result;
//}

int AlignedSentence::getTgtAlignedWords(int srcIndex) {
	return std::lower_bound(AlignedSrcSorted.begin(), AlignedSrcSorted.end(), srcIndex, lowerCmp) - AlignedSrcSorted.begin();
}

//std::vector<int> AlignedSentence::getSrcAlignedWords(int tgtIndex) {
//	std::vector<int> result;
//	std::vector<std::pair<int, int> >::iterator left = std::lower_bound(Aligned.begin(), Aligned.end(), tgtIndex, lowerCmp);
//	return result;
//}

int AlignedSentence::getSrcAlignedWords(int tgtIndex) {
	return std::lower_bound(AlignedTgtSorted.begin(), AlignedTgtSorted.end(), tgtIndex, lowerTgtCmp) - AlignedTgtSorted.begin();
}

int AlignedSentence::getRightmostTgtAlignedWords(int srcIndex) {
	return std::upper_bound(AlignedSrcSorted.begin(), AlignedSrcSorted.end(), srcIndex, upperCmp) - AlignedSrcSorted.begin();
}

int AlignedSentence::getRightmostSrcAlignedWords(int tgtIndex) {
	return std::upper_bound(AlignedTgtSorted.begin(), AlignedTgtSorted.end(), tgtIndex, upperTgtCmp) - AlignedTgtSorted.begin();
}

void AlignedSentence::printMe() {
	std::string srcSent = "";
	for (size_t i = 0; i < SrcSent.size(); i++) {
		srcSent += " " + SrcSent[i];
	}
	logging::logFatal("SrcSent: %s", srcSent.c_str());

	srcSent = "";
	for (size_t i = 0; i < TgtSent.size(); i++) {
		srcSent += " " + TgtSent[i];
	}
	logging::logFatal("TgtSent: %s", srcSent.c_str());
}

int AlignedSentence::getLeftAlignIndex(std::string word, int source) {
	int result = -1;

	if (source == 1) {
		// align from source to target
		int sourceIndex = std::lower_bound(SrcSent.begin(), SrcSent.end(), word) - SrcSent.begin();
		result = getTgtAlignedWords(sourceIndex);
	}
	else {
		// align from target to source
		int tgtIndex = std::lower_bound(TgtSent.begin(), TgtSent.end(), word) - TgtSent.begin();
		result = getSrcAlignedWords(tgtIndex);
	}

	return result;
}

int AlignedSentence::getRightAlignIndex(std::string word, int source) {
	int result = -1;

	if (source == 1) {
		// align from source to target
		int sourceIndex = std::lower_bound(SrcSent.begin(), SrcSent.end(), word) - SrcSent.begin();
		result = getRightmostTgtAlignedWords(sourceIndex);
	}
	else {
		// align from target to source
		int tgtIndex = std::lower_bound(TgtSent.begin(), TgtSent.end(), word) - TgtSent.end();
		result = getRightmostSrcAlignedWords(tgtIndex);
	}

	return result;
}
