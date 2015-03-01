
// *****************************************************************************

#ifndef __ZERO_UTILITY_JSON_H__
#define __ZERO_UTILITY_JSON_H__

// *****************************************************************************

#include "SharedJSON.h"
#include "../File/File.h"

#include "rapidjson/reader.h"
#include "rapidjson/writer.h"
#include "rapidjson/document.h"
#include "rapidjson/stringbuffer.h"

// *****************************************************************************

namespace Zero
{
    class JSON : public SharedJSON, private File
    {
    public:
        JSON() {}
        ~JSON() {}

        bool parse(const char* jsonstring);
        bool loadFromFile(const char* file);

        rapidjson::GenericMemberIterator<false, rapidjson::UTF8<char>, rapidjson::MemoryPoolAllocator<rapidjson::CrtAllocator>> begin() { return getDocument()->MemberBegin(); }
        rapidjson::GenericMemberIterator<false, rapidjson::UTF8<char>, rapidjson::MemoryPoolAllocator<rapidjson::CrtAllocator>> end() { return getDocument()->MemberEnd(); }

        rapidjson::Value& getValue(const char* key);
        rapidjson::Document* getDocument() { return &m_document; }
        rapidjson::StringBuffer getStringBuffer();

    private:
        rapidjson::Document     m_document;
    };
}

// *****************************************************************************

#endif  // __ZERO_UTILITY_JSON_H__