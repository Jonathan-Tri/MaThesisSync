/*
 * AlphaValue.cpp
 *
 *  Created on: Sep 23, 2017
 *      Author: trivv
 */

#include "AlphaValue.h"

AlphaValue::AlphaValue(int len) : CounterAlgorithm(len) {
	Beta = new BetaValue(len);
	AlphaCalculate();
}

AlphaValue::~AlphaValue() {
	delete Beta;
}

void AlphaValue::AlphaCalculate() {
	for (int j = Len; j > 0; j--) {
		for (int i = 1; i <= Len; i++) {
			if (i == 1 && j == Len) {
				setValue(i, j, 1);
			}
			else {
				int alpha = 0;
				for (int k = 1; k < i; k++) {
					alpha += getValue(k, j) * Beta->getValue(k, i - 1);
				}
				for (int k = j + 1; k <= Len; k++) {
					alpha += getValue(i, k) * Beta->getValue(j+1, k);
				}
				setValue(i, j, alpha);
			}
		}
	}
}
