#include <iostream>

using namespace std;


class Resource{

    int *data;

public:
    Resource(): data(nullptr){
        cout << "default c'tor" << endl;
    }

    // paramter c'tor
    Resource(int val): data(new int(val)){
        cout << "parameter c'tor called" << endl;
    }

    // copy c'tor
    Resource (const Resource& other){
        cout << "copy c'tor called" << endl;
        data = new int(*other.data);
    }

    // copy assignment operator
    Resource& operator=(const Resource& other){
        cout << "copy assignment operator called" << endl;
        if(this != &other){
            delete data; // possible memory leak if not done
            data = new int(*other.data);
        }
        return *this;
    }

    // move c'tor
    Resource(Resource&& other) noexcept {
        cout << "move c'tor called" << endl;
        data = other.data;
        other.data = nullptr;
    }

    // move assignment operator
    Resource& operator=(Resource&& other) noexcept {
        if(this != &other)
        {
             cout << "move assignment operator called" << endl;
            delete data;
            data = other.data;
            other.data = nullptr;
        }
        return *this;
    }

    ~Resource()
    {
        cout << "d'tor called" << endl;
        delete data;
    }
};


int main(){
    Resource ob1(20); // param c'tor
    Resource ob2(ob1); // copy c'tor
    Resource ob3; // default c'tor
    ob3 = ob1;  // copy assignment

    Resource ob4(std::move(ob3)); // move c'tor
    Resource ob5;
    ob5 = std::move(ob4); // move assignment operator

    return 0;
}