/*
 * CounterAlgorithm.h
 *
 *  Created on: Sep 23, 2017
 *      Author: trivv
 */

#ifndef SRC_NLP_ANALYSIS_COUNTERALGORITHM_H_
#define SRC_NLP_ANALYSIS_COUNTERALGORITHM_H_

#include <memory>

class CounterAlgorithm {
public:
	CounterAlgorithm(int len);
	int getValue(int i, int j);
	void setValue(int i, int j, int value);
	~CounterAlgorithm();

	int getLen() const {
		return Len;
	}

	void setLen(int len) {
		Len = len;
	}

protected:
	int Len;
	std::unique_ptr<int[]> Table;
};


#endif /* SRC_NLP_ANALYSIS_COUNTERALGORITHM_H_ */
