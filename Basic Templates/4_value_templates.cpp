/*

4. Non type templates

*/

/*
Another nice thing about templates is that you can also pas in values instead of types. This might not seem
very useful at this moment, but it's useful for doing compile time stuff. Note that you can only pass in integral
values as non type templates in C++17. Maybe the standard will add support for floating point types and custom
classes later, but until then it's integral types only. Example:
*/

#include <cstddef>

template<typename T, std::size_t N>
struct array {
    T data[N];
};

// Note that N must always be known at compile time, so the array above is not a VLA.