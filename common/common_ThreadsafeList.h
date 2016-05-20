#ifndef COMMONS_COMMON_THREADSAFELIST_H_
#define COMMONS_COMMON_THREADSAFELIST_H_

#include "common_Mutex.h"
#include <list>

/**
 * We use mutex and not a lock
 * because what we want is that if someone is
 * either removing or adding, the whole class
 * becomes locked. (you cant add while removing)
 *
 * Like a synchronized(object) of java.
 */
/**
 * According to c++03 standard I need to declare
 * here the methods
 * or well.. import the cpp file instead of .h or
 * use explicit inst
 * in the cpp. Which of the three I like to just
 * declare stuff
 * here as the least worse.
 *
 * Standard says:
 * The definition of a non-exported function template,
 * a non-exported member function template, or a
 * non-exported member function or static data member
 * of a class template shall be present in every
 * translation unit in which it is explicitly
 * instantiated.
 */
template<class Element>
class ConcurrentList {
private:
	Mutex mutex;
	std::list<Element> elementList;

public:
	ConcurrentList() {
	}

	virtual ~ConcurrentList() {
	}

	void add(Element element) {
		mutex.enableLock();

		elementList.push_back(element);

		mutex.disableLock();
	}

	void remove(Element element) {
		mutex.enableLock();

		elementList.remove(element);

		mutex.disableLock();
	}

	int size() {
		mutex.enableLock();

		int size = elementList.size();

		mutex.disableLock();

		return size;
	}

	std::list<Element> unblock() {
		return elementList;
	}

	void clear() {
		mutex.enableLock();

		elementList.clear();

		mutex.disableLock();
	}

	//So he can access our private stuff. c++11 onwards
	//Let us do this automatically w inner classes
	friend class ConcurrentIterator;

	class ConcurrentIterator {
	private:
		//Because we cant access outer elements from inner classes
		//available from c++11 onwards
		ConcurrentList *list;

	public:
		explicit ConcurrentIterator(ConcurrentList *list) :
				list(list) {
			list->mutex.enableLock();
		}

		virtual ~ConcurrentIterator() {
			list->mutex.disableLock();
		}

		typename std::list<Element>::iterator begin() {
			return list->elementList.begin();
		}

		typename std::list<Element>::iterator end() {
			return list->elementList.end();
		}

	private:
		ConcurrentIterator(const ConcurrentIterator&);
		ConcurrentIterator& operator=(const ConcurrentIterator&);
	};

private:
	ConcurrentList(const ConcurrentList&);
	ConcurrentList& operator=(const ConcurrentList&);
};

#endif /* COMMONS_COMMON_THREADSAFELIST_H_ */
