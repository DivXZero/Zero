
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
    //defineFunction("print", (Function*)&print, 1);
    rb_define_singleton_method(get(), "new", (ruby_method*)classNew<Test>, 0);
    rb_define_method(get(), "print", (ruby_method*)&test_print, 1);
    rb_define_method(get(), "add", (ruby_method*)&test_add, 2);
    rb_define_method(get(), "random", (ruby_method*)&test_random, 2);
    rb_define_method(get(), "set", (ruby_method*)&set, 0);
    rb_define_method(get(), "getWidth", (ruby_method*)&getWidth, 0);
    rb_define_method(get(), "create", (ruby_method*)&create, 1);
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