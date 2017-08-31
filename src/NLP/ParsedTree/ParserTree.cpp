
/*
 * parsedTree.cpp
 *
 *  Created on: Sep 15, 2016
 *      Author: trivv
 */

#include "ParserTree.h"

#include <stddef.h>
#include <cstdio>
#include <string>
#include <vector>

#include "../../SharedAlgorithm/logging.h"
#include "../../SharedAlgorithm/SharedAlgorithm.h"

ParserTree::ParserTree() {
	isNull = true;
	mroot = NULL;
	nodeCnt = 0;
	mCompressTreeText = "";
}

ParserTree::ParserTree(Node* root) {
	mroot = root;
	isNull = false;
	nodeCnt = 0;
	mCompressTreeText = "";
}

ParserTree::ParserTree(std::string compressTreeText) {
	mCompressTreeText = compressTreeText;
	SharedAlgorithm::removeTreeDecoration(mCompressTreeText);
	logging::logFatal("[ParserTree::Constructor]: building the tree with compress text: %s", mCompressTreeText.c_str());
	mroot = buildTree(mCompressTreeText);
}

std::string ParserTree::getCompressTree() {
	return mCompressTreeText;
}

std::string ParserTree::traversal() {
	std::string result = "";
	traversal(mroot, 0);
	return result;
}

void ParserTree::traversal(Node* node, int level) {
	node->printMe(level);
	size_t ChildCnt = node->getNumOfChildren();
	if (ChildCnt == 0) {
		return;
	}
	for (size_t i = 0; i < ChildCnt; i++) {
		traversal(&node->getChild(i), level + 1);
	}
}

Node* ParserTree::buildTree(std::string compressText) {
	SharedAlgorithm::trimAll(compressText);
	logging::logDebug("[ParserTree::buildTree]: compressText: %s", compressText.c_str());
	if (compressText.size() == 0) {
		return NULL;
	}

	Node* curNode = new Node();
	std::string content = SharedAlgorithm::getContentInfo(compressText);
	logging::logDebug("[ParserTree::buildTree]: set content for curNode: %s", content.c_str());
	curNode->setContent(content);
	int openingCnt = 0, closingCnt = 0, startIndex = -1, endIndex = -1, len = compressText.length();

	for (int i = 0; i < len; i++) {
		if (compressText[i] == '(') {
			openingCnt++;
			if (startIndex < 0) {
				startIndex = i;
			}
		}
		if (compressText[i] == ')') {
			closingCnt++;
		}
		if (openingCnt * closingCnt > 0 && openingCnt == closingCnt) {
			// we have just gotten a child of current node
			endIndex = i;
			std::string subCompressText = compressText.substr(startIndex, endIndex - startIndex + 1);
			if (subCompressText.size() > 0) {
				curNode->addChild(buildTree(subCompressText));
			}
			// we need to reset all flags to continuously acquiring next child
			openingCnt = 0, closingCnt = 0, startIndex = -1, endIndex = -1;
		}
	}

	return curNode;
}

ParserTree::~ParserTree() {
	printf("Cleaned the parsedTree\n");
}

