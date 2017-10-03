/*
 * Node.cpp
 *
 *  Created on: Mar 26, 2017
 *      Author: trivv
 */

#include "Node.h"

#include <stddef.h>
#include <cstdio>
#include <iostream>

#include "../../SharedAlgorithm/logging.h"
#include "../../SharedAlgorithm/SharedAlgorithm.h"

Node::Node() {
	//NumChildren = 0;
	Content = "";
}

//Node::Node(Rule rule, std::string content) {
//	Parent = NULL;
//	_rule = rule;
//	Content = content;
//}

void Node::addChild(Node* child) {
	//NumChildren++;
	Children.push_back(child);
}

Node& Node::getChild(size_t index) {
	return *Children[index];
}

Node* Node::getPChild(size_t index) {
	return Children[index];
}

//void Node::setParent(Node* parent) {
//	Parent = parent;
//}

std::string Node::getContent() {
	return Content;
}

void Node::setContent(std::string content) {
	Content = content;
}

size_t Node::getNumOfChildren() {
	return Children.size();
}

std::string Node::doGetTree(Node* node) {
	std::string result = "";
	int cnt = node->getNumOfChildren();
	if (cnt == 0) {
		result = node->getContent();
	}
	else {
		result += node->getContent();
		for (int i = 0; i < cnt; i++) {
			Node* child = node->getPChild(i);
			result += " " + doGetTree(child);
		}
	}
	return result;
}

std::string Node::getTree() {
	return doGetTree(this);
}

Node::~Node() {
	printf("Destructor the node\n");
//	for (size_t i = 0; i < Children.size(); i++) {
//		delete Children[i];
//	}
	Children.clear();
}

void Node::printMe(int tabCnt) {
	std::string tabBlock = "";
	for (int i = 0; i < tabCnt; i++) {
		tabBlock.append(LEVEL_BLOCK);
	}
	std::cout << tabBlock << getContent() << std::endl;
}

std::vector<std::string> getLeave(Node node) {
	std::vector<std::string> res;
	/*logging::logDebug("getLeave for node: %s", node.getContent().c_str());*/
	int cntChild = node.getNumOfChildren();
	if (cntChild > 0) {
		for (int i = 0; i< cntChild; i++) {
			std::vector<std::string> child = getLeave(node.getChild(i));
			if (!res.empty()) {
				res.reserve(res.size() + child.size());
				res.insert(res.end(), child.begin(), child.end());
			}
			else {
				res = child;
			}
		}
	}
	else {
		Rule simpleRule(node.getContent());
		res.push_back(simpleRule.getRHSStr());
	}
	/*std::string leaves = "";
	for (int i = 0; i < res.size(); i++) {
		leaves += res[i] + " ";
	}
	logging::logDebug("Leaves got: %s", leaves.c_str());*/
	return res;
}


std::vector<std::string> Node::getLeaves() {
	std::vector<std::string> res;
	logging::logDebug("[Node::getLeaves] - Node Content: %s", getContent().c_str());
	int cntChild = getNumOfChildren();
	logging::logDebug("[Node::getLeaves] - Node Children: %d", cntChild);
	if (cntChild > 0) {
		for (int i = 0; i< cntChild; i++) {
			Node child = getChild(i);
			std::vector<std::string> childLeave = getLeave(child);
			res.reserve(res.size() + childLeave.size());
			res.insert(res.end(), childLeave.begin(), childLeave.end());
		}
	}
	else {
		Rule simpleRule(getContent());
		res.push_back(simpleRule.getRHSStr());
	}
	if (!res.empty()) {
		std::string leaves = "";
		for (int i = 0; i < res.size(); i++) {
			leaves += res[i] + " ";
		}
		logging::logDebug("[Node::getLeaves] - Node Leaves: %s", leaves.c_str());
	}
	else {
		logging::logDebug("[Node::getLeaves] - Node Leaves: empty");
	}
	return res;
}
