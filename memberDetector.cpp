#include <iostream>

class IHaveAField
{
public:
    int field;  
};

class IDont
{
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
    std::cout << std::boolalpha << hasIt<IHaveAField>::value << "\n";
    std::cout << std::boolalpha << hasIt<IDont>::value << "\n";
}
