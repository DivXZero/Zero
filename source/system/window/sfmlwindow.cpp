
// *****************************************************************************

#include "system/window/sfmlwindow.h"
#include <iostream>

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

    m_isOpen = m_window.isOpen();

    std::cout << "OpenGL " << m_window.getSettings().majorVersion << "." << m_window.getSettings().minorVersion << std::endl;

    return m_isOpen;
}

// *****************************************************************************

void SFMLWindow::resize()
{
    //glViewport(0, 0, m_window.getSize().x, m_window.getSize().y);
}

// *****************************************************************************

void SFMLWindow::destroy()
{
    m_isOpen = false;
    m_window.close();
}

// *****************************************************************************

void SFMLWindow::pollEvents()
{
    m_window.pollEvent(m_event);

    if (m_event.type == sf::Event::Closed)
        destroy();
}

// *****************************************************************************

void SFMLWindow::swapBuffers()
{
    m_window.display();
}