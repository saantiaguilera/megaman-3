/*
 * server_EngineRunner.h
 *
 *  Created on: Jun 20, 2016
 *      Author: mastanca
 */

#ifndef SERVER_GAME_ENGINE_SERVER_ENGINEWORKER_H_
#define SERVER_GAME_ENGINE_SERVER_ENGINEWORKER_H_

#include "../../common/common_Thread.h"

class EngineWorker : public Thread{
private:
	bool* running;
public:
	EngineWorker(bool* running);
	virtual ~EngineWorker();
	// Run the worker
	void run();
};

#endif /* SERVER_GAME_ENGINE_SERVER_ENGINEWORKER_H_ */
