/*
 * client_MainLooper.h
 *
 *  Created on: May 16, 2016
 *      Author: santi
 */

#ifndef CLIENT_CLIENT_LOOPER_H_
#define CLIENT_CLIENT_LOOPER_H_

#include "client_Runnable.h"
#include "client_GarbageCollector.h"
#include "../../common/common_Mutex.h"
#include "../../common/common_Lock.h"
#include <queue>
#include <vector>
#include <cstdlib>

/**
 * Pasar a cpp
 *
 * Se puede hacer get y pop a la vez ? Me suena a que no asi que comparten el mutex
 */
class Looper {
private:
	Mutex mutex;

	std::queue<Runnable*> messagePool;

	bool gcRunning;
	std::vector<Runnable*> gcPool;
	GarbageCollector *gc;

public:
    static Looper& getMainLooper() {
        static Looper instance;
        return instance;
    }

	Runnable * get() {
		Runnable *value;

		{
			Lock lock(mutex);
			value = messagePool.empty() ? NULL : messagePool.front();
		}

		return value;
	}

	void pop() {
			Lock lock(mutex);

			if (!messagePool.empty()) {
				if (gcRunning)
					gcPool.push_back(messagePool.front());
				messagePool.pop();
			}
	}

	void put(Runnable *runnable) {
			Lock lock(mutex);
			messagePool.push(runnable);
	}
private:
	Looper(Looper const&);
	void operator=(Looper const&);

	explicit Looper() : gcRunning(true) {
			gc = new GarbageCollector(&gcRunning, &gcPool);
			gc->start();
	};

	~Looper() {
			gcRunning = false;
			gc->join();

			delete gc;
	}

};



#endif /* CLIENT_CLIENT_LOOPER_H_ */
