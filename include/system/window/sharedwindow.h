
// *****************************************************************************

#ifndef __ZERO_SYSTEM_SHARED_WINDOW_H__
#define __ZERO_SYSTEM_SHARED_WINDOW_H__

// *****************************************************************************

namespace Zero
{
    namespace System
    {
        class SharedWindow
        {
        public:
            virtual bool create() = 0;
            virtual void destroy() = 0;

            //virtual void resize() = 0;

            virtual void swapBuffers() = 0;

            virtual void pollEvents() = 0;

            bool isOpen() { return m_isOpen; }

        protected:
            const char* m_title;
            int m_width, m_height;
            bool m_isFullscreen;
            bool m_isOpen;
        };
    }
}

// *****************************************************************************

#endif  // __ZERO_SYSTEM_SHARED_WINDOW_H__