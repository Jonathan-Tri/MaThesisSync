/*
 * AlignedSentence.cpp
 *
 *  Created on: Apr 9, 2017
 *      Author: trivv
 */

#include "AlignedSentence.h"

#include <stddef.h>
#include <algorithm>
#include <cstdio>
#include <iterator>

#include "../../SharedAlgorithm/logging.h"

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

void AlignedSentence::setAligned(const std::vector<std::pair<int, int> >& aligned) {
		Aligned = aligned;
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
	return AlignedSrcSorted[std::lower_bound(AlignedSrcSorted.begin(), AlignedSrcSorted.end(), srcIndex, lowerCmp) - AlignedSrcSorted.begin()].second;
}

//std::vector<int> AlignedSentence::getSrcAlignedWords(int tgtIndex) {
//	std::vector<int> result;
//	std::vector<std::pair<int, int> >::iterator left = std::lower_bound(Aligned.begin(), Aligned.end(), tgtIndex, lowerCmp);
//	return result;
//}

int AlignedSentence::getSrcAlignedWords(int tgtIndex) {
	return AlignedTgtSorted[std::lower_bound(AlignedTgtSorted.begin(), AlignedTgtSorted.end(), tgtIndex, lowerTgtCmp) - AlignedTgtSorted.begin()].first;
}

int AlignedSentence::getRightmostTgtAlignedWords(int srcIndex) {
	return AlignedSrcSorted[std::upper_bound(AlignedSrcSorted.begin(), AlignedSrcSorted.end(), srcIndex, upperCmp) - AlignedSrcSorted.begin() - 1].second;
}

int AlignedSentence::getRightmostSrcAlignedWords(int tgtIndex) {
	return AlignedTgtSorted[std::upper_bound(AlignedTgtSorted.begin(), AlignedTgtSorted.end(), tgtIndex, upperTgtCmp) - AlignedTgtSorted.begin() - 1].first;
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

auto findWord = [](std::vector<std::string> vector, std::string word) {
	int pos = 0;
	for (int i = 0; i < vector.size(); i++) {
		if (word == vector[i]) {
			pos = i;
			break;
		}
	}
	return pos;
};

int AlignedSentence::getLeftAlignIndex(std::string word, int source) {
	int result = -1;

	if (source == 1) {
		// align from source to target
		int sourceIndex = findWord(SrcSent, word);/*std::lower_bound(SrcSent.begin(), SrcSent.end(), word) - SrcSent.begin();*/
		if (sourceIndex > 0) {
			result = getTgtAlignedWords(sourceIndex + 1);
		}
	}
	else {
		// align from target to source
		int tgtIndex = findWord(TgtSent, word);/*std::lower_bound(TgtSent.begin(), TgtSent.end(), word) - TgtSent.begin();*/
		if (tgtIndex > 0) {
			result = getSrcAlignedWords(tgtIndex + 1);
		}
	}

	return result;
}

int AlignedSentence::getRightAlignIndex(std::string word, int source) {
	int result = -1;

	if (source == 1) {
		// align from source to target
		int sourceIndex = findWord(SrcSent, word);/*std::lower_bound(SrcSent.begin(), SrcSent.end(), word) - SrcSent.begin();*/
		if (sourceIndex > 0) {
			result = getRightmostTgtAlignedWords(sourceIndex + 1);
		}
	}
	else {
		// align from target to source
		int tgtIndex = findWord(TgtSent, word);/*std::lower_bound(TgtSent.begin(), TgtSent.end(), word) - TgtSent.end();*/
		if (tgtIndex > 0) {
			result = getRightmostSrcAlignedWords(tgtIndex + 1);
		}
	}

	return result;
}

/*
 * test something
 */
void testLowerUpBound1() {
	int myints[] = {10,20,30,30,20,10,10,20};
	std::vector<int> vt(myints, myints + 8);
	std::sort(vt.begin(), vt.end());
	printf("The data test:");
	auto lamda = [](std::vector<int> vt) {
		int sum = 0;
		for (int i = 0; i < vt.size(); i++) {
			printf("%d ", vt[i]);
			sum += vt[i];
		}
		return sum;
	};
	int sum = lamda(vt);
	printf("sum is %d\n", sum);
	int low_20 = std::lower_bound(vt.begin(), vt.end(), 20) - vt.begin();
	printf("lower_bound of 20 is %d \n", low_20);
	int up_20 = std::upper_bound(vt.begin(), vt.end(), 20) - vt.begin();
	printf("upper_bound of 20 is %d \n", up_20);
}

void AlignedSentence::ownerTest() {
	testLowerUpBound1();
	/*auto compareOp = [](std::string key, std::string value) {
		return key <= value;
	};*/
	/*int low =
	printf("lower_bound of 'Lines' is %d \n", low);

	low = std::lower_bound(SrcSent.begin(), SrcSent.end(), "communications", compareOp) - SrcSent.begin();
	std::string word = SrcSent[low];
	printf("lower_bound of 'communications' is %d at %s \n", low, word.c_str());

	low = std::lower_bound(SrcSent.begin(), SrcSent.end(), "communications", compareOp) - SrcSent.begin();
	word = SrcSent[low];
	printf("lower_bound of 'communications' is %d at %s \n", low, SrcSent[low].c_str());

	low = std::lower_bound(SrcSent.begin(), SrcSent.end(), "promoted", compareOp) - SrcSent.begin();
	word = SrcSent[low];
	printf("lower_bound of 'promoted' is %d at %s \n", low, SrcSent[low].c_str());

	low = std::lower_bound(SrcSent.begin(), SrcSent.end(), "NULL", compareOp) - SrcSent.begin();
	word = SrcSent[low];
	printf("lower_bound of 'NULL' is %d at %s \n", low, SrcSent[low].c_str());*/
}
