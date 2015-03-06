
// *****************************************************************************

#ifndef __ZERO_SYSTEM_GL_SCENE_H__
#define __ZERO_SYSTEM_GL_SCENE_H__

// *****************************************************************************

#include <SFML/OpenGL.hpp>
#include "scene.h"

// *****************************************************************************

namespace Zero
{
    namespace Graphics
    {
        class GLScene : public Scene
        {
            void init();
            void update();
            void render();
            void cleanup();
        };
    }
}

// *****************************************************************************

#endif  // __ZERO_SYSTEM_GL_SCENE_H__