/*
 * TreeletExt.h
 *
 *  Created on: Aug 8, 2017
 *      Author: trivv
 */

#ifndef SRC_NLP_ANALYSIS_TREELETEXT_H_
#define SRC_NLP_ANALYSIS_TREELETEXT_H_

#include "../../FileAdapter/IFileWriter.h"
#include "../Alignment/AlignedSentence.h"
#include "../ParsedTree/ParserTree.h"

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

	void execute();

private:
	ParserTree pTree;
	AlignedSentence algSent;
	IFileWriter *treeletRes;
};


#endif /* SRC_NLP_ANALYSIS_TREELETEXT_H_ */