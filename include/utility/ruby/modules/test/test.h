
// *****************************************************************************

#ifndef __ZERO_RUBY_CLASS_TEST_H__
#define __ZERO_RUBY_CLASS_TEST_H__

// *****************************************************************************

#include "../base/class.h"
#include <iostream>

// *****************************************************************************

namespace Zero
{
    namespace Ruby
    {
        // *********************************************************************
        //  Main Class
        // *********************************************************************
        class Test : public Class
        {
        public:
            void init();
            void print(const char* msg);
            int add(int arg1, int arg2);
            double random(double min, double max);
            int getSceneCount();
            void pushScene();
            void popScene();
        };

        // *********************************************************************
        //  Ruby Functions
        // *********************************************************************
        namespace TestClass
        {
            // *****************************************************************

            static Function test_print(VALUE self, VALUE arg)
            {
                classPtr<Test>(self)->print(CSTR(arg));
                return arg;
            }

            // *****************************************************************

            static Function test_add(VALUE self, VALUE arg1, VALUE arg2)
            {
                int sum = classPtr<Test>(self)->add(NUM2INT(arg1), NUM2INT(arg2));
                return INT2NUM(sum);
            }

            // *****************************************************************

            static Function test_random(VALUE self, VALUE min, VALUE max)
            {
                double rnd = classPtr<Test>(self)->random(NUM2DBL(min), NUM2DBL(max));
                return DBL2NUM(rnd);
            }

            // *****************************************************************

            static Function test_set(VALUE self)
            {
                rb_iv_set(self, "@testvar", INT2NUM(7));
                return Qnil;
            }

            // *****************************************************************

            static Function test_getWidth(VALUE self)
            {
                return rb_iv_get(self, "@width");
            }

            // *****************************************************************

            static Function test_create(VALUE self, VALUE args)
            {
                Check_Type(args, T_HASH);
                VALUE title = rb_hash_aref(args, rb_eval_string(":title")); // vs. rb_str_new2("title")
                std::cout << "Title: " << rb_string_value_cstr(&title) << std::endl;
                return Qtrue;
            }

            // *****************************************************************

            static Function test_scene_count(VALUE self)
            {
                int count = classPtr<Test>(self)->getSceneCount();
                return INT2NUM(count);
            }

            // *****************************************************************

            static Function test_scene_push(VALUE self)
            {
                classPtr<Test>(self)->pushScene();
                return Qnil;
            }

            // *****************************************************************

            static Function test_scene_pop(VALUE self)
            {
                classPtr<Test>(self)->popScene();
                return Qnil;
            }
        }
    }
}

// *****************************************************************************

#endif  // __ZERO_RUBY_CLASS_TEST_H__