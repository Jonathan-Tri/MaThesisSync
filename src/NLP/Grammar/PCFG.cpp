/*
 * PCFG.cpp
 *
 *  Created on: Sep 29, 2017
 *      Author: jonathan.tri.vo
 */

#include "PCFG.h"

void PCFG::addRule(PCFGRule rule) {
	// check where this is a terminal rule, ex: NNS ::= Lines, VBN ::= established
	// will update Terminals list, in the future will map to VN terminal list
	if (rule.RHS.size() == 1 && !isNonTerminal(rule.getRHSStr())) {
		// the left hand side is a terminal, check to insert it to Terminals list
		if (findTheTerminal(rule.LHS)) {
			Terminals[rule.LHS]++;
		}
		else {
			Terminals[rule.LHS] = 1;
		}
		// find this terminal in the NonTerminals list
		// if find out, there are two approaches: change the sign or remove it
		if (findTheNonTerminal(rule.LHS)) {
			// first, try to remove it
			NonTerminals.erase(rule.LHS);
		}
	}
	else {
		// we assume that all is nonterminal
		updateNonTerminal(rule.LHS);
		for (int i = 0; i < rule.RHS.size(); i++) {
			std::string token = rule.RHS[i];
			updateNonTerminal(token);
		}
	}

	// add the rule to rule list
	ListRulesAddress listAddr;
	RuleAddress addr;
	if (findTheRule(rule, listAddr, addr)) {
		updateRule(rule, addr);
	}
	else {
		listAddr->second.push_back(rule);
	}
}

void PCFG::updateNonTerminal(std::string token) {
	if (findTheNonTerminal(token)) {
		NonTerminals[token]++;
	}
	else {
		NonTerminals[token] = 1;
	}
}

void PCFG::updateRule(const PCFGRule& rule, const RuleAddress& addr) {
	addr->setProbability(rule.getProbability());
}

bool PCFG::findTheRule(const PCFGRule& rule, ListRulesAddress listAddr, RuleAddress addr) {
	bool result = false;

	ListRulesAddress finder = Rules.begin();
	for (; finder != Rules.end(); ++finder) {
		if (finder->first == rule.LHS) {
			RuleAddress  finderIn = finder->second.begin();
			for (; finderIn != finder->second.end(); ++finderIn) {
				// find out the rule is equal to given rule
				if (Rule(rule) == Rule(*finderIn)) { // implement rule == operator
					listAddr = finder;
					addr = finderIn;
					result = true;
					break;
				}
			}
			break;
		}
	}

	return result;
}

bool PCFG::findTheNonTerminal(std::string nonterminal) {
	bool result = false;
	if (NonTerminals.find(nonterminal) != NonTerminals.end()) {
		result = true;
	}
	return result;
}

bool PCFG::findTheTerminal(std::string terminal) {
	bool result = false;
	if (Terminals.find(terminal) != Terminals.end()) {
		result = true;
	}
	return result;
}

bool PCFG::isNonTerminal(std::string token) {
	int len = token.length();
	for (int i = 0; i< len; ++i) {
		if (!((token[i]>='A' && token[i]<='Z')||(token[i]>='0' && token[i]<='9'))) {
			return false;
		}
	}
	return true;
}

	return result;
}
