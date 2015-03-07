
// *****************************************************************************

#ifndef __ZERO_LIB_GAME_H__
#define __ZERO_LIB_GAME_H__

// *****************************************************************************

#include "system/graphics/scenemanager.h"
#include "system/window/sharedwindow.h"
#include "utility/common.h"
#include <memory>

// *****************************************************************************

namespace Zero
{
    class Game : public Singleton<Game>
    {
    public:

        DECLARE_SINGLETON(Game)

        virtual ~Game() {}

        void init();
        void update();
        void run();
        void cleanup();

        std::shared_ptr<Graphics::SceneManager> sceneMgr()  { return m_sceneMgr; }
        std::shared_ptr<Graphics::Scene>        scene()     { return sceneMgr()->currentScene(); }
        std::shared_ptr<System::SharedWindow>   window()    { return m_windowPtr; }
        std::shared_ptr<Ruby::VM>          TEMPscriptMgr()  { return m_TEMPrubyVM; }

        void setSceneMgr(Graphics::SceneManager* smgr) { m_sceneMgr.reset(smgr); }
        void setWindow(System::SharedWindow* window) { m_windowPtr.reset(window); }
        void setScriptMgr(Ruby::VM* vm) { m_TEMPrubyVM.reset(vm); }

    private:

        Game() : m_deltaTime(0.01f), m_accumTime(0.0f) {}

        std::shared_ptr<Graphics::SceneManager> m_sceneMgr;
        std::shared_ptr<System::SharedWindow>   m_windowPtr;
        std::shared_ptr<Ruby::VM> m_TEMPrubyVM;

        Utility::Timer m_timer;
        float m_updateTime;
        float m_accumTime;
        float m_deltaTime;
    };

    inline Game* getGame() {
        return Game::getInstancePtr();
    }
}

// *****************************************************************************

#endif  // __ZERO_LIB_GAME_H__