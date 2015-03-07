
// *****************************************************************************

#include "system/window/sfmlwindow.h"
#include <iostream>

// *****************************************************************************

using namespace Zero;
using namespace System;

// *****************************************************************************

bool SFMLWindow::create(int width, int height, const char* title, bool fullscreen)
{
    m_width = width;
    m_height = height;
    m_title = title;
    m_isFullscreen = fullscreen;

    m_contextSettings.antialiasingLevel = 8;

    m_videoMode = sf::VideoMode(m_width, m_height);
    m_style = (m_isFullscreen) ? sf::Style::Fullscreen : sf::Style::Close;

    m_window.create(m_videoMode, m_title, m_style, m_contextSettings);

    resize();
    m_window.setVerticalSyncEnabled(true);

    m_isOpen = m_window.isOpen();

    return m_isOpen;
}

// *****************************************************************************

void SFMLWindow::resize()
{
    glViewport(0, 0, m_window.getSize().x, m_window.getSize().y);
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
    while (m_window.pollEvent(m_event))
    {
        if (m_event.type == sf::Event::Closed)
            destroy();

        if (m_event.type == sf::Event::Resized)
            resize();
    }
}

// *****************************************************************************

void SFMLWindow::swapBuffers()
{
    //glFlush();
    m_window.display();
}