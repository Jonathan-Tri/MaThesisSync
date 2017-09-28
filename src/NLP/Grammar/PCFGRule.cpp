/*
 * PCFGRule.cpp
 *
 *  Created on: Sep 28, 2017
 *      Author: jonathan.tri.vo
 */

#include "PCFGRule.h"

PCFGRule::PCFGRule(std::string content, float prob) : Rule(content) {
	setProbability(prob);
}
