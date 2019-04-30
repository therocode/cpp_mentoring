/*

2. Function templates

*/

/*
In this part we'll explore how function templates work. We'll start where we left off in the previous part,
namely our not-so-great max() function. As said, templates are the way to solve this problem. You declare a 
templated function using the 'template' keyword:
*/

template<typename T>
/*
This tells the compiler to introduce a template parameter called 'T'. After this we put the actual function,
but we can use the type 'T' in this function as if it were any type.
*/
T max(T a, T b) {
    return b < a ? a : b;
}

/*
In this function. T could be anything. It might be int, float, double, long long, or even some custom class!
*/

void test_max() {
    int a = max<int>(2, 9);
    float b = max<float>(1.1, 1.4);

    // Note that by specifying the type T between the angled brackets, we explicitely tell the compiler 
    // what T should be for this call. You usually do not have to specify it, as for example in this case
    // the compiler can deduce what T should be by looking at the parameters passed in. There are a few rules
    // about how type deduction is performed, but we will not go into detail on those since it's a rather
    // complicated topic. Using template type deduction, we could just as well have written:
    a = max(2, 9);
    b = max(1.1f, 1.4f);
}

/*
Obviously, you can have more than one template type parameter. For example this function adds two types together
that might be of different type (but don't have to be)
*/

template<typename T, typename U>
T add(T a, U b) {
    return a + b;
}

/*
This function is not great though, because if T = int and U = long long, there might be some overflowing
issues when converting the result to a T (the return type). For this example though it's not important, as the 
main goal is to illustrate the basic syntax.
*/