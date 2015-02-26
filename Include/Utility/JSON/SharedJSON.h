
// *****************************************************************************

#ifndef __ZERO_UTILITY_SHARED_JSON_H__
#define __ZERO_UTILITY_SHARED_JSON_H__

// *****************************************************************************

namespace Zero
{
    class SharedJSON
    {
    public:
        virtual ~SharedJSON() = 0;

        virtual bool parse(const char* jsonstring) = 0;
    };
}

// *****************************************************************************

#endif  // __ZERO_UTILITY_SHARED_JSON_H__