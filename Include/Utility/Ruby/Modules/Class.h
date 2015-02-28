
// *****************************************************************************

#ifndef __ZERO_RUBY_CLASS_H__
#define __ZERO_RUBY_CLASS_H__

// *****************************************************************************

#include "Function.h"

// *****************************************************************************

namespace Zero
{
    namespace Ruby
    {
        class Module;

        class Class
        {
        public:
            virtual void init() = 0;

            void define(const char* name);
            void defineUnder(Module* parent, const char* name);

            void defineFunction(const char* name, Function* func, int args);

            VALUE get() { Check_Type(m_class, T_CLASS); return m_class; }

        private:
            VALUE m_class;
        };
    }
}

// *****************************************************************************

#endif  // __ZERO_RUBY_CLASS_H__