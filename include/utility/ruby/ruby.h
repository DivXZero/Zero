
// *****************************************************************************

#ifndef __ZERO_UTILITY_RUBY_H__
#define __ZERO_UTILITY_RUBY_H__

// *****************************************************************************

#include "modules/zero.h"

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
            int load(const char* file);
            void update();
            void shutdown();

        private:
            void loadModules();
            ZeroModule m_zeroModule;
        };
    }
}

// *****************************************************************************

#endif  // __ZERO_UTILITY_RUBY_H__