/*

2. Creating a "value type trait"

*/

/*
As an example of a "value type trait", we will start by implementing std::is_same as an example.
We want to be able to do the following:

static_assert(is_same<int, float>::value == false, "Int and float should be distinct types");
static_assert(is_same<double, double>::value, "Double and double should be the same");

*/

/*
Type traits like this are usually implemented by making a partial specialization for the case in which
the condition is true. We will first define the base case:
*/

template<typename T, typename U>
struct is_same {
    static constexpr bool value = false;
};

/*
Now we want to make a partial specialization for this struct in which value is true. We do this as follows:
*/

template<typename T>
struct is_same<T, T> {
    static constexpr bool value = true;
};

/*
If T and U are the same, the above specialization is a better match, so the compiler will choose to instantiate
this one instead.
*/

void test_is_same() {
    // With the above is_same implementation, the following compiles.
    static_assert(is_same<int, float>::value == false, "Int and float should be distinct types");
    static_assert(is_same<double, double>::value, "Double and double should be the same");
}

/*
We will create one more "value type trait" as an example here. The trait we are going to implement is
std::is_reference<T>. This trait checks if a type is either an rvalue reference or an lvalue reference.
*/

template<typename T>
struct is_reference {
    static constexpr bool value = false;
};

/*
Again, this is the base case of our type trait. If no better match is found, we can assume that the type is not
a reference type.
*/

template<typename T>
struct is_reference<T&> {
    static constexpr bool value = true;
};

/*
With this specialization we tell the compiler the following:
'If the type the user passed in is a reference (e.g. there is a type T so that T& is the same as what the user
supplied), choose this specialization instead.'
Obviously we have to do the same for rvalue references:
*/

template<typename T>
struct is_reference<T&&> {
    static constexpr bool value = true;
};

void test_is_reference() {
    static_assert(is_reference<int>::value == false, "int is should not be a reference");
    static_assert(is_reference<int&>::value == true, "int& should be a reference");
    static_assert(is_reference<int&&>::value == true, "int&& should be a reference");
}

/*
As you can see, having to type ::value everywhere can make your code very bloat. This is why usually
you provide the following:
*/

template<typename T>
static constexpr bool is_reference_v = is_reference<T>::value;

/*
Yes, this is a templated variable.
*/

int main() {
    test_is_same();
    test_is_reference();
}