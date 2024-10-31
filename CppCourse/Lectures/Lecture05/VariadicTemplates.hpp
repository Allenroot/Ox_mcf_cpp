#ifndef _VARIADIC_TEMPLATE_EXAMPLE_
#define _VARIADIC_TEMPLATE_EXAMPLE_

#include <iostream>

template<typename... T> struct my_tuple {};

template<typename T>
struct my_tuple<T>
{
    T head;
    my_tuple(T const& arg) : head(arg) {}

    friend std::ostream & operator<<(std::ostream& os,
            const my_tuple<T>& arg)
    {
        return os << arg.head ;
    }
};

template<typename Head, typename... Tail>
struct my_tuple<Head,Tail...>
{
    Head head;
    my_tuple<Tail...> tail;

    my_tuple(const Head & head_arg, const Tail&... tail_arg)
    : head(head_arg), tail(tail_arg...) {}

    friend std::ostream & operator<<(std::ostream& os,
            const my_tuple<Head, Tail...>& arg)
    {
        return os << arg.head << ", " << arg.tail ;
    }
};

template<typename... T>
my_tuple<T...> make_my_tuple(const T&... arg)
{
    return my_tuple<T...>(arg...);
}


#endif //_VARIADIC_TEMPLATE_EXAMPLE_
