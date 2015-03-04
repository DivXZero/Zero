
// *****************************************************************************

#ifndef __ZERO_LIB_RUBY_MODULE_H__
#define __ZERO_LIB_RUBY_MODULE_H__

// *****************************************************************************

#include "base/module.h"
#include "test/test.h"

// *****************************************************************************

namespace Zero
{
    namespace Ruby
    {
        class ZeroModule : public Module
        {
        public:
            void init();

            Test m_test;
        };
    }
}

// *****************************************************************************

#endif  // __ZERO_LIB_RUBY_MODULE_H__