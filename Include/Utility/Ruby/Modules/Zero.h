
// *****************************************************************************

#ifndef __ZERO_LIB_RUBY_MODULE_H__
#define __ZERO_LIB_RUBY_MODULE_H__

// *****************************************************************************

#include "Module.h"

// *****************************************************************************

namespace Zero
{
    namespace Ruby
    {
        class ConsoleClass : public Class
        {
        public:
            void init();
        };

        class ZeroModule : public Module
        {
        public:
            void init();
        };
    }
}

// *****************************************************************************

#endif  // __ZERO_LIB_RUBY_MODULE_H__