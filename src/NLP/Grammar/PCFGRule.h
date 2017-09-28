/*
 * PCFGRule.h
 *
 *  Created on: Sep 28, 2017
 *      Author: jonathan.tri.vo
 */

#ifndef SRC_NLP_GRAMMAR_PCFGRULE_H_
#define SRC_NLP_GRAMMAR_PCFGRULE_H_

#include "Rule.h"


class PCFGRule : public Rule {
public:
	PCFGRule(std::string content, float prob = 1.0);

	float getProbability() const {
		return Probability;
	}

	void setProbability(float probability) {
		Probability = probability;
	}

private:
	float Probability;
};


#endif /* SRC_NLP_GRAMMAR_PCFGRULE_H_ */
