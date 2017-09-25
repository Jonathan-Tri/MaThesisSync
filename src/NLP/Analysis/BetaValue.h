/*
 * BetaValue.h
 *
 *  Created on: Sep 23, 2017
 *      Author: trivv
 */

#ifndef SRC_NLP_ANALYSIS_BETAVALUE_H_
#define SRC_NLP_ANALYSIS_BETAVALUE_H_

#include "CounterAlgorithm.h"


class BetaValue : public CounterAlgorithm{
public:
	BetaValue(int len);
private:
	void BetaCalculate();
};


#endif /* SRC_NLP_ANALYSIS_BETAVALUE_H_ */
