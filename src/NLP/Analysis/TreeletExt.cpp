
/*
 * TreeletExt.cpp
 *
 *  Created on: Aug 9, 2017
 *      Author: trivv
 */

#include "TreeletExt.h"

#include <string>
#include <vector>

#include "../../FileAdapter/FileType.h"
#include "../../FileAdapter/FileWriterFactory.h"
#include "../../FileAdapter/IFileWriter.h"
#include "../../SharedAlgorithm/logging.h"
#include "../Grammar/PCFGRule.h"
#include "AlphaValue.h"
#include "BetaValue.h"

TreeletExt::TreeletExt() {
	treeletRes = FileWriterFactory::getInstance().create(NEW_FILE_TYPE, "treelet.txt");
	BetaHelper = NULL;
	AlphaHelper = NULL;
	GlobalGrammar = NULL;
}


void TreeletExt::setAlgSent(const AlignedSentence& algSent) {
	this->algSent = algSent;
	if (BetaHelper != NULL) {
		delete BetaHelper;
	}
	if (AlphaHelper != NULL) {
		delete AlphaHelper;
	}
	BetaHelper = new BetaValue(algSent.TgtSent.size());
	AlphaHelper = new AlphaValue(algSent.TgtSent.size());
}
/*
 * Input:
 * 		- a span e[i..j] of target sentence
 * 		- a source ptree
 * Output: A treelet T that cover-inside totally in span e[i..j]
 * Algorithm: recursive traversal
 */
Node* TreeletExt::ExtTreelet(Node* T, int left, int right) {
	Node *result =  new Node();
	logging::logDebug("[TreeletExt::ExtTreelet] - Extract Treelet for node: %s", T->getContent().c_str());
	// get the span of node
	// Jonathan -  important comment:
	// need to improve the time of get align -> using hash table
	// more test case here
	std::vector<std::string> source_span = T->getLeaves();
	logging::logFatal("[TreeletExt::ExtTreelet] - T holds a span %s", SharedAlgorithm::vec2String(source_span).c_str());
	int left_algn = algSent.getLeftAlignIndex(source_span[0]);
	int right_algn = algSent.getRightAlignIndex(source_span[source_span.size() - 1]);
//	int leftIndex = algSent.getIndex(source_span[0]);
//	int rightIndex = algSent.getIndex(source_span[source_span.size() - 1]);

	if (left_algn > right || right_algn < left) {
		// T aligns totally outside of span e[left..right] then return the empty tree
		return result;
	} else if (left_algn >= left && right_algn <= right) {
		// T aligns totally inside of span e[left..right] then return the tree T
		return T;
	}
	else {
//		if (left == right) {
//			return result;
//		}
		// T aligns partly of span e[left..right] then we need to recursive inside T
//		result->setContent(T->getContent());
		int cntChildren = T->getNumOfChildren();
//		if (cntChildren == 0) {
//			return T;
//		}
//		else {
			for (int i = 0; i < cntChildren; i++) {
				Node* partlyRs = ExtTreelet(T->getPChild(i), left, right);
				if (!partlyRs->isEmpty()) {
					result->addChild(partlyRs);
				}
			}
			return result;
//		}
	}
}

void attachToGlobal(PCFGRule rule) {
	//TBD
}

void TreeletExt::execute() {
//	int SrcCnt = algSent.getSrcSentLen();
	int TgtCnt = algSent.getTgtSentLen();// - 1;

	// test something
	/*algSent.ownerTest();
	return;*/
	for (int i = 0; i < TgtCnt - 1; i++) {
		for (int j = i; j < TgtCnt - 1; j++) {
			// pTree will keep a treelet that correspond with e[i, j]
			ParserTree treelet = ExtTreelet(pTree.getRoot(), i + 1, j + 1);

			// add the PCFG Rule built this treelet to Global Grammar
//			if (!treelet.isEmpty()) {
//				// get the highest rule from the treelet
//				PCFGRule theRule(treelet.getRoot()->getContent());
//				int childCnt = treelet.getRoot()->getNumOfChildren();
//				if (childCnt > 0) {
//					for (int i = 0; i < childCnt; i++) {
//						theRule.addToken(2, treelet.getRoot()->getPChild(i)->getContent());
//					}
//				}
//				attachToGlobal(theRule);
//			}


			// output the treelet here
			std::string span = algSent.TgtSent[i];
			for (int k = i + 1; k <= j; k++) {
				span += " " + algSent.TgtSent[k];
			}
			std::string treeletContent = treelet.getTree();
			treeletRes->write("Span: ");
			treeletRes->writeLine(span);
			treeletRes->write("Treelet: ");
			treeletRes->writeLine(treeletContent);
			treeletRes->writeLine("");
		}
	}

}

void TreeletExt::addMessage(std::string message) {
	treeletRes->writeLine(message);
}
