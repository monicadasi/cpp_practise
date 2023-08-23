#include <iostream>
using namespace std;
class Base{
public:
virtual void print()
{
    cout << "Base Class Print" << endl;
}
};

class Derived : public Base{
public:
void print() override{
    cout << "Print in Derived" << endl;
}
};

int main()
{
    Base* bptr = new Derived();
    Derived* dptr = dynamic_cast<Derived*>(bptr);
    cout << typeid(dptr).name() << endl;
    return 0;
}