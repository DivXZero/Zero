
// *****************************************************************************

#ifndef __ZERO_RUBY_CLASS_H__
#define __ZERO_RUBY_CLASS_H__

// *****************************************************************************

#include "Function.h"

// *****************************************************************************

namespace Zero
{
    namespace Ruby
    {
        class Module;

        class Class
        {
        public:
            virtual void init() = 0;

            void define(const char* name);
            void defineUnder(Module* parent, const char* name);

            void defineFunction(const char* name, Function* func, int args);

            VALUE get() { Check_Type(m_class, T_CLASS); return m_class; }

        private:
            VALUE m_class;
        };

        template <class T> T* classPtr(VALUE self)
        {
            RubyStruct<T>* ptr;
            Data_Get_Struct(self, RubyStruct<T>, ptr);
            return ptr->ptr;
        }

        template <class T> void classDel(RubyStruct<T>* ptr)
        {
            delete ptr->ptr;
            delete ptr;
        }

        template <class T> VALUE classNew(VALUE self)
        {
            RubyStruct<T>* ptr = new RubyStruct<T>;
            ptr->ptr = new T;

            VALUE argv[1];

            VALUE tdata = Data_Wrap_Struct(self, 0, classDel<Test>, ptr);
            rb_obj_call_init(tdata, 0, argv);

            return tdata;
        }
    }
}

// *****************************************************************************

#endif  // __ZERO_RUBY_CLASS_H__