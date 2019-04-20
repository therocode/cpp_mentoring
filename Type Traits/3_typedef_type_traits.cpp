/*

3. Creating a "typedef type trait"

*/

/*
The "typedef type traits" are very similar to the "value type traits", except that they provide a 
typedef or using declaration instead of a (boolean) value. The first example we will create is std::add_pointer.
This type trait 'returns' a T* and is fairly easy to implement
*/

template<typename T>
struct add_pointer {
    using type = T*;
};

/*
And that's it. There is however one issue with using it. If we try to do the following:
add_pointer<int>::type intptr;
everything is fine. However, consider the following function:
*/

template<typename T>
void f() {
//    add_pointer<T>::type tPtr; // BAD!
}

/*
We get a compiler error along the lines of 'dependent name is not a type'.
How do we get this? We clearly provided a typedef in the add_pointer struct. 

The problem is that the compiler cannot know if, for all instantiations of f(), add_pointer<T>::type is actually
a type. The user might have a specialization for add_pointer<int>, in which ::type is an integer (even though
that would be quite stupid). To fix this issue, we simply add 'typename' in front to tell the compiler that it 
is a type:
*/

template<typename T>
void g() {
    typename add_pointer<T>::type tPtr; // Now it works
}

/*
As you can see though, this again adds a lot of boilerplate to our program. We can luckily do something
similar to what we have seen already with the "value type traits":
*/

template<typename T>
using add_pointer_t = typename add_pointer<T>::type; // Don't forget 'typename' here.

/*
The next time we want to use add_pointer, we simply use add_pointer_t and we don't have to put
'typename' or '::type' everywhere.
*/

#include <type_traits>

void test_add_pointer() {
    static_assert(std::is_same_v<int*, add_pointer_t<int>>, "add_pointer<int> should be int*");
}


/*
We will implement one other "typedef type trait" here. This time we are going to create remove_reference<T>. This
trait removes lvalue and rvalue references and returns the raw type.
*/

template<typename T>
struct remove_reference {
    using type = T;
};

/*
This is the base case. Now we are going to create the different specializations for reference types.
*/

template<typename T>
struct remove_reference<T&> {
    using type = T;
};

template<typename T>
struct remove_reference<T&&> {
    using type = T;
};

/*
Now that we have the two specilizations for lvalue and rvalue references, we can test this out:
*/

template<typename T>
using remove_reference_t = typename remove_reference<T>::type;

void test_remove_reference() {
    static_assert(std::is_same_v<remove_reference_t<int&>, int>, "remove_reference<int&> should give int");
    static_assert(std::is_same_v<remove_reference_t<int>, int>, "remove_reference<int> should give int");
    static_assert(std::is_same_v<remove_reference_t<int const&>, int const>, 
    "remove_reference<int const&> should give int const");
    static_assert(std::is_same_v<remove_reference_t<int&&>, int>, "remove_reference<int&&> should give int");
}


int main() {
    test_add_pointer();
    test_remove_reference();
}