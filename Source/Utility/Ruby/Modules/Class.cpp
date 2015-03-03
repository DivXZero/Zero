
// *****************************************************************************

#include "utility/ruby/modules/class.h"
#include "utility/ruby/modules/module.h"

// *****************************************************************************

using namespace Zero;
using namespace Ruby;

// *****************************************************************************

void Class::define(const char* name)
{
    m_class = rb_define_class(name, rb_cObject);
}

// *****************************************************************************

void Class::defineUnder(Module* parent, const char* name)
{
    m_class = rb_define_class_under(parent->get(), name, rb_cObject);
}

// *****************************************************************************

void Class::defineFunction(const char* name, VALUE* func, int args)
{
    rb_define_method(get(), name, (ruby_method*)func, args);
}

// *****************************************************************************

VALUE Class::callFunction(const char* func)
{
    return rb_funcall(get(), rb_intern(func), 0);
}

// *****************************************************************************