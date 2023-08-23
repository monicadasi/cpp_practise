# include <iostream>

class Resource {
private:
    int * data;
public:
// Default constructor
Resource() : data(nullptr) {
    std::cout << "Default constructor" << std::endl; 
}

// Constructor
Resource(int value) : data(new int(value)) { 
    std::cout << "Constructor" << std::endl; 
}

// Destructor
~ Resource() {
    delete data; 
    std::cout << "Destructor" << std::endl; 
}

// Copy constructor
Resource(const Resource& other) : data(new int (*other.data)) 
{ 
    std::cout << "Copy constructor" << std::endl; 
}

// Copy assignment operator
Resource& operator =( const Resource& other) 
{
 if(this != &other) {
    delete data;
    data = new int (*other.data);
    }   
    std::cout << "Copy assignment operator" << std::endl;
    return * this;
}

// Move constructor
Resource (Resource&& other) noexcept : data (other.data) { 
    other.data = nullptr; 
    std::cout << "Move constructor" << std::endl; 
}

// Move assignment operator
Resource& operator=(Resource&& other) noexcept{
    if(this != &other) {
    delete data;
    data = other.data; 
    other.data = nullptr; 
    } 
    std::cout << "Move assignment operator" << std::endl;
    return *this; 
}
};

int main()
{
    // Creating objects
    Resource obj1 (42);
    Resource obj2(obj1); // copy c'tor
    Resource obj3;
    obj3 = obj2; // copy assignment operator

    Resource obj4(std::move(obj3)); // move c'tor
    Resource obj5;

    obj5 = std::move(obj4); // move assignment operator

    return 0;
}