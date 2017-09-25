
/*
 * CounterAlgorithm.cpp
 *
 *  Created on: Sep 23, 2017
 *      Author: trivv
 */

#include "CounterAlgorithm.h"

#include <exception>

#include "../../SharedAlgorithm/logging.h"

CounterAlgorithm::CounterAlgorithm(int len) {
	Len = len;
	try {
		Table = std::make_unique<int[]>((Len + 1) * (Len + 1));
	}
	catch (std::exception& ex) {
		logging::logErr("Error: %s", ex.what());
	}
}

int CounterAlgorithm::getValue(int i, int j) {
	return *(Table.get() + (i - 1) * Len + (j - 1));
}

void CounterAlgorithm::setValue(int i, int j, int value) {
	*(Table.get() + (i - 1) * Len + (j - 1)) = value;
}

CounterAlgorithm::~CounterAlgorithm() {
}


