/*
 * server_EngineRunner.h
 *
 *  Created on: Jun 20, 2016
 *      Author: mastanca
 */

#ifndef SERVER_GAME_ENGINE_SERVER_ENGINEWORKER_H_
#define SERVER_GAME_ENGINE_SERVER_ENGINEWORKER_H_

#include "../../common/common_Thread.h"
#include <mutex>              // std::mutex, std::unique_lock
#include <condition_variable>

class EngineWorker : public Thread{
private:
	bool* running;
	// Mutex for conditional variable
	std::mutex mutex;
	// Condition variable to not fry the cpu looking for evens
	std::condition_variable conditionVariable;
public:
	EngineWorker(bool* running);
	virtual ~EngineWorker();
	// Run the worker
	void run();
	void notify();
};

#endif /* SERVER_GAME_ENGINE_SERVER_ENGINEWORKER_H_ */
