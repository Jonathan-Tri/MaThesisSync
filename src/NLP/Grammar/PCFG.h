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

typedef std::vector<std::string, std::vector<PCFGRule>> PCFGRulesType;
typedef PCFGRulesType::iterator PCFGRulesIterator;
typedef std::vector<PCFGRule>::iterator RuleListIterator;

class PCFG {
public:
	void addRule(PCFGRule rule);
	void updateRule(const PCFGRule& rule);
	bool findTheRule(const PCFGRule& rule, PCFGRulesIterator addr);
	bool findTheNonTerminal(std::string nonterminal);
	bool findTheTerminal(std::string terminal);
	bool isTerminal(std::string token);

private:
	std::vector<std::string, std::vector<PCFGRule>> Rules;
	std::map<std::string, int> NonTeminals;
	std::map<std::string, int> Terminals;
};


#endif /* SRC_NLP_GRAMMAR_PCFG_H_ */
