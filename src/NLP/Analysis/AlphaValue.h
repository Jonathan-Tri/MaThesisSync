/*
 * AlphaValue.h
 *
 *  Created on: Sep 23, 2017
 *      Author: trivv
 */

#ifndef SRC_NLP_ANALYSIS_ALPHAVALUE_H_
#define SRC_NLP_ANALYSIS_ALPHAVALUE_H_

#include "CounterAlgorithm.h"
#include "BetaValue.h"


class AlphaValue : public CounterAlgorithm {
public:
	AlphaValue(int len);
	~AlphaValue();
private:
	BetaValue* Beta;
	void AlphaCalculate();
};


#endif /* SRC_NLP_ANALYSIS_ALPHAVALUE_H_ */
