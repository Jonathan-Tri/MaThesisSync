
/*
 * logging.cpp
 *
 *  Created on: Nov 5, 2016
 *      Author: trivv
 */

#include "logging.h"

#include <stdarg.h>
#include <stdlib.h>
#ifdef _WIN32
	#define	LOG_EMERG	0	 // system is unusable
	#define	LOG_ALERT	1	 // action must be taken immediately
	#define	LOG_CRIT	2	 // critical conditions
	#define	LOG_ERR		3	 // error conditions
	#define	LOG_WARNING	4	 // warning conditions
	#define	LOG_NOTICE	5	 // normal but significant condition
	#define	LOG_INFO	6	 // informational
	#define	LOG_DEBUG	7	 // debug-level messages
#else
	#include <syslog.h>
#endif
#include <cstdio>
#include <cstring>
#include <string>

#include "../FileAdapter/FileType.h"
#include "../FileAdapter/FileWriterFactory.h"
#include "SharedAlgorithm.h"


char *logging::log_fn;
unsigned int logging::log_level;
IFileWriter* logging::logger = NULL;

void logging::createLogger(char* fileName) {
	log_fn = (char *) calloc(strlen(fileName) + 1, sizeof(char));
	strcpy(log_fn, fileName);
	logger = FileWriterFactory::getInstance().create(NEW_APPD_FILE, log_fn, "w+");
	setLogLevel(LOG_FATAL);
}

const char* logging::getLogType(unsigned int log_level) {
	/*
	 * #define	LOG_EMERG	0	 system is unusable
	 * #define	LOG_ALERT	1	 action must be taken immediately
	 * #define	LOG_CRIT	2	 critical conditions
	 * #define	LOG_ERR		3	 error conditions
	 * #define	LOG_WARNING	4	 warning conditions
	 * #define	LOG_NOTICE	5	 normal but significant condition
	 * #define	LOG_INFO	6	 informational
	 * #define	LOG_DEBUG	7	 debug-level messages
	 */
	switch (log_level) {
		case 1: return "LOG_ALERT";
		case 2: return "LOG_CRIT";
		case 3: return "LOG_ERR";
		case 4: return "LOG_WARNING";
		case 5: return "LOG_NOTICE";
		case 6: return "LOG_FATAL";
		case 7: return "LOG_DEBUG";
	}
	return "UNKNOW";
}

void logging::logAlert(const char* format, ...) {
	std::string msg = SharedAlgorithm::StringBuilder("[%s] - [%s]: ",
			SharedAlgorithm::getCurrTime(), getLogType(LOG_ALERT));
	va_list argList;
	va_start(argList, format);
	msg += SharedAlgorithm::StringBuilder(format, argList);
	logger->writeLine(msg);
	va_end(argList);
}

void logging::logCristical(const char* format, ...) {
	std::string msg = SharedAlgorithm::StringBuilder("[%s] - [%s]: ",
			SharedAlgorithm::getCurrTime(), getLogType(LOG_CRIT));
	va_list argList;
	va_start(argList, format);
	msg += SharedAlgorithm::StringBuilder(format, argList);
	logger->writeLine(msg);
	va_end(argList);
}

void logging::logErr(const char* format, ...) {
	std::string msg = SharedAlgorithm::StringBuilder("[%s] - [%s]: ",
				SharedAlgorithm::getCurrTime(), getLogType(LOG_ERR));
	va_list argList;
	va_start(argList, format);
	msg += SharedAlgorithm::StringBuilder(format, argList);
	logger->writeLine(msg);
	va_end(argList);
}

void logging::logWarning(const char* format, ...) {
	std::string msg = SharedAlgorithm::StringBuilder("[%s] - [%s]: ",
					SharedAlgorithm::getCurrTime(), getLogType(LOG_WARNING));
	va_list argList;
	va_start(argList, format);
	msg += SharedAlgorithm::StringBuilder(format, argList);
	logger->writeLine(msg);
	va_end(argList);
}

void logging::logNotice(const char* format, ...) {
	std::string msg = SharedAlgorithm::StringBuilder("[%s] - [%s]: ",
						SharedAlgorithm::getCurrTime(), getLogType(LOG_NOTICE));
	va_list argList;
	va_start(argList, format);
	msg += SharedAlgorithm::StringBuilder(format, argList);
	logger->writeLine(msg);
	va_end(argList);
}

void logging::logFatal(const char* format, ...) {
	std::string msg = SharedAlgorithm::StringBuilder("[%s] - [%s]: ",
							SharedAlgorithm::getCurrTime(), getLogType(LOG_FATAL));
	va_list argList;
	va_start(argList, format);
	msg += SharedAlgorithm::StringBuilder(format, argList);
	va_end(argList);
	logger->writeLine(msg);
	printf("%s\n", msg.c_str());
}

void logging::logDebug(const char* format, ...) {
	if (log_level < 7) {
		return;
	}
	std::string msg = SharedAlgorithm::StringBuilder("[%s] - [%s]: ",
								SharedAlgorithm::getCurrTime(), getLogType(LOG_DEBUG));
	va_list argList;
	va_start(argList, format);
	msg += SharedAlgorithm::StringBuilder(format, argList);
	logger->writeLine(msg);
	va_end(argList);
}

int logging::getLogLevel() {
	return log_level;
}

const char* logging::getLogFileName() {
	return log_fn;
}

void logging::setLogLevel(int level) {
	log_level = level;
}

void logging::finalizeLogging() {
	logger->close();

}
