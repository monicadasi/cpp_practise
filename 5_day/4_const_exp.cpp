#include<iostream>

int main()
{
    float i =  20.5;
    decltype(i) j = 45;

    std::cout << typeid(j).name() << "\t" << j << std::endl;
    return 0;
}