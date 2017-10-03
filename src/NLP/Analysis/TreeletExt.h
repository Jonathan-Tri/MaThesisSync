/*
 * TreeletExt.h
 *
 *  Created on: Aug 8, 2017
 *      Author: trivv
 */

#ifndef SRC_NLP_ANALYSIS_TREELETEXT_H_
#define SRC_NLP_ANALYSIS_TREELETEXT_H_

#include <string>

#include "../Alignment/AlignedSentence.h"
#include "../ParsedTree/ParserTree.h"

class CounterAlgorithm;
class IFileWriter;
class PCFG;

class TreeletExt {
public:
	TreeletExt();

	const AlignedSentence& getAlgSent() const {
		return algSent;
	}

	void setAlgSent(const AlignedSentence& algSent) {
		this->algSent = algSent;
	}

	const ParserTree& getTree() const {
		return pTree;
	}

	void setTree(const ParserTree& tree) {
		pTree = tree;
	}

	void setAlgSent(const AlignedSentence& algSent);

	Node* ExtTreelet(Node* root, int left, int right);

	void execute();

	void addMessage(std::string message);

	PCFG* GlobalGrammar;

private:
	ParserTree pTree;
	AlignedSentence algSent;
	IFileWriter *treeletRes;
	CounterAlgorithm* BetaHelper;
	CounterAlgorithm* AlphaHelper;
};


#endif /* SRC_NLP_ANALYSIS_TREELETEXT_H_ */
