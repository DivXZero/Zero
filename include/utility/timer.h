
// *****************************************************************************

#ifndef __ZERO_UTILITY_TIMER_H__
#define __ZERO_UTILITY_TIMER_H__

// *****************************************************************************

#include <SFML/System/Clock.hpp>

// *****************************************************************************

namespace Zero
{
    namespace Utility
    {
        class Timer
        {
        public:
            Timer() {}
            ~Timer() {}

            void start() { m_clock.restart(); m_updateTime = currentTime(); }

            float currentTime() { return m_clock.getElapsedTime().asSeconds(); }

            float elapsedTime() {
                float elapsed = currentTime() - m_updateTime;
                m_updateTime = currentTime();
                return elapsed;
            }

        private:
            sf::Clock m_clock;
            float m_updateTime;
        };
    }
}

// *****************************************************************************

#endif  // __ZERO_UTILITY_TIMER_H__