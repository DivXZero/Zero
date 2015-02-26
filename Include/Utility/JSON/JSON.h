
// *****************************************************************************

#ifndef __ZERO_UTILITY_JSON_H__
#define __ZERO_UTILITY_JSON_H__

// *****************************************************************************

#include "SharedJSON.h"

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

// *****************************************************************************

namespace Zero
{
    class JSON : public SharedJSON
    {
    public:
        JSON() {}
        ~JSON() {}
    };
}

// *****************************************************************************

#endif  // __ZERO_UTILITY_JSON_H__