#include <iostream>
#include <string>

class MyClass {
private:
    std::string* data;

public:
    // Default constructor
    MyClass() : data(nullptr) {
        std::cout << "Default constructor called." << std::endl;
    }

    // Constructor
    MyClass(const std::string& str) : data(new std::string(str)) {
        std::cout << "Constructor called: " << *data << std::endl;
    }

    // Copy constructor
    MyClass(const MyClass& other) : data(new std::string(*other.data)) {
        std::cout << "Copy constructor called: " << *data << std::endl;
    }

    // Move constructor
    MyClass(MyClass&& other) noexcept : data(other.data) {
        other.data = nullptr;
        std::cout << "Move constructor called: " << *data << std::endl;
    }

    // Move assignment operator
    MyClass& operator=(MyClass&& other) noexcept {
        if (this != &other) {
            delete data;
            data = other.data;
            other.data = nullptr;
            std::cout << "Move assignment operator called: " << *data << std::endl;
        }
        return *this;
    }

    // Destructor
    ~MyClass() {
        if (data != nullptr) {
            std::cout << "Destructor called: " << *data << std::endl;
            delete data;
        }
    }
};

int main() {
    MyClass a("Hello");
    MyClass b(a); // Copy constructor

    MyClass c("World");
    b = std::move(c); // Move assignment operator

    return 0;
}