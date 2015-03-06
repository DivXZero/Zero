
// *****************************************************************************
#ifndef __ZERO_UTILITY_SINGLETON_H__
#define __ZERO_UTILITY_SINGLETON_H__

// *****************************************************************************

#include <stddef.h>
#include <assert.h>

// *****************************************************************************

template <class T>
class Singleton
{
public:
	static T* Instance() {
		if (!m_Instance) m_Instance = new T();
		assert(m_Instance != NULL);
		return m_Instance;
	}

protected:
	Singleton();
	~Singleton();

private:
	Singleton(Singleton const&);
	Singleton& operator=(Singleton const&);
	static T* m_Instance;
};

// *****************************************************************************

template <class T> T* Singleton<T>::m_Instance = NULL;

// *****************************************************************************

#endif  // __ZERO_UTILITY_SINGLETON_H__