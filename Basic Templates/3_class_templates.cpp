/*

3. Class templates

*/

/*
Functions are not the only things that can be templated. Classes and structs can be templates as well, 
for example:
*/

template<typename T>
struct value_holder {
    T value;
};

/*
This is a very basic templated struct. It just holds a value of a type T. We can use it for example like:
*/

#include <string>

void test_value_holder() {
    value_holder<int> vh {5};
    value_holder<std::string> string_holder {"Hello World"};
}

/*
This syntax might look very familiar if you have ever worked with standard library classes like std::vector. 
Creating a new vector looks a bit like this: std::vector<int> v {1, 2, 3, 4, 5}; And now we know where this weird
<int> syntax comes from! A very simplified vector class looks like this:
*/

template<typename T>
class vector {
public:
    // etc
private:
    T* data;
    std::size_t size;
};

/*
Class templates are extremely useful for creating classes that operate on different types, for example
container classes.
*/