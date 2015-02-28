
// *****************************************************************************

#ifndef __ZERO_UTILITY_RUBY_H__
#define __ZERO_UTILITY_RUBY_H__

// *****************************************************************************

#include "Modules/Zero.h"

// *****************************************************************************

namespace Zero
{
    namespace Ruby
    {
        class VM
        {
        public:
            void init();
            void init(int argc, char**argv);
            int run(const char* file);
            void shutdown();

        private:
            void loadModules();
            ZeroModule m_zeroModule;
        };
    }
}

// *****************************************************************************

#endif  // __ZERO_UTILITY_RUBY_H__