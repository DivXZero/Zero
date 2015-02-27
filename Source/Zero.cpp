
// *****************************************************************************

#include <ruby.h>
#include "glm/glm.hpp"
#include <iostream>

#include "Zero.h"

// *****************************************************************************

using namespace Zero;

// *****************************************************************************

int Ruby::StartVM(int argc, char**argv)
{
    ruby_sysinit(&argc, &argv);
    ruby_init();
    //ruby_init_loadpath();
    int status;
    //ruby_script("./test.rb");
    rb_load_protect(rb_str_new2("./test.rb"), 0, &status);
    if (status) {
        VALUE rbError = rb_funcall(rb_gv_get("$!"), rb_intern("message"), 0);
        std::cerr << StringValuePtr(rbError) << std::endl;
    };

    ruby_finalize();

    return status;
}