// Copyright (c) 2012, Evgeny Panasyuk

// Permission is hereby granted, free of charge, to any person or organization
// obtaining a copy of the software and accompanying documentation covered by
// this license (the "Software") to use, reproduce, display, distribute,
// execute, and transmit the Software, and to prepare derivative works of the
// Software, and to permit third-parties to whom the Software is furnished to
// do so, all subject to the following:
// 
// The copyright notices in the Software and this entire statement, including
// the above license grant, this restriction and the following disclaimer,
// must be included in all copies of the Software, in whole or in part, and
// all derivative works of the Software, unless such copies or derivative
// works are solely in the form of machine-executable object code generated by
// a source language processor.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
// SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
// FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.

// e-mail: E?????[dot]P???????[at]gmail.???

#ifndef UNWINDING_AWARE_DESTRUCTOR_HPP
#define UNWINDING_AWARE_DESTRUCTOR_HPP


#include <stack_unwinding.hpp>

// Note: function-try-block for unwinding aware destructor does not catch exceptions from bases or members

// Put it into access specifier where you want to place your destructor.
// After this macro, access specifier is set to private
#define UNWINDING_AWARE_DESTRUCTOR(TYPE,UNWINDING_PARAM_NAME) \
    ~TYPE() \
    { stack_unwinding_aware_destructor##TYPE##UNWINDING_PARAM_NAME(this->stack_unwinding_indicator##TYPE##UNWINDING_PARAM_NAME.unwinding()); } \
    private: \
    stack_unwinding::unwinding_indicator stack_unwinding_indicator##TYPE##UNWINDING_PARAM_NAME; \
    void stack_unwinding_aware_destructor##TYPE##UNWINDING_PARAM_NAME(bool UNWINDING_PARAM_NAME)

// Put it into access specifier where you want to place your destructor.
// After this macro, access specifier is set to private
#define UNWINDING_AWARE_DESTRUCTOR_OUF_OF_CLASS_DECL(TYPE,UNWINDING_PARAM_NAME) \
    ~TYPE(); \
    private: \
    stack_unwinding::unwinding_indicator stack_unwinding_indicator##TYPE##UNWINDING_PARAM_NAME; \
    void stack_unwinding_aware_destructor##TYPE##UNWINDING_PARAM_NAME(bool UNWINDING_PARAM_NAME);

// Note: defines non-inline functions
#define UNWINDING_AWARE_DESTRUCTOR_OUT_OF_CLASS_DEF(TYPE,UNWINDING_PARAM_NAME) \
    TYPE::~TYPE() \
    { stack_unwinding_aware_destructor##TYPE##UNWINDING_PARAM_NAME(this->stack_unwinding_indicator##TYPE##UNWINDING_PARAM_NAME.unwinding()); } \
    void TYPE::stack_unwinding_aware_destructor##TYPE##UNWINDING_PARAM_NAME(bool UNWINDING_PARAM_NAME)

#endif