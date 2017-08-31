
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
ParserTree ExtTreelet(Node* root, int left, int right) {
	ParserTree result;
	// get the span of node
	std::vector<std::string> source_span = root->getLeaves();
	int left_algn =

	return result;
}

void TreeletExt::execute() {
	int SrcCnt = algSent.getSrcSentLen();
	int TgtCnt = algSent.getTgtSentLen();

	for (int i = 0; i < SrcCnt - 1; i++) {
		for (int j = i + 1; j < SrcCnt; j++) {
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

