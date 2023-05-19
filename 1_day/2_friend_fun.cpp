#include <iostream>

using namespace std;

// 1. Friend function fun() can access the public, protected and private members
// of Base class here. 
// 2. Could be used in test cases in testing framework.

class Base{
    int x;
public:
    Base() {} // default c'tor
    Base(int x): x{x} {} // parameterised c'tor

    friend void fun(Base&); // Class is telling that fun is friend of mine and can access my data.

};

void fun(Base& obj)
{
    cout << obj.x << endl;
    obj.x = 20;
    cout << obj.x << endl;
}

int main()
{
    Base b(10);
    fun(b);
    return 0;
}