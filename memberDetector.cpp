#include <iostream>
#include <type_traits>

class IHaveAField
{
public:
    int field;  
};

class IDont
{
};

template<typename T, typename = void>
struct hasIt : std::false_type
{
};

template<typename T>
struct hasIt<T, std::void_t<decltype(T::field)> > : std::true_type
{
};


int main()
{
    std::cout << std::boolalpha << hasIt<IHaveAField>::value << "\n";
    std::cout << std::boolalpha << hasIt<IDont>::value << "\n";
}
