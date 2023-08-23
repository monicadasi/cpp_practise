#include <iostream>

class Base {
public:
    virtual void print() {
        std::cout << "Base class" << std::endl;
    }
};

class Derived : public Base {
public:
    void print() override {
        std::cout << "Derived class" << std::endl;
    }
};

int main() {
    // Dynamic Casting
    Base* basePtr = new Derived();
    Derived* derivedPtr = dynamic_cast<Derived*>(basePtr);
    if (derivedPtr) {
        derivedPtr->print();  // Output: Derived class
    }

    // Static Casting
    Derived* derivedPtr2 = new Derived();
    Base* basePtr2 = static_cast<Base*>(derivedPtr2);
    basePtr2->print();  // Output: Derived class

    return 0;
}

// In this example, we have a base class Base and a derived class Derived. 
// The print() function is overridden in the derived class.

// Dynamic Casting: We create a pointer basePtr of type Base* and assign it a dynamically allocated object of type Derived. 
// Then, we use dynamic casting dynamic_cast<Derived*>(basePtr) to attempt to cast basePtr to a pointer of type Derived*. 
// Since the actual object is of type Derived, the dynamic cast is successful, and derivedPtr is not a null pointer. 
// We then call the print() function using derivedPtr, which outputs "Derived class".

// Static Casting: We create a pointer derivedPtr2 of type Derived* and allocate an object of type Derived. 
// We then create a pointer basePtr2 of type Base* and assign it the result of a static cast static_cast<Base*>(derivedPtr2). 
// In this case, the static cast is valid because Derived is derived from Base. 
// We call the print() function using basePtr2, which outputs "Derived class".

// Note that dynamic casting is used when the cast involves polymorphic types (classes with virtual functions), 
// and it performs runtime type checking. On the other hand, static casting is used for non-polymorphic types and 
// performs type conversions without runtime checks.
