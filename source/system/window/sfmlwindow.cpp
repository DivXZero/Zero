
// *****************************************************************************

#include "system/window/sfmlwindow.h"

// *****************************************************************************

using namespace Zero;
using namespace System;

// *****************************************************************************

bool SFMLWindow::create()
{
    m_width = 640;
    m_height = 480;
    m_title = "Zero";
    m_isFullscreen = false;

    m_contextSettings.antialiasingLevel = 8;

    m_videoMode = sf::VideoMode(m_width, m_height);
    m_style = (m_isFullscreen) ? sf::Style::Fullscreen : sf::Style::Close;

    m_window.create(m_videoMode, m_title, m_style, m_contextSettings);
    m_window.setVerticalSyncEnabled(true);

    return m_window.isOpen();
}

// *****************************************************************************

void SFMLWindow::resize()
{
    //glViewport(0, 0, m_window.getSize().x, m_window.getSize().y);
}

// *****************************************************************************

void SFMLWindow::destroy()
{
    m_window.close();
}

// *****************************************************************************

void SFMLWindow::pollEvents()
{
    m_window.pollEvent(m_event);
}

// *****************************************************************************