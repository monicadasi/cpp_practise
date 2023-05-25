#include <iostream>
using namespace std;

class Base{
public:
    Base(){
        cout << "base c'tor" << endl;
    }

    ~Base(){
        cout << "base d'tor" << endl;
    }

    virtual void foo()
    {
        cout << "foo in base" << endl;
    }
};

class Derived : public Base{
public:
    Derived(){
        cout << "derived c'tor" << endl;
        //Base* b = new Base();
        Base* b;
        b = this;
        b->foo();
    }

    ~Derived(){
        cout << "derived d'tor" << endl;
    }

    void foo(){
        cout << "foo in derived" << endl;
    }
};


int main()
{
   Base *b = new Derived();
   b->foo();
   return 0;
}