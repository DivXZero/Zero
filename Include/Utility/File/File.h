
// *****************************************************************************

#ifndef __ZERO_UTILITY_FILE_H__
#define __ZERO_UTILITY_FILE_H__

// *****************************************************************************

#include "SharedFile.h"

// *****************************************************************************

namespace Zero
{
    class File : public SharedFile
    {
    public:
        File() {}
        ~File() {}
    };
}

// *****************************************************************************

#endif  // __ZERO_UTILITY_FILE_H__