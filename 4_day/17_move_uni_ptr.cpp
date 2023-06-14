#include <iostream>
#include <memory>

class Resource {
public:
    Resource() {
        std::cout << "Resource acquired!" << std::endl;
    }

    ~Resource() {
        std::cout << "Resource released!" << std::endl;
    }

    // Move constructor
    Resource(Resource&& other) noexcept {
        std::cout << "Move constructor called!" << std::endl;
    }

    // Move assignment operator
    Resource& operator=(Resource&& other) noexcept {
        std::cout << "Move assignment operator called!" << std::endl;
        return *this;
    }
};

int main() {
    // Create a unique pointer and transfer ownership using move semantics
    std::unique_ptr<Resource> ptr1 = std::make_unique<Resource>();
    //std::unique_ptr<Resource> ptr1(new Resource());
    std::unique_ptr<Resource> ptr2 = std::move(ptr1);

    // Use move assignment operator to transfer ownership
    std::unique_ptr<Resource> ptr3;
    ptr3 = std::move(ptr2);

    return 0;
}
