#include <iostream>

class Base {
public:
    void baseFunction() {
        // Base class function
        std::cout << "base function" << std::endl;
    }
};

class Derived : public Base {
public:
    void derivedFunction() {
        // Derived class function
        std::cout << "derived function" << std::endl;
    }
};

int main() {
    // Derived dobj;
    // Base* bptr = &dobj; // Upcasting

    // bptr->baseFunction();

    Base bobj;
    Derived* dptr = static_cast<Derived*>(&bobj);

    dptr->baseFunction();
    return 0;
}
