
// *****************************************************************************

#ifndef __ZERO_UTILITY_SINGLETON_H__
#define __ZERO_UTILITY_SINGLETON_H__

// *****************************************************************************

#include <stddef.h>
#include <assert.h>

// *****************************************************************************

#define DECLARE_SINGLETON(classname)        \
    static classname &getInstance(void);    \
    static classname *getInstancePtr(void);

#define IMPLEMENT_SINGLETON(classname)                              \
    template<> classname *Singleton<classname>::m_Singleton = 0;    \
    classname &classname::getInstance(void) {                       \
        if(!m_Singleton) new classname();                           \
        return Singleton<classname>::getInstance(); }               \
        classname *classname::getInstancePtr(void) {                \
            if(!m_Singleton) new classname();                       \
            return Singleton<classname>::getInstancePtr(); }

template <typename T>
class Singleton
{
public:

    Singleton(void)
    {
        m_Singleton = static_cast<T*>(this);
    }

    virtual ~Singleton(void)
    {
        m_Singleton = 0;
    }

    static T& getInstance(void)
    {
        return *m_Singleton;
    }

    static T* getInstancePtr(void)
    {
        return m_Singleton;
    }

    inline void destroy(void)
    {
        delete this;
    }

protected:

    static T* m_Singleton;

};


#endif  // __ZERO_UTILITY_SINGLETON_H__