#include <iostream>

class Base {
public:
    void greet() {
        std::cout << "Hello from Base" << std::endl;
    }
};

class DerivedA : public Base {
public:
    void greet() {
        std::cout << "Hello from DerivedA" << std::endl;
    }
};

class DerivedB : public Base {
public:
    void greet() {
        std::cout << "Hello from DerivedB" << std::endl;
    }
};

class Diamond : public DerivedA, public DerivedB {
public:
    void greet(){
        DerivedB::greet();
    }
};

int main() {
    Diamond diamond;
    diamond.greet();  // Error: ambiguous function call

    return 0;
}
