
// *****************************************************************************

#include "game.h"
#include <memory>
#include "system/window/sfmlwindow.h"

// *****************************************************************************

using namespace Zero;
using namespace Graphics;
using namespace System;

// *****************************************************************************

void Game::init()
{
    TEMPscriptMgr()->init(0, 0);
    setWindow(std::make_shared<SFMLWindow>());
}

// *****************************************************************************

void Game::update()
{
    sceneMgr()->update();
    window()->pollEvents();
    //TEMPscriptMgr()->update();
}

// *****************************************************************************

void Game::render()
{
    sceneMgr()->render();
    window()->swapBuffers();
}

// *****************************************************************************

void Game::run()
{
    update();
    render();

    if (window()->isOpen())
    {
        run();
    }    
}

// *****************************************************************************

void Game::cleanup()
{
    TEMPscriptMgr()->shutdown();
}

// *****************************************************************************