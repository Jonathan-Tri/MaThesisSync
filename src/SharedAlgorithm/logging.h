/*
 * syslog.h
 *
 *  Created on: Sep 8, 2016
 *      Author: trivv
 */

#ifndef SHAREDALGORITHM_LOGGING_H_
#define SHAREDALGORITHM_LOGGING_H_

#include <stddef.h>

#include "../FileAdapter/IFileWriter.h"

enum {
	LOG_EMERG,
	LOG_ALERT,
	LOG_CRIT,
	LOG_ERR,
	LOG_WARNING,
	LOG_NOTICE,
	LOG_FATAL,
	LOG_DEBUG,
};


class logging {
public:

	/*
	 * create a system log to file
	 */
	static void createLogger(char* fileName);

	/*
	 * write down the message to log file
	 */
	static void insertlog(unsigned int level, const char *format, ...);


	/*
	 * map the log level to log mode
	 */
	static const char *getLogType(unsigned int log_level);

	/*
	 * insert log alert: log level = 1
	 */
	static void logAlert(const char *format, ...);

	/*
	 * insert log critical: log level = 2
	 */
	static void logCristical(const char *format, ...);

	/*
	 * insert log error: log level = 3
	 */
	static void logErr(const char *format, ...);

	/*
	 * insert log warning: log level = 4
	 */
	static void logWarning(const char *format, ...);

	/*
	 * insert log notice: log level = 5
	 */
	static void logNotice(const char *format, ...);

	/*
	 * insert log fatal/info: log level = 6
	 */
	static void logFatal(const char *format, ...);

	/*
	 * insert debug log: log level = 7
	 */
	static void logDebug(const char *format, ...);


	/*
	 * get log level: return integer number
	 */
	static int getLogLevel();

	/*
	 * get log file name
	 */
	static const char *getLogFileName();

	/*
	 * set log level
	 */
	static void setLogLevel(int level);

	/*
	 * finalize logging
	 */
	static void finalizeLogging();

private:
	static unsigned int log_level;
	static char *log_fn;
	static IFileWriter* logger;
};


#endif /* SHAREDALGORITHM_LOGGING_H_ */
