
// *****************************************************************************

#include "system/graphics/scenemanager.h"

// *****************************************************************************

using namespace Zero;
using namespace Graphics;

// *****************************************************************************

void SceneManager::push(std::shared_ptr<Scene> scene)
{
    m_sceneStack.push(scene);
    currentScene()->init();
}

// *****************************************************************************

void SceneManager::pop()
{
    if (hasScene())
    {
        currentScene()->cleanup();
        m_sceneStack.pop();
        if (hasScene())
            currentScene()->init();
    }
}

// *****************************************************************************

void SceneManager::update()
{
    if (hasScene())
    {
        currentScene()->update();
    }
}

// *****************************************************************************

void SceneManager::render()
{
    if (hasScene())
    {
        currentScene()->render();
    }
}

// *****************************************************************************