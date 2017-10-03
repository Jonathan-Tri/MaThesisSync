/*
 * PCFG.h
 *
 *  Created on: Sep 28, 2017
 *      Author: jonathan.tri.vo
 */

#ifndef SRC_NLP_GRAMMAR_PCFG_H_
#define SRC_NLP_GRAMMAR_PCFG_H_

#include <map>
#include <string>
#include <vector>

#include "PCFGRule.h"

typedef std::vector<std::pair<std::string, std::vector<PCFGRule>>> PCFGRulesType;
typedef PCFGRulesType::iterator ListRulesAddress;
typedef std::vector<PCFGRule>::iterator RuleAddress;

class PCFG {
public:
	void addRule(PCFGRule rule);
	void updateRule(const PCFGRule& rule, const RuleAddress& addr);
	bool findTheRule(const PCFGRule& rule, ListRulesAddress listAddr, RuleAddress addr);
	bool findTheNonTerminal(std::string nonterminal);
	bool findTheTerminal(std::string terminal);
	bool isNonTerminal(std::string token);
	void updateNonTerminal(std::string token);

private:
	PCFGRulesType Rules;
	std::map<std::string, int> NonTerminals;
	std::map<std::string, int> Terminals;
};


#endif /* SRC_NLP_GRAMMAR_PCFG_H_ */
