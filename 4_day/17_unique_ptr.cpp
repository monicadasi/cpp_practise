#include <iostream>
#include <memory>

class Resource {
public:
    Resource() {
        std::cout << "Resource acquired." << std::endl;
    }

    ~Resource() {
        std::cout << "Resource released." << std::endl;
    }
};

class MyClass {
private:
    std::unique_ptr<Resource> mResource;

public:
    MyClass() : mResource(std::make_unique<Resource>()) {}

    // Move constructor
    MyClass(MyClass&& other) noexcept : mResource(std::move(other.mResource)) {
        std::cout << "Move constructor called." << std::endl;
    }

    // Move assignment operator
    MyClass& operator=(MyClass&& other) noexcept {
        if (this != &other) {
            mResource = std::move(other.mResource);
            std::cout << "Move assignment operator called." << std::endl;
        }
        return *this;
    }
};

int main() {
    MyClass obj1;
    MyClass obj2 = std::move(obj1);

    obj1 = std::move(obj2);

    return 0;
}
