
// *****************************************************************************

#ifndef __ZERO_SYSTEM_SCENE_H__
#define __ZERO_SYSTEM_SCENE_H__

// *****************************************************************************

namespace Zero
{
    namespace Graphics
    {
        class Scene
        {
        public:
            virtual void init() = 0;
            virtual void update() = 0;
            virtual void render() = 0;
            virtual void cleanup() = 0;
        };
    }
}

// *****************************************************************************

#endif  // __ZERO_SYSTEM_SCENE_H__