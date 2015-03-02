
// *****************************************************************************

#ifndef __ZERO_RUBY_FUNCTION_H__
#define __ZERO_RUBY_FUNCTION_H__

// *****************************************************************************

#include <ruby.h>

// *****************************************************************************

namespace Zero
{
    namespace Ruby
    {
        typedef VALUE(ruby_method)(...);
        extern "C" typedef VALUE Func;
        extern "C" typedef VALUE Function;
    }
}

// *****************************************************************************

#endif  // __ZERO_RUBY_FUNCTION_H__