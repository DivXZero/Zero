
// *****************************************************************************

#include "Utility/File/File.h"

// *****************************************************************************

using namespace Zero;

// *****************************************************************************

bool File::open(const char* file)
{
    m_fname = file;
    m_fstream.open(file, std::ios::out | std::ios::in);
    return m_fstream.is_open();
}

// *****************************************************************************

std::string File::getDataString()
{
    m_strContent = std::string(std::istreambuf_iterator<char>(m_fstream), std::istreambuf_iterator<char>());
    return m_strContent;
}