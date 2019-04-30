/*

5. Template specialization

*/

/*
The last new concept we are going to look at is template specialization. In this lesson, we'll only look at 
full template specialization, but keep somwhere in the back of your head that partial specialization exists as
well.

As an example, suppose we have a templated function that tests if two numbers are equal:
*/

template<typename T>
bool equal(T a, T b) {
    return a == b;
}

/*
This function works fine for most types, but if we pass in floating point values we might get wrong results due
to floating point precision errors. So what we want to do is keep this function, but create a different version
for floats. We do this by specializing the function. Doing so looks like this:
*/

#include <cmath> // for std::abs()

template<> // No template arguments introduced here, so empty <>. The reason it still has to be present is to
           // tell the compiler that the function is a template
bool equal<float>(float a, float b) { // With the <float> we tell the compiler that this is a specialization 
                                      // of equal for floats
    float epsilon = 0.001;
    return std::abs(a - b) < epsilon;
}

void test_equal() {
    // If we now call equal with any type, it will call the first function except when we pass in a float, 
    // in which case the compiler will choose the second version:
    equal(2, 8); // Calls first version of equal()
    equal(1.2f, 1.2f); // Calls second version of equal()
    equal<double>(1.2, 1.8); // Calls first version, since it's a double and not a float.
}

// Of course, you can also specialize class templates.