
// *****************************************************************************

#include "Utility/Ruby/Ruby.h"
#include <iostream>

// *****************************************************************************

using namespace Zero;
using namespace Zero::Ruby;

// *****************************************************************************

void VM::init()
{
    ruby_init();
    ruby_init_loadpath();
    rb_set_safe_level(0);
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

int VM::run(const char* file)
{
    int status;

    ruby_script(file);

    loadModules();

    /*
    VALUE hardware_list;
    hardware_list = rb_ary_new();
    rb_define_variable("$hardware", &hardware_list);
    rb_ary_push(hardware_list, rb_str_new2("DVD"));
    rb_ary_push(hardware_list, rb_str_new2("CDPlayer1"));
    rb_ary_push(hardware_list, rb_str_new2("CDPlayer2"));
    */

    rb_load_protect(rb_str_new2(file), 0, &status);
    if (status) {
        VALUE rbError = rb_funcall(rb_gv_get("$!"), rb_intern("message"), 0);
        std::cerr << StringValuePtr(rbError) << std::endl;
    };

    return status;
}

// *****************************************************************************