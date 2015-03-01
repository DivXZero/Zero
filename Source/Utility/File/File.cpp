
// *****************************************************************************

#include "Utility/File/File.h"

// *****************************************************************************

using namespace Zero;

// *****************************************************************************

bool File::open(const char* file)
{
    m_fname = file;
    //m_fstream.open(file, std::fstream::in);
    return true;
    //return m_fstream.is_open();
}

// *****************************************************************************

std::string File::getContentString()
{
    //open(m_fname);
    std::fstream    m_fstream(m_fname, std::fstream::in);
    m_strContent = std::string(std::istreambuf_iterator<char>(m_fstream), std::istreambuf_iterator<char>());
    m_fstream.close();
    return m_strContent;
}

// *****************************************************************************