/*

1. What is a type trait?

*/

/*
A type trait is essentially a class that does an operation on types. I like to distinguish between two 
categories of type traits. There are "value type traits" that give you a value based on one or more types
passed in, and there are "typedef type traits", which return another type.

In the STL, an example of such a "value type trait" is for example std::is_same<T, U>. A "typedef type trait"
found in the STL is for example std::remove_reference<T>
*/