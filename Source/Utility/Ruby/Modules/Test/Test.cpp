
// *****************************************************************************

#include "Utility/Ruby/Modules/Test/Test.h"
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
    defineFunction("print", (Function*)&test_print, 1);
    defineFunction("add", (Function*)&test_add, 2);
    defineFunction("random", (Function*)&test_random, 2);
    defineFunction("set", (Function*)&test_set, 0);
    defineFunction("getWidth", (Function*)&test_getWidth, 0);
    defineFunction("create", (Function*)&test_create, 1);
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