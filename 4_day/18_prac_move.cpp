#include <iostream>
#include <vector>

class MyClass {
private:
    int* data;

public:
    MyClass(int value) : data(new int(value)) {
        std::cout << "Constructor" << std::endl;
    }

    // Copy constructor
    MyClass(const MyClass& other) : data(new int(*other.data)) {
        std::cout << "Copy constructor" << std::endl;
    }

    // Move constructor
    MyClass(MyClass&& other) noexcept : data(other.data) {
        other.data = nullptr;
        std::cout << "Move constructor" << std::endl;
    }

    ~MyClass() {
        delete data;
        std::cout << "Destructor" << std::endl;
    }
};

int main() {
    MyClass obj1(42);

    // Move constructor is called implicitly here
    MyClass obj2 = std::move(obj1);

    return 0;
}
