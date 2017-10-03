/*
 * Rule.cpp
 *
 *  Created on: Mar 26, 2017
 *      Author: trivv
 */

#include "Rule.h"

#include <stddef.h>
#include <iostream>

#include "../../SharedAlgorithm/SharedAlgorithm.h"

Rule::Rule() {
}

void Rule::addToken(int handFlag, std::string token) {
	if (handFlag == 1) {
		LHS = token;
	}
	else {
		RHS.push_back(token);
	}
}

std::string Rule::getRHSStr() {
	std::string rhsStr = RHS[0];
	if (RHS.size() > 1) {
		for (int i = 1; i < RHS.size(); i++) {
			rhsStr += " " + RHS[i];
		}
	}
	return rhsStr;
}

void Rule::print() {
	std::cout << LHS << " ::= ";
	for (size_t i = 0; i < RHS.size(); i++) {
		std::cout << RHS[i];
	}
	std::cout << std::endl;
}

Rule::Rule(std::string content) {
	buildSimpleRule(content);
}

// The simple rule assumes that the LHR only contains one non-terminal token
// and the RHS only contains terminal tokens
void Rule::buildSimpleRule(std::string content) {
	std::vector<std::string> tokens = SharedAlgorithm::parsedSent2Vec(content);
	if (tokens.empty()) {
		LHS = "";
		RHS.push_back("");
	}
	LHS = tokens[0];
	RHS.reserve(tokens.size() - 1);
	RHS.insert(RHS.end(), tokens.begin() + 1, tokens.end());
}

bool Rule::operator ==(const Rule& rule) {
	bool result = false;

	if (LHS == rule.LHS) {
		// check whether the RHS is equal
//		if (rule.RHS.size() == 1 && !SharedAlgorithm::isNonTerminal(rule.getRHSStr())) {
//			return true;
//		}
		if (RHS.size() != rule.RHS.size()) {
			return result;
		}
		for (int i = 0; i < RHS.size(); ++i) {
			if (RHS[i] != rule.RHS[i]) {
				return result;
			}
		}
		result = true;
	}

	return result;
}
