
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
		//Table = std::make_unique<long long[]>((Len + 1) * (Len + 1));
		Table = std::unique_ptr<long long[]>(new long long[(Len + 1) * (Len + 1)]);
	}
	catch (std::exception& ex) {
		logging::logErr("Error: %s", ex.what());
	}
}

long long CounterAlgorithm::getValue(int i, int j) {
	return *(Table.get() + (i - 1) * Len + (j - 1));
}

void CounterAlgorithm::setValue(int i, int j, long long value) {
	*(Table.get() + (i - 1) * Len + (j - 1)) = value;
}

CounterAlgorithm::~CounterAlgorithm() {
}


