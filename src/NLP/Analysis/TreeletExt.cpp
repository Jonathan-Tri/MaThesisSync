
/*
 * TreeletExt.cpp
 *
 *  Created on: Aug 9, 2017
 *      Author: trivv
 */

#include "TreeletExt.h"

#include "../../FileAdapter/FileWriterFactory.h"

TreeletExt::TreeletExt() {
	treeletRes = FileWriterFactory::getInstance().create(NEW_FILE_TYPE, "treelet.txt");
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
	// get the span of node
	std::vector<std::string> source_span = T->getLeaves();
	int left_algn = algSent.getLeftAlignIndex(source_span[0]);
	int right_algn = algSent.getRightAlignIndex(source_span[source_span.size() - 1]);
	if (left_algn > right || right_algn < left) {
		// T aligns totally outside of span e[left..right] then return the empty tree
		return result;
	} else if (left_algn >= left && right_algn <= right) {
		// T aligns totally inside of span e[left..right] then return the tree T
		return T;
	}
	else {
		// T aligns partly of span e[left..right] then we need to recursive inside T
		int cntChildren = T->getNumOfChildren();
		for (int i = 0; i < cntChildren; i++) {
			Node* partlyRs = ExtTreelet(T->getPChild(i), left, right);
			result->addChild(partlyRs);
		}
		return result;
	}
}

void TreeletExt::execute() {
//	int SrcCnt = algSent.getSrcSentLen();
	int TgtCnt = algSent.getTgtSentLen();

	for (int i = 0; i < TgtCnt - 1; i++) {
		for (int j = i + 1; j < TgtCnt; j++) {
			// pTree will keep a treelet that correspond with e[i, j]
			 ParserTree treelet = ExtTreelet(pTree.getRoot(), i, j);

			// output the treelet here
			std::string span = algSent.SrcSent[i];
			for (int k = i + 1; k <= j; k++) {
				span += " " + algSent.SrcSent[k];
			}
			std::string treeletContent = pTree.getCompressTree();
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
