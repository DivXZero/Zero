
// *****************************************************************************

#include "utility/ruby/modules/module.h"

// *****************************************************************************

using namespace Zero;
using namespace Ruby;

// *****************************************************************************

void Module::define(const char* name)
{
    m_module = rb_define_module(name);
}

// *****************************************************************************

void Module::defineUnder(Module* parent, const char* name)
{
    m_module = rb_define_module_under(parent->get(), name);
}

// *****************************************************************************

void Module::defineClass(Class* child, const char* name)
{
    child->defineUnder(this, name);
}