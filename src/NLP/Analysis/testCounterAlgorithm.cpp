/*
 * testCounterAlgorithm.cpp
 *
 *  Created on: Sep 24, 2017
 *      Author: trivv
 */

#include <memory>
#include <string>

#include "../../FileAdapter/FileType.h"
#include "../../FileAdapter/FileWriterFactory.h"
#include "../../FileAdapter/IFileWriter.h"
#include "../../SharedAlgorithm/logging.h"
#include "../../SharedAlgorithm/SharedAlgorithm.h"
#include "AlphaValue.h"
#include "BetaValue.h"
#include "CounterAlgorithm.h"

std::string testCounterFile4 = "counterTable4.txt";
std::string testCounterFile16 = "counterTable16.txt";
std::string testCounterFile32 = "counterTable32.txt";

void testCounterAlgorithm4() {
	logging::logFatal("TEST COUNTER ALGORITHM>>>");
	IFileWriter *writer = FileWriterFactory::getInstance().create(NEW_FILE_TYPE, testCounterFile4.c_str());

	std::shared_ptr<BetaValue> Beta(new BetaValue(4));
	logging::logFatal("Create a new Beta Table with size is 4");
	writer->writeLine("Beta Value Table:");
	for (int i = 1; i <= Beta.get()->getLen(); i++) {
		for (int j = 1; j <= Beta.get()->getLen(); j++) {
//			writer->write(SharedAlgorithm::StringBuilder("%04d ", Beta.get()->getValue(i, j)));
			writer->write(SharedAlgorithm::StringBuilder("%04d ", i*j));
		}
		writer->writeLine("");
	}

	std::shared_ptr<AlphaValue> Alpha(new AlphaValue(4));
	logging::logFatal("Create a new Alpha Table with size is 4");
	writer->writeLine("Alpha Value Table:");
	for (int i = 1; i <= Alpha.get()->getLen(); i++) {
		for (int j = 1; j <= Alpha.get()->getLen(); j++) {
			writer->write(SharedAlgorithm::StringBuilder("%04d ", Alpha.get()->getValue(i, j)));
		}
		writer->writeLine("");
	}

	writer->close();
}

void testCounterAlgorithm16() {
	logging::logFatal("TEST COUNTER ALGORITHM>>>");
	IFileWriter *writer = FileWriterFactory::getInstance().create(NEW_FILE_TYPE, testCounterFile16.c_str());

	std::shared_ptr<BetaValue> Beta(new BetaValue(16));
	logging::logFatal("Create a new Beta Table with size is 16");
	writer->writeLine("Beta Value Table:");
	for (int i = 1; i <= Beta.get()->getLen(); i++) {
		for (int j = 1; j <= Beta.get()->getLen(); j++) {
			writer->write(SharedAlgorithm::StringBuilder("%04d ", Beta.get()->getValue(i, j)));
		}
		writer->writeLine("");
	}

	std::shared_ptr<AlphaValue> Alpha(new AlphaValue(16));
	logging::logFatal("Create a new Alpha Table with size is 16");
	writer->writeLine("Alpha Value Table:");
	for (int i = 1; i <= Alpha.get()->getLen(); i++) {
		for (int j = 1; j <= Alpha.get()->getLen(); j++) {
			writer->write(SharedAlgorithm::StringBuilder("%04d ", Alpha.get()->getValue(i, j)));
		}
		writer->writeLine("");
	}

	writer->close();
}


void testCounterAlgorithm32() {
	logging::logFatal("TEST COUNTER ALGORITHM>>>");
	IFileWriter *writer = FileWriterFactory::getInstance().create(NEW_FILE_TYPE, testCounterFile32.c_str());

	std::shared_ptr<BetaValue> Beta(new BetaValue(32));
	logging::logFatal("Create a new Beta Table with size is 32");
	writer->writeLine("Beta Value Table:");
	for (int i = 1; i <= Beta.get()->getLen(); i++) {
		for (int j = 1; j <= Beta.get()->getLen(); j++) {
			writer->write(SharedAlgorithm::StringBuilder("%04d ", Beta.get()->getValue(i, j)));
		}
		writer->writeLine("");
	}

	std::shared_ptr<AlphaValue> Alpha(new AlphaValue(32));
	logging::logFatal("Create a new Alpha Table with size is 32");
	writer->writeLine("Alpha Value Table:");
	for (int i = 1; i <= Alpha.get()->getLen(); i++) {
		for (int j = 1; j <= Alpha.get()->getLen(); j++) {
			writer->write(SharedAlgorithm::StringBuilder("%04d ", Alpha.get()->getValue(i, j)));
		}
		writer->writeLine("");
	}

	writer->close();
}
