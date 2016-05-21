/*
 * server_Logger.h
 *
 *  Created on: May 21, 2016
 *      Author: mastanca
 */

#ifndef SERVER_SERVER_LOGGER_H_
#define SERVER_SERVER_LOGGER_H_

#include <string>

class Logger {
	// Singleton
public:
	// Return logger instance
	static Logger& getInstance();
	// Destroyer
	virtual ~Logger();
	// Put data in log
	// Use log level 1 for INFO, 2 for WARNING, 3 for ERROR
	void log(int logLevel, const std::string& dataToLog);
private:
	// Private constructor for singleton
	Logger();
};

#endif /* SERVER_SERVER_LOGGER_H_ */

