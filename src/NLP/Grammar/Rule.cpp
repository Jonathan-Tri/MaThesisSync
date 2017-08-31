/*
 * Rule.cpp
 *
 *  Created on: Mar 26, 2017
 *      Author: trivv
 */

#include "Rule.h"

#include <iostream>

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

void Rule::print() {
	std::cout << LHS << " ::= ";
	for (size_t i = 0; i < RHS.size(); i++) {
		std::cout << RHS[i];
	}
	std::cout << std::endl;
}
