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


class PCFG {
public:
	void addRule(PCFGRule rule);
	void updateRule(PCFGRule rule);
private:
	std::vector<std::string, std::vector<PCFGRule>> Rules;
	std::map<std::string, int> NonTeminals;
	std::map<std::string, int> Terminals;
};


#endif /* SRC_NLP_GRAMMAR_PCFG_H_ */
