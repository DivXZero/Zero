
// *****************************************************************************

#include "Utility/Ruby/Modules/Test/Test.h"
#include "glm/glm.hpp"
#include "glm/gtc/random.hpp"
#include <iostream>

// *****************************************************************************

using namespace Zero;
using namespace Zero::Ruby;

// *****************************************************************************

static Function print(VALUE self, VALUE arg)
{
    Check_Type(arg, T_STRING);
    std::cout << rb_string_value_cstr(&arg) << std::endl;
    return arg;
}

// *****************************************************************************

static Function add(VALUE self, VALUE arg1, VALUE arg2)
{
    VALUE sum = INT2NUM(NUM2INT(arg1) + NUM2INT(arg2));
    return sum;
}

// *****************************************************************************

static Function random(VALUE self, VALUE min, VALUE max)
{
    double rnd = glm::linearRand(NUM2DBL(min), NUM2DBL(max));
    return DBL2NUM(rnd);
}

// *****************************************************************************

void Test::init()
{
    //defineFunction("print", (Function*)&print, 1);
    rb_define_method(get(), "print", (ruby_method*)&print, 1);
    rb_define_method(get(), "add", (ruby_method*)&add, 2);
    rb_define_method(get(), "random", (ruby_method*)&random, 2);
}

// *****************************************************************************