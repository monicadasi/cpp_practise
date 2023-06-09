#include <iostream>
#include <typeinfo>

// auto : used for type deduction
// resource acquistion and initialization

class Base {};


int main()
{
    auto x = 20;
    auto y = 20.55f;
    auto z = 6.68796796;

    auto b = new Base();

    std::cout << typeid(x).name() << std::endl;
    std::cout << typeid(y).name() << std::endl;
    std::cout << typeid(z).name() << std::endl;
    std::cout << typeid(b).name() << std::endl;

    std::cout << sizeof(b) << std::endl;

    return 0;
}
