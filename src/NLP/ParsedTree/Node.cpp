/*
 * Node.cpp
 *
 *  Created on: Mar 26, 2017
 *      Author: trivv
 */

#include "Node.h"

#include <cstdio>
#include <iostream>

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

Node::~Node() {
	printf("Destructor the node\n");
	for (size_t i = 0; i < Children.size(); i++) {
		delete Children[i];
	}
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

	int cntChild = node.getNumOfChildren();
	if (cntChild > 0) {
		for (int i = 0; i< cntChild; i++) {
			std::vector<std::string> child = getLeave(node.getChild(i));
			res.insert(res.end(), child.begin(), child.end());
		}
	}
	else {
		res.push_back(node.getContent());
	}

	return res;
}


std::vector<std::string> Node::getLeaves() {
	std::vector<std::string> res;

	int cntChild = getNumOfChildren();
	if (cntChild > 0) {
		for (int i = 0; i< cntChild; i++) {
			Node child = getChild(i);
			std::vector<std::string> childLeave = getLeave(child);
			res.insert(res.end(), childLeave.begin(), childLeave.end());
		}
	}
	else {
		res.push_back(getContent());
	}

	return res;
}
