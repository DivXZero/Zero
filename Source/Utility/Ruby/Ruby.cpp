
// *****************************************************************************

#include "Utility/Ruby/Ruby.h"
#include <ruby.h>
#include <iostream>

// *****************************************************************************

using namespace Zero;

// *****************************************************************************

typedef VALUE (ruby_method)(...);
extern "C" typedef VALUE RubyFunc;

// *****************************************************************************

static RubyFunc print(VALUE self, VALUE arg)
{
    Check_Type(arg, T_STRING);
    std::cout << rb_string_value_cstr(&arg) << std::endl;
    return arg;
}

// *****************************************************************************

void Ruby::init()
{
    ruby_init();
    ruby_init_loadpath();
    rb_set_safe_level(0);
}

// *****************************************************************************

void Ruby::init(int argc, char**argv)
{
    ruby_sysinit(&argc, &argv);
    init();
}

// *****************************************************************************

void Ruby::shutdown()
{
    ruby_finalize();
}

// *****************************************************************************

int Ruby::run(const char* file)
{
    int status;

    ruby_script(file);

    VALUE hardware_list;
    hardware_list = rb_ary_new();
    rb_define_variable("$hardware", &hardware_list);
    rb_ary_push(hardware_list, rb_str_new2("DVD"));
    rb_ary_push(hardware_list, rb_str_new2("CDPlayer1"));
    rb_ary_push(hardware_list, rb_str_new2("CDPlayer2"));

    VALUE modZero = rb_define_module("Zero");
    VALUE cConsole = rb_define_class_under(modZero, "Console", rb_cObject);
    rb_define_method(cConsole, "print", (ruby_method*)&print, 1);

    rb_load_protect(rb_str_new2(file), 0, &status);
    if (status) {
        VALUE rbError = rb_funcall(rb_gv_get("$!"), rb_intern("message"), 0);
        std::cerr << StringValuePtr(rbError) << std::endl;
    };

    return status;
}

// *****************************************************************************