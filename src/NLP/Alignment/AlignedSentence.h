/*
 * AlignedSentence.h
 *
 *  Created on: Apr 9, 2017
 *      Author: trivv
 */

#ifndef SRC_NLP_ALIGNMENT_ALIGNEDSENTENCE_H_
#define SRC_NLP_ALIGNMENT_ALIGNEDSENTENCE_H_

#include <string>
#include <utility>
#include <vector>

class AlignedSentence {
public:
	AlignedSentence();
	AlignedSentence(std::vector<std::string> srcSent,
			std::vector<std::string> tgtSent, std::vector<std::pair<int, int> > aligned);

	// get the target aligned words for a given source word
//	std::vector<int> getTgtAlignedWords(int srcIndex);
	// get the target aligned words for a given source word
	int getTgtAlignedWords(int srcIndex);
	int getRightmostTgtAlignedWords(int srcIndex);

	// get the target aligned words for a given source word
//	std::vector<int> getSrcAlignedWords(int tgtIndex);
	// get the target aligned words for a given source word
	int getSrcAlignedWords(int tgtIndex);
	int getRightmostSrcAlignedWords(int tgtIndex);

	// get the left align index
	int getLeftAlignIndex(int source, std::string word);

	// get the right align index
	int getRightAlignIndex(int source, std::string word);

	const std::vector<std::pair<int, int> >& getAligned() const {
		return Aligned;
	}

	void setAligned(const std::vector<std::pair<int, int> >& aligned) {
		Aligned = aligned;
	}

	const std::vector<std::string>& getSrcSent() const {
		return SrcSent;
	}

	void setSrcSent(const std::vector<std::string>& srcSent) {
		SrcSent = srcSent;
	}

	const std::vector<std::string>& getTgtSent() const {
		return TgtSent;
	}

	void setTgtSent(const std::vector<std::string>& tgtSent) {
		TgtSent = tgtSent;
	}

	int getSrcSentLen() {
		return SrcSent.size();
	}

	int getTgtSentLen() {
		return TgtSent.size();
	}
	void printMe();

//private:
	std::vector<std::string> SrcSent;
	std::vector<std::string> TgtSent;
	std::vector<std::pair<int, int> > Aligned;
	std::vector<std::pair<int, int> > AlignedSrcSorted;
	std::vector<std::pair<int, int> > AlignedTgtSorted;
};



#endif /* SRC_NLP_ALIGNMENT_ALIGNEDSENTENCE_H_ */
