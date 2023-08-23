#include <iostream>
#include <string>

class MyString {
private:
    std::string* data;

public:
    MyString(const std::string& str) : data(new std::string(str)) {
        std::cout << "Constructor called: " << *data << std::endl;
    }

    // Move constructor
    MyString(MyString&& other) noexcept : data(other.data) {
        other.data = nullptr;
        std::cout << "Move constructor called: " << *data << std::endl;
    }

    ~MyString() {
        if (data != nullptr) {
            std::cout << "Destructor called: " << *data << std::endl;
            delete data;
        }
    }
};

int main() {
    std::string str = "Hello, World!";
    MyString a(str); // Constructor called

    MyString b(std::move(a)); // Move constructor called
    // a.data is now nullptr, and b.data is "Hello, World!"

    return 0;
}