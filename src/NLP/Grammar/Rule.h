/*
 * Rule.h
 *
 *  Created on: Mar 26, 2017
 *      Author: trivv
 */

#ifndef SRC_NLP_GRAMMAR_RULE_H_
#define SRC_NLP_GRAMMAR_RULE_H_

#include <string>
#include <vector>


class Rule {
public:
	Rule();

	/*
	 * add a token into the rule depend on hand side flag
	 * if hand side flag = 1, this token will be added to the left hand
	 * otherwise it will be added into the right hand
	 */
	void addToken(int handFlag, std::string token);

	/*
	 * print out the rule
	 */
	void print();

public:
	std::string LHS;
	std::vector<std::string> RHS;
};


#endif /* SRC_NLP_GRAMMAR_RULE_H_ */
