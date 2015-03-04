
// *****************************************************************************

#include "utility/ruby/ruby.h"
#include <iostream>

// *****************************************************************************

using namespace Zero;
using namespace Ruby;

// *****************************************************************************

void VM::init()
{
    RUBY_INIT_STACK;
    ruby_init();
    ruby_init_loadpath();
    rb_set_safe_level(0);

    //ruby_setup();

    loadModules();
}

// *****************************************************************************

void VM::init(int argc, char**argv)
{
    ruby_sysinit(&argc, &argv);
    init();
}

// *****************************************************************************

void VM::shutdown()
{
    ruby_finalize();
}

// *****************************************************************************

void VM::loadModules()
{
    m_zeroModule.init();
}

// *****************************************************************************

static VALUE vm_thread(VALUE file)
{
    int status;

    Check_Type(file, T_ARRAY);
    rb_load_protect(file, 0, &status);
    if (status) {
        VALUE rbError = rb_funcall(rb_gv_get("$!"), rb_intern("message"), 0);
        std::cerr << StringValuePtr(rbError) << std::endl;
    };

    return INT2NUM(status);
}

// *****************************************************************************

int VM::load(const char* file)
{
    ruby_script(file);

    /*
    VALUE hardware_list;
    hardware_list = rb_ary_new();
    rb_define_variable("$hardware", &hardware_list);
    rb_ary_push(hardware_list, rb_str_new2("DVD"));
    rb_ary_push(hardware_list, rb_str_new2("CDPlayer1"));
    rb_ary_push(hardware_list, rb_str_new2("CDPlayer2"));
    */
    int status;
    rb_load_protect(rb_str_new2(file), 0, &status);
    if (status) {
        VALUE rbError = rb_funcall(rb_gv_get("$!"), rb_intern("message"), 0);
        std::cerr << StringValuePtr(rbError) << std::endl;
    };

    //VALUE argv[1];
    //argv[0] = rb_str_new2(file);
    //VALUE thread = rb_thread_create((ruby_method*)&vm_thread, argv);

    

    return status;//NUM2INT(thread);
}

// *****************************************************************************

VALUE _update(VALUE self)
{
    rb_funcall(rb_mKernel, rb_intern("update"), 0);
    return Qnil;
}

void VM::update()
{
    int status;
    rb_protect(_update, Qnil, &status);
    if (status) {
        VALUE rbError = rb_funcall(rb_gv_get("$!"), rb_intern("message"), 0);
        std::cerr << StringValuePtr(rbError) << std::endl;
    };
}

// *****************************************************************************