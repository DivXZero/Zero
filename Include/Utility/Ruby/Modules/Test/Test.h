
// *****************************************************************************

#ifndef __ZERO_RUBY_CLASS_TEST_H__
#define __ZERO_RUBY_CLASS_TEST_H__

// *****************************************************************************

#include "../Class.h"

// *****************************************************************************

namespace Zero
{
    namespace Ruby
    {
        typedef struct _test {
            int id;
        } TestStruct;

        class Test : public Class
        {
        public:
            void init();

            static int id;
        };
    }
}

// *****************************************************************************

#endif  // __ZERO_RUBY_CLASS_TEST_H__