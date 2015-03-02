
// *****************************************************************************

#include "Utility/Ruby/Modules/Class.h"
#include "Utility/Ruby/Modules/Module.h"

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

void Class::defineFunction(const char* name, Function* func, int args)
{
    rb_define_method(get(), name, (ruby_method*)&func, args);
}