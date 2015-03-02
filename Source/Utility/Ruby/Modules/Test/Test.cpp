
// *****************************************************************************

#include "Utility/Ruby/Modules/Test/Test.h"
#include "glm/glm.hpp"
#include "glm/gtc/random.hpp"
#include <iostream>

// *****************************************************************************

using namespace Zero;
using namespace Zero::Ruby;

// *****************************************************************************

int Test::id = 0;

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
    rb_funcall(self, rb_intern("update"), 0);
    double rnd = glm::linearRand(NUM2DBL(min), NUM2DBL(max));
    return DBL2NUM(rnd);
}

// *****************************************************************************

static Function set(VALUE self)
{
    rb_iv_set(self, "@testvar", INT2NUM(7));
    return Qnil;
}

// *****************************************************************************

static Function getWidth(VALUE self)
{
    return rb_iv_get(self, "@width");
}

// *****************************************************************************

static void del_test(void* p)
{
    delete p;
}

// *****************************************************************************

static Function new_test(VALUE self)
{
    VALUE argv[1];
    TestStruct* ptr = new TestStruct;
    ptr->id = Test::id++;
    VALUE tdata = Data_Wrap_Struct(self, 0, del_test, ptr);
    rb_obj_call_init(tdata, 0, argv);
    return tdata;
}

// *****************************************************************************

static Function get_id(VALUE self)
{
    int id;
    TestStruct* ptr;
    Data_Get_Struct(self, TestStruct, ptr);
    id = ptr->id;
    return rb_int_new(id);
}

// *****************************************************************************

static Function create(VALUE self, VALUE args)
{
    Check_Type(args, T_HASH);
    VALUE title = rb_hash_aref(args, rb_eval_string(":title")); // vs. rb_str_new2("title")
    std::cout << "Title: " << rb_string_value_cstr(&title) << std::endl;
    return Qtrue;
}

// *****************************************************************************

void Test::init()
{
    //defineFunction("print", (Function*)&print, 1);
    rb_define_singleton_method(get(), "new", (ruby_method*)new_test, 0);
    rb_define_method(get(), "print", (ruby_method*)&print, 1);
    rb_define_method(get(), "add", (ruby_method*)&add, 2);
    rb_define_method(get(), "random", (ruby_method*)&random, 2);
    rb_define_method(get(), "set", (ruby_method*)&set, 0);
    rb_define_method(get(), "getWidth", (ruby_method*)&getWidth, 0);
    rb_define_method(get(), "getID", (ruby_method*)get_id, 0);
    rb_define_method(get(), "create", (ruby_method*)&create, 1);
}

// *****************************************************************************