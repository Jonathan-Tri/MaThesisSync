/*
 * BetaValue.cpp
 *
 *  Created on: Sep 23, 2017
 *      Author: trivv
 */

#include "BetaValue.h"

BetaValue::BetaValue(int len) : CounterAlgorithm(len) {
	BetaCalculate();

}

/*
 * The Inside Algorithm: Dynamic Algorithm
 */
void BetaValue::BetaCalculate() {
	for (int i = 1; i <= Len; i++) {
		for (int j = 1; j <= Len; j++) {
			setValue(i, j, 0);
		}
	}

	for (int j = Len - 1; j > 0; j--) {
		for (int i = j; i <= Len; i++) {
			if (i == j) {
				setValue(i, j, 1);
			}
			else {
				int Betaij = 0;
				for (int k = i; k < j; k++) {
					Betaij += getValue(i, k) * getValue(k + 1, j);
				}
				setValue(i, j, Betaij);
			}
		}
	}
}
