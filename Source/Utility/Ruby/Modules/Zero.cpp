
// *****************************************************************************

#include "Utility/Ruby/Modules/Zero.h"

// *****************************************************************************

using namespace Zero;
using namespace Zero::Ruby;

// *****************************************************************************

static Function test(VALUE self)
{
    return Qnil;
}

// *****************************************************************************

void ConsoleClass::init()
{
    defineFunction("test", (Function*)&test, 0);
}

// *****************************************************************************

void ZeroModule::init()
{
    define("Zero");
}

// *****************************************************************************