/*
 * PCFG.cpp
 *
 *  Created on: Sep 29, 2017
 *      Author: jonathan.tri.vo
 */

#include "PCFG.h"

void PCFG::addRule(PCFGRule rule) {
}

void PCFG::updateRule(const PCFGRule& rule) {
}

bool PCFG::findTheRule(const PCFGRule& rule, PCFGRulesIterator addr) {
	bool result = false;

	PCFGRulesIterator finder = Rules.begin();
	for (; finder != Rules.end(); ++finder) {
		if (finder->first == rule.LHS) {
			RuleListIterator  finderIn = finder->second.begin();
			for (; finderIn != finder->second.end(); ++finderIn) {

			}
			break;
		}
	}

	return result;
}

bool PCFG::findTheNonTerminal(std::string nonterminal) {
	bool result = false;

	return result;
}

bool PCFG::findTheTerminal(std::string terminal) {
	bool result = false;

	return result;
}

bool PCFG::isTerminal(std::string token) {
	bool result = false;

	return result;
}
