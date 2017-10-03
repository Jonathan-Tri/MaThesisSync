/*
 * PCFGRule.cpp
 *
 *  Created on: Sep 28, 2017
 *      Author: jonathan.tri.vo
 */

#include "PCFGRule.h"

PCFGRule::PCFGRule(std::string content, float prob) : Rule(content) {
	setProbability(prob);
}

//PCFGRule::PCFGRule(const ParserTree& tree, float prob) {
//	int childCnt = tree.getRoot()->getNumOfChildren();
//
//	setProbability(prob);
//}

bool PCFGRule::operator ==(const PCFGRule& rule) {
	Rule *baseL = this;
	if (*baseL == rule) {
		return getProbability() == rule.getProbability();
	}
	return false;
}
