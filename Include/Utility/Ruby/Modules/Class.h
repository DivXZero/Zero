
// *****************************************************************************

#ifndef __ZERO_RUBY_CLASS_H__
#define __ZERO_RUBY_CLASS_H__

// *****************************************************************************

#include "function.h"
#include <memory>

// *****************************************************************************

namespace Zero
{
    namespace Ruby
    {
        // *********************************************************************

        class Module;

        // *********************************************************************

        class Class
        {
        public:
            template <class T> void init() {
                rb_define_singleton_method(get(), "new", (ruby_method*)classNew<T>, 0);
            }

            void define(const char* name);
            void defineUnder(Module* parent, const char* name);

            void defineFunction(const char* name, VALUE* func, int args);
            VALUE callFunction(const char* func);

            VALUE get() { Check_Type(m_class, T_CLASS); return m_class; }

        private:
            VALUE m_class;
        };

        // *********************************************************************

        template <class T> struct _ruby_struct {
            std::unique_ptr<T> uniqPtr;
        };
        template <class T> using RubyStruct = _ruby_struct<T>;

        // *********************************************************************

        template <class T> T* classPtr(VALUE self)
        {
            RubyStruct<T>* ptr;
            Data_Get_Struct(self, RubyStruct<T>, ptr);
            return ptr->uniqPtr.get();
        }

        // *********************************************************************

        template <class T> void classDel(RubyStruct<T>* ptr)
        {
            ptr->uniqPtr.release();
            delete ptr;
        }

        // *********************************************************************

        template <class T> VALUE classNew(VALUE self)
        {
            RubyStruct<T>* ptr = new RubyStruct<T>;
            ptr->uniqPtr.reset(new T);

            VALUE argv[1];

            VALUE tdata = Data_Wrap_Struct(self, 0, classDel<T>, ptr);
            rb_obj_call_init(tdata, 0, argv);

            return tdata;
        }

        // *********************************************************************
    }
}

// *****************************************************************************

#endif  // __ZERO_RUBY_CLASS_H__