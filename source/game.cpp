
// *****************************************************************************

#include "game.h"
#include <memory>
#include "system/window/sfmlwindow.h"

// *****************************************************************************

using namespace Zero;
using namespace Graphics;
using namespace System;

// *****************************************************************************

IMPLEMENT_SINGLETON(Game)

// *****************************************************************************

void Game::init()
{
    setWindow(new SFMLWindow());
    setSceneMgr(new Graphics::SceneManager());

    setScriptMgr(new Ruby::VM);
    TEMPscriptMgr()->init(0, 0);

    m_timer.start();
}

// *****************************************************************************

void Game::update()
{
    m_updateTime = m_timer.elapsedTime();

    if (m_updateTime > 0.25f)
        m_updateTime = 0.25f;

    m_accumTime += m_updateTime;

    window()->pollEvents();

    while (m_accumTime >= m_deltaTime)
    {
        sceneMgr()->update();
        TEMPscriptMgr()->update();

        m_accumTime -= m_deltaTime;
    }

    sceneMgr()->render();
    window()->swapBuffers();
}

// *****************************************************************************

void Game::run()
{
    while (window()->isOpen())
    {
        update();
    }    
}

// *****************************************************************************

void Game::cleanup()
{
    TEMPscriptMgr()->shutdown();
}

// *****************************************************************************