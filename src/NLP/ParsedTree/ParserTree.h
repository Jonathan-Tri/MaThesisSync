/*
 * parsedTree.h
 *
 *  Created on: Sep 15, 2016
 *      Author: trivv
 */

#ifndef SRC_NLP_PARSERTREE_PARSERTREE_H_
#define SRC_NLP_PARSERTREE_PARSERTREE_H_

#include "Node.h"

class ParserTree : public Node {
public:
	/*
	 * create a null parsed tree
	 */
	ParserTree();

	/*
	 * create a tree with root that is assigned by a node
	 */
	ParserTree(Node *root);

	/*
	 * build a tree with a compress parsed tree
	 */
	ParserTree(std::string compressTreeText);

	/*
	 * get a compress tree
	 */
	std::string getCompressTree();

	/*
	 * traversal
	 */
	std::string traversal();

	virtual std::string getTree();

	Node* getRoot() {return mroot;}

	bool isEmpty();

	/*
	 * destructor
	 */
	~ParserTree();

private:
	Node* buildTree(std::string compressText);
	void traversal(Node* node, int level);
	Node* mroot;
	int nodeCnt;
	bool isNull;
	std::string mCompressTreeText;
};



#endif /* SRC_NLP_PARSERTREE_PARSERTREE_H_ */
