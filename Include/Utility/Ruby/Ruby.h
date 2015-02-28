
// *****************************************************************************

#ifndef __ZERO_UTILITY_RUBY_H__
#define __ZERO_UTILITY_RUBY_H__

// *****************************************************************************

//#include <ruby.h>

// *****************************************************************************

namespace Zero
{
    class Ruby
    {
    public:
        void init();
        void init(int argc, char**argv);
        int run(const char* file);
        void shutdown();
    };
}

// *****************************************************************************

#endif  // __ZERO_UTILITY_RUBY_H__