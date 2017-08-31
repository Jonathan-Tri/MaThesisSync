/*
 * Node.h
 *
 *  Created on: Mar 26, 2017
 *      Author: trivv
 */

#ifndef SRC_NLP_PARSEDTREE_NODE_H_
#define SRC_NLP_PARSEDTREE_NODE_H_

#include <string>
#include <vector>

#include "../Grammar/Rule.h"


class Node {
public:
	Node();

	//Node(Rule rule, std::string content);

	//void setParent(Node* parent);

	std::string getContent();

	void setContent(std::string content);

	void addChild(Node* child);

	Node& getChild(size_t index);

	size_t getNumOfChildren();

	std::vector<std::string> getLeaves();

	void printMe(int tabCnt);

	~Node();

private:
	//Node *Parent;
	std::vector<Node*> Children;
	//int NumChildren;
	std::string Content;
};



#endif /* SRC_NLP_PARSEDTREE_NODE_H_ */
