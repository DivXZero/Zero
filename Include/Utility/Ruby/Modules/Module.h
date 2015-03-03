
// *****************************************************************************

#ifndef __ZERO_RUBY_MODULE_H__
#define __ZERO_RUBY_MODULE_H__

// *****************************************************************************

#include "class.h"

// *****************************************************************************

namespace Zero
{
    namespace Ruby
    {
        class Module
        {
        public:
            virtual void init() = 0;
            // Define Module
            void define(const char* name);
            void defineUnder(Module* parent, const char* name);

            // Define Class
            void defineClass(Class* child, const char* name);
            
            VALUE get() { Check_Type(m_module, T_MODULE); return m_module; }

        private:
            VALUE m_module;
        };
    }
}

// *****************************************************************************

#endif  // __ZERO_RUBY_MODULE_H__