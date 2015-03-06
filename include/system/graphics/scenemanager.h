
// *****************************************************************************

#ifndef __ZERO_SYSTEM_SCENE_MANAGER_H__
#define __ZERO_SYSTEM_SCENE_MANAGER_H__

// *****************************************************************************

#include <memory>
#include <stack>
#include "scene.h"

// *****************************************************************************

namespace Zero
{
    namespace Graphics
    {
        class SceneManager
        {
        public:
            template <class T> void push() { push(std::make_shared<T>()); }
            void push(std::shared_ptr<Scene> scene);
            void pop();

            void update();
            void render();

            bool hasScene() { return (!m_sceneStack.empty()); }
            int sceneCount() { return m_sceneStack.size(); }
            std::shared_ptr<Scene> currentScene() { return m_sceneStack.top(); }

        private:
            std::stack<std::shared_ptr<Scene>>  m_sceneStack;
        };
    }
}

// *****************************************************************************

#endif  // __ZERO_SYSTEM_SCENE_MANAGER_H__