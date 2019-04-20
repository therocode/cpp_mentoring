/*

4. Applications of type traits

*/

/*
We have learned how to create two types of type traits. But what is all this useful for? Type traits are 
used a lot in generic programming. Say we have a function calculating the length of a string:
*/

#include <cstddef>

template<typename CharT>
std::size_t my_strlen(CharT const* str) {
    std::size_t len = 0;
    while(*str++ != '\0') {
        ++len;
    }
    return len;
}

/*
Here, we have a problem. What if the character is a wchar_t? What if it is a char32_t? What if it is some custom 
character type? The problem is that we are comparing a character of unknown character type to '\0', which is a
char. To fix this, we use a char_traits class which defines what the null terminator looks like:
*/

template<typename CharT>
struct char_traits;

template<>
struct char_traits<char> {
    static constexpr char null = '\0';
};

template<>
struct char_traits<wchar_t> {
    static constexpr wchar_t null = L'\0';
};

template<typename CharT>
std::size_t my_strlen2(CharT const* str) {
    std::size_t len = 0;
    while(*str++ != char_traits<CharT>::null) {
        ++len;
    }
    return len;
}

/*
Now, we can use this char_traits class to make sure that the correct null terminator is chosen.
If the user wants a special character type to work with this function, all he has to do is specialize char_traits
for this character type and it will work.

Note: This is also how std::string handles characters of different types.
*/

#include <iostream>

void test_my_strlen() {
    std::cout << my_strlen("Hello") << "\n";
    std::cout << my_strlen(L"Hello Wstring");
}

/*
Now this was an application of "value type traits". Let's take a look at an example of where you can use
a "typedef type trait." Suppose you have a function that takes a container and does something with it.
*/

template<typename C>
void f(C& container) {
    /*
    Now in this function, we want to somehow use an iterator pointing to an element in this container. 
    We could obviously write:
    */
    typename C::iterator it = container.begin();
    /*
    But if the user passes in an array, or some container that has another name for iterator, it will fail
    to compile. To fix this problem, we use a type trait that determines the underlying iterator of a container.
    */
}

template<typename C>
struct underlying_iterator {
    using type = typename C::iterator;
};

template<typename T, std::size_t N>
struct underlying_iterator<T[N]> { // partial specialization for arrays
    using type = T*; // a raw pointer to the element type is the iterator for an array
};

/*Now, we can rewrite f() as follows:*/
template<typename C>
void new_f(C& c) {
    typename underlying_iterator<C>::type it = std::begin(c); // Note that we use std::begin() to support arrays
}

int main() {
    test_my_strlen();
    int arr[5] {0, 1, 2, 3, 4};
    new_f(arr);
}