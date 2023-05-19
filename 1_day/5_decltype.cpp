// Question : Use of decltype
// It check the type of expression..

#include <iostream>
using namespace std;

template<typename T1, typename T2>
auto add(T1 a, T2 b) -> decltype(a+b) // Trailing return type (checks the expression)
{
    return a + b;
}

int main()
{
    cout << add(1 , 1.8) << endl;
    cout << add(1.8 , 1) << endl;
}