/*

1. Why do we need templates?

*/

/*
We'll dive right in with an example. Suppose I have a function that finds the largest number between 
two numbers. It might look like this:
*/

int max(int a, int b) {
    return b < a ? a : b;
}

/*
This is all fine, until we want to find the largest number between two long long's. We need a new function:
*/

long long max(long long a, long long b) {
    return b < a ? a : b;
}

/*
You could be smart here and remove the first overload, since this max() function will also work for 
plain ints. However the problem is still not solved. What if we want to find the largest number between
two floats? We'll have to define another new function:
*/

float max(float a, float b) {
    return b < a ? a : b;
}

/*
As you probably noticed, all functions from above have the exact same implementation. The only thing
that differs is the return type and parameter types. You obviously don't want to rewrite the function dozens
of times for each combination of parameters. This is where templates come in to save the day.
*/