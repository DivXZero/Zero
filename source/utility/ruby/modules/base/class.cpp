
// *****************************************************************************

#include "utility/ruby/modules/base/class.h"
#include "utility/ruby/modules/base/module.h"

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

void Class::defineStaticFunction(const char* name, VALUE* func, int args)
{
    rb_define_singleton_method(get(), name, (ruby_method*)func, args);
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