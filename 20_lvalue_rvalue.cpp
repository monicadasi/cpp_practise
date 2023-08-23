#include <iostream>

int getValue() {
    return 42;
}

int main() {
    int a = 5;  // 'a' is an lvalue
    int b = 10; // 'b' is an lvalue

    int sum = a + b; // 'a + b' is an rvalue representing the temporary sum

    int& ref = a; // 'ref' is a reference to an lvalue 'a'
    ref = 35;

    int&& rref = a + b; // 'a + b' is an rvalue reference to the temporary sum

    int c = getValue(); // 'getValue()' returns an rvalue

    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Reference: " << ref << std::endl;
    std::cout << "Rvalue Reference: " << rref << std::endl;
    std::cout << "Value: " << c << std::endl;

    return 0;
}
