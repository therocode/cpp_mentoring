/*

7. [BONUS] Type traits and variadic templates

*/

/*
A TMP Lesson would obviously be nothing without variadic templates. In this bonus lesson, we will see how
type traits work with variadic templates. The main problem here will be iterating over template parameter packs.

We will dive right in with an example: in_pack<T, Ts...>
*/

#include <type_traits>

template<typename T, typename... Ts>
struct in_pack;

template<typename T, typename U>
struct in_pack<T, U> {
    static constexpr bool value = std::is_same_v<T, U>;
};

template<typename T, typename Head, typename Next, typename... Tail>
struct in_pack<T, Head, Next, Tail...>
{
    static constexpr bool value = std::is_same_v<T, Head> || in_pack<T, Next, Tail...>::value;
};

/*
Now this requires some explanation. First we declare the base struct, so we can specialize on that.
Then, we make a partial specialization for the case in which we have only two elements left. In this case, we 
do not need to iterate more. The last case is the case in which the pack has 2 or more elements left (Head, Next, 
and possibly Tail...). In this case, we first test if the element that has to be tested is the same as the Head
element. We use the logical or operator to chain this operation together with the same operation on the pack, but 
without the Head element. This way the pack keeps getting smaller and we effectively iterate over the pack.
*/

void test_in_pack() {
    static_assert(in_pack<int, int, float, double>::value);
    static_assert(in_pack<int, double, char, float, int, long double>::value);
    static_assert(in_pack<int, int>::value);
    static_assert(in_pack<int, float, double, long long, char>::value == false);
}

/*
This is the basic technique to iterate over a template parameter pack.
*/

int main() {
    test_in_pack();
}