/*
 * PCFGRule.h
 *
 *  Created on: Sep 28, 2017
 *      Author: jonathan.tri.vo
 */

#ifndef SRC_NLP_GRAMMAR_PCFGRULE_H_
#define SRC_NLP_GRAMMAR_PCFGRULE_H_

#include <string>

#include "../ParsedTree/ParserTree.h"
#include "Rule.h"


class PCFGRule : public Rule {
public:
	PCFGRule(std::string content, float prob = 1.0);
//	PCFGRule(const ParserTree& tree, float prob = 1.0);

	float getProbability() const {
		return Probability;
	}

	void setProbability(float probability) {
		Probability = probability;
	}

	bool operator ==(const PCFGRule& rule);

private:
	float Probability;
};


#endif /* SRC_NLP_GRAMMAR_PCFGRULE_H_ */
