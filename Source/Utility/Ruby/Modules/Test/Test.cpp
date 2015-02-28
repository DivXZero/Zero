
// *****************************************************************************

#include "Utility/Ruby/Modules/Test/Test.h"
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

void Test::init()
{
    //defineFunction("print", (Function*)&print, 1);
    rb_define_method(get(), "print", (ruby_method*)&print, 1);
    rb_define_method(get(), "add", (ruby_method*)&add, 2);
}

// *****************************************************************************