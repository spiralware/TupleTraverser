#include <iostream>
#include <tuple>

//  ============================================================

class student
{
    std::string name = "John";
    int age = 25;
    double average_score = 9.2;

    friend std::ostream& operator<<(std::ostream& , const student& );
};

std::ostream& operator<<(std::ostream& os, const student& st)
{
    os << "Student {\n"
    << "\"name\": " << st.name << ",\n"
    << "\"age\": " << st.age << ",\n"
    << "\"average_score\": " << st.average_score << "\n"
    << "}";
    return os;
}

//  ============================================================

template<size_t I>
class print_tuple_t
{
public:
    template<typename ... Types>
    static void print(std::ostream& os, const std::tuple<Types...>& tup)
    {
        print_tuple_t<I - 1>::print(os, tup);
        os << std::get<I>(tup) << std::endl;
    }
};

template<>
class print_tuple_t<0>
{
public:
    template<typename ... Types>
    static void print(std::ostream& os, const std::tuple<Types...>& tup)
    {
        os << std::get<0>(tup) << std::endl;
    }
};

//  ============================================================

template<typename ... Types>
void tuple_to_ostream(std::ostream& os, const std::tuple<Types...>& tup)
{
    using namespace std;
    constexpr size_t tup_size = tuple_size<tuple<Types...>>::value;
    print_tuple_t<tup_size - 1>::print(os, tup);
}

//  ============================================================

int main()
{
    auto tup_one_elem = std::make_tuple(42);
    tuple_to_ostream(std::cout, tup_one_elem);
    std::cout << "\n";

    auto tup_built_in_types = std::make_tuple(42, 42.42, "42", true);
    tuple_to_ostream(std::cout, tup_built_in_types);
    std::cout << "\n";

    student st;
    auto tup_user_types = std::make_tuple(std::string("yeah"), st);
    tuple_to_ostream(std::cout, tup_user_types);
    std::cout << "\n";

    return 0;
}
