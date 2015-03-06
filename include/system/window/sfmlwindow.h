
// *****************************************************************************

#ifndef __ZERO_SYSTEM_SFML_WINDOW_H__
#define __ZERO_SYSTEM_SFML_WINDOW_H__

// *****************************************************************************

#include <SFML/Graphics.hpp>

#include "sharedwindow.h"

// *****************************************************************************

namespace Zero
{
    namespace System
    {
        class SFMLWindow : public SharedWindow
        {
        public:
            bool create();
            void destroy();

            void resize();

            void swapBuffers();

            void pollEvents();

        private:
            sf::RenderWindow    m_window;
            sf::VideoMode       m_videoMode;
            sf::ContextSettings m_contextSettings;
            sf::Uint32          m_style;
            sf::Event           m_event;
        };
    }
}

// *****************************************************************************

#endif  // __ZERO_SYSTEM_SFML_WINDOW_H__