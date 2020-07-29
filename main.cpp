#include <iostream>
#include <tuple>
#include <typeinfo>

class student {
    int age = 25;
    double score = 9.;

    friend std::ostream& operator<<(std::ostream& , const student& );
};

std::ostream& operator<<(std::ostream& o, const student& st)
{
    o << "age = " << st.age << "; score = " << st.score;
    return o;
}

template<typename ... T>
class tuple_printer
{

};

template<size_t N, typename ... Args>
class TupleElemGetter
{
    void print() {std::cout << N << " ";}
    
};

template<typename ... Args>
class TupleElemGetter<0, Args...>
{
    void print() {std::cout << 0;}
};

template<typename... Types>
void tuple_to_ostream(std::ostream& os, const std::tuple<Types...>& tup)
{
}

/* template<typename T>
void tuple_to_ostream(const std::tuple<T>& one_elem_tup)  //  probably universal ref?
{
    std::cout << std::get<0>(one_elem_tup);
} */

int main()
{
    std::cout << "EMINEM" << std::endl;
    student st;
    auto tup = std::make_tuple(1, 3.14, "mystring", st);
    std::size_t sz = std::tuple_size<decltype(tup)>::value;
    
    for (int i = 0; i < sz; ++i)
    {
        //std::cout << std::get<i>(tup);
    }
    
    //  ============================================================

    auto one_elem_tup = std::make_tuple(42);
    //tuple_to_ostream(one_elem_tup);

    return 0;
}
