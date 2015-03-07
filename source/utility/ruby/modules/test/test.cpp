
// *****************************************************************************

#include "game.h"
#include "system/graphics/glscene.h"
#include "utility/ruby/modules/test/test.h"
#include "glm/glm.hpp"
#include "glm/gtc/random.hpp"
#include <iostream>

// *****************************************************************************

using namespace Zero;
using namespace Ruby;
using namespace TestClass;

// *****************************************************************************

void Test::init()
{
    Class::init<Test>();
    //defineFunction("print", (Function*)&test_print, 1);
    defineFunction("add", (Function*)&test_add, 2);
    defineFunction("random", (Function*)&test_random, 2);
    defineFunction("set", (Function*)&test_set);
    defineFunction("getWidth", (Function*)&test_getWidth);
    defineFunction("create", (Function*)&test_create, 1);
    defineFunction("scene_count", (Function*)&test_scene_count);
    defineFunction("push_scene", (Function*)&test_scene_push);
    defineFunction("pop_scene", (Function*)&test_scene_pop);
}

// *****************************************************************************

void Test::print(const char* msg)
{
    std::cout << msg << std::endl;
}

// *****************************************************************************

int Test::add(int arg1, int arg2)
{
    return arg1 + arg2;
}

// *****************************************************************************

double Test::random(double min, double max)
{
    return glm::linearRand(min, max);
}

// *****************************************************************************

int Test::getSceneCount()
{
    return getGame()->sceneMgr()->sceneCount();
}

// *****************************************************************************

void Test::pushScene()
{
    getGame()->sceneMgr()->push<Graphics::GLScene>();
}

// *****************************************************************************

void Test::popScene()
{
    getGame()->sceneMgr()->pop();
}