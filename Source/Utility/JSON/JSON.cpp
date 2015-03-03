
// *****************************************************************************

#include "utility/json/json.h"

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

rapidjson::Value& JSON::getValue(const char* key)
{
    assert(m_document.HasMember(key));

    return m_document[key];
}

// *****************************************************************************

StringBuffer JSON::getStringBuffer()
{
    StringBuffer buffer;
    Writer<StringBuffer> writer(buffer);
    m_document.Accept(writer);
    return buffer;
}

// *****************************************************************************

bool JSON::loadFromFile(const char* file)
{
    if(!open(file))
        return false;

    if (!parse(getContentString().c_str()))
        return false;

    //close();

    return true;
}

// *****************************************************************************