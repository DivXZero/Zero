
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
        // *********************************************************************

        typedef VALUE(ruby_method)(...);
        extern "C" typedef VALUE Function;

        // *********************************************************************

        static const char* CSTR(VALUE arg) {
            Check_Type(arg, T_STRING);
            return rb_string_value_cstr(&arg);
        }

        // *********************************************************************
    }
}

// *****************************************************************************

#endif  // __ZERO_RUBY_FUNCTION_H__