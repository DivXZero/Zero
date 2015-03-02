
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

        template <class T> struct _ruby_struct {
            T* ptr;
        };
        template <class T> using RubyStruct = _ruby_struct<T>;
    }
}

// *****************************************************************************

#endif  // __ZERO_RUBY_FUNCTION_H__