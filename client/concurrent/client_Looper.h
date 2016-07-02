#ifndef CLIENT_CLIENT_LOOPER_H_
#define CLIENT_CLIENT_LOOPER_H_

#include "client_Event.h"
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

	std::queue<Event*> messagePool;

public:
  static Looper& getMainLooper() {
    static Looper instance;
    return instance;
  }

	explicit Looper() {
	}

	~Looper() {
		while (messagePool.size() > 0) {
			delete messagePool.front();
			messagePool.pop();
		}
	}

	Event * get() {
		Event *value;

		{
			Lock lock(mutex);
			value = messagePool.empty() ? NULL : messagePool.front();
		}

		return value;
	}

	void pop() {
		Lock lock(mutex);

		if (!messagePool.empty()) {
			delete messagePool.front();
			messagePool.pop();
		}
	}

	void put(Event *ev) {
		Lock lock(mutex);
		messagePool.push(ev);
	}

	int size() {
		int size = -1;

		{
			Lock lock(mutex);
			size = messagePool.size();
		}

		return size;
	}

private:
	Looper(Looper const&);
	void operator=(Looper const&);

};

#endif /* CLIENT_CLIENT_LOOPER_H_ */
