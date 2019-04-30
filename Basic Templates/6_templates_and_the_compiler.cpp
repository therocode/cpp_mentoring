/*

6. Templates and the compiler

*/

/*
In this part we will talk about how a compiler compiles templated functions and classes. This
is an important process to understand as it is the base of many rules and tricks used in template metaprogramming

When we create a templated function, the compiler does nothing. You can see the templated function as some
sort of blueprint the compiler keeps stored somewhere to build new functions on. When we call the templated
function then, the compiler uses that blueprint to 'instantiate' the template for the type(s) that we requested.
For example:
*/

template<typename T>
void f(T val) {}

void template_instantiation() {
    f<int>(6);
    f<long double>(1.2);
}

// For this snippet of code, the compiler creates the following functions based on the definition of f:

void f(int val) {}
void f(long double val) {}

/*
Now that we know how the compiler processes templates, we can take a look at two more rules to consider when
working with templates. The first one has to do with compiler errors in templated functions.
*/

template<typename T>
T multiply(T a, T b) {
    return a * b;
}

/*
This is all fine, until you call multiply with two strings. Only then the compiler gives an error, since that is
the point where the function is instantiated with T = std::string. This is useful, since you don't want the 
compiler to complain about errors in functions that will never even exist.
*/

/*
The second rule has to do with header files and .cpp files. As you know, declarations like
void f();
should always go in the header files, while implementations for those functions like
void f() {

}

should always go in .cpp files. With templates, this is not the case. Templated functions and classes
should ALWAYS be implemented in header files. This is logical, because in order to instantiate a function the
compiler needs to see how that templated function is implemented so it can replace all occurences of T for example
with the type needed.
*/