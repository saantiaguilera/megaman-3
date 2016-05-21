/*
 * server_Logger.cpp
 *
 *  Created on: May 21, 2016
 *      Author: mastanca
 */

#include "server_Logger.h"

#include <glog/logging.h>
#define LOG_DEST "/var/tmp/fiuba-taller-I-megaman"

void Logger::log(int logLevel, const std::string& dataToLog) {
	switch (logLevel) {
		case 1:
		    LOG(INFO) << dataToLog;
			break;
		case 2:
		    LOG(WARNING) << dataToLog;
			break;
		case 3:
		    LOG(ERROR) << dataToLog;
			break;
		default:
			break;
	}
}

Logger::Logger() {
    // Initialize Google's logging library.
    google::SetLogDestination(google::GLOG_INFO, LOG_DEST );
    google::InitGoogleLogging("fiuba-taller-I-megaman");
}

Logger::~Logger() {
}

Logger& Logger::getInstance() {
    static Logger instance;
    return instance;
}

