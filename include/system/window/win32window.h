
// *****************************************************************************

#ifndef __ZERO_SYSTEM_WINDOW_WIN32__
#define __ZERO_SYSTEM_WINDOW_WIN32__

// *****************************************************************************

#ifdef WIN32

#define WIN32_LEAN_AND_MEAN

#include "sharedwindow.h"
#include <Windows.h>

// *****************************************************************************

namespace Zero
{
    namespace System
    {
        class Win32Window : public SharedWindow
        {
        public:
            bool create();
            void destroy() {}

            void pollEvents();

            void swapBuffers();

        private:
            WNDCLASSEX      m_wndClass;
            HWND            m_hWnd;
            HDC             m_hDC;
            MSG             m_msg;
        };
    }
}

// *****************************************************************************

#endif  // WIN32

// *****************************************************************************

#endif  // __ZERO_SYSTEM_WINDOW_WIN32__