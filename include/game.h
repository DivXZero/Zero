
// *****************************************************************************

#ifndef __ZERO_LIB_GAME_H__
#define __ZERO_LIB_GAME_H__

// *****************************************************************************

#include "system/graphics/scenemanager.h"
#include "system/window/sharedwindow.h"
#include "utility/common.h"

// *****************************************************************************

namespace Zero
{
    class Game
    {
    public:
        void init();
        void update();
        void render();
        void run();
        void cleanup();

        Graphics::SceneManager*               sceneMgr()  { return &m_sceneMgr; }
        std::shared_ptr<Graphics::Scene>      scene()     { return sceneMgr()->currentScene(); }
        std::shared_ptr<System::SharedWindow> window()    { return m_windowPtr; }
        Ruby::VM*                        TEMPscriptMgr()  { return &m_TEMPrubyVM; }

        void setWindow(std::shared_ptr<System::SharedWindow> window) { m_windowPtr = window; }

    private:
        Graphics::SceneManager          m_sceneMgr;
        std::shared_ptr<System::SharedWindow>   m_windowPtr;
        Ruby::VM                m_TEMPrubyVM;
    };

    using ZeroGame = Singleton<Game>;
}

// *****************************************************************************

#endif  // __ZERO_LIB_GAME_H__