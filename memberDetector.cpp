//Simple trick to know at compile time if a class has a certain member or not

#include <iostream>

class Test
{
public:
    int field;  
};

template<typename T, typename = int>
struct hasIt : std::false_type
{
};

template<typename T>
struct hasIt<T, decltype(T::field)> : std::true_type
{
};


int main()
{
    std::cout << std::boolalpha << hasIt<Test>::value;
}
