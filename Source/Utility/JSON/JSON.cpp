
// *****************************************************************************

#include "Utility/JSON/JSON.h"

// *****************************************************************************

using namespace Zero;
using namespace rapidjson;

// *****************************************************************************

bool JSON::parse(const char* jsonstring)
{
    if (m_document.Parse(jsonstring).HasParseError())
        return false;

    assert(m_document.IsObject());

    return true;
}

// *****************************************************************************