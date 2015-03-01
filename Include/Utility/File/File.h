
// *****************************************************************************

#ifndef __ZERO_UTILITY_FILE_H__
#define __ZERO_UTILITY_FILE_H__

// *****************************************************************************

#include "SharedFile.h"

#include <fstream>
#include <string>
#include <iostream>

// *****************************************************************************

namespace Zero
{
    class File : public SharedFile
    {
    public:
        File() {}
        ~File() {}

        bool open(const char* file);
        std::string getContentString();

    private:
        std::string     m_strContent;
        const char*     m_fname;
    };
}

// *****************************************************************************

#endif  // __ZERO_UTILITY_FILE_H__