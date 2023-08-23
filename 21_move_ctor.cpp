// a move constructor is a special member function of a class that allows efficient transfer of ownership 
// and resources from one object to another. It is used when initializing a new object from an existing 
// object of the same type, typically an rvalue. The move constructor is denoted by using the double ampersand (&&) after the type name.
#include<iostream>
using namespace std;

class MyVector{
private:
    int size;
    int* data;

public:
    MyVector(int sz): size(sz), data(new int[size]){
        cout << "C'tor called - size :" << size << endl;
    }

    ~MyVector(){
        delete[] data;
        cout << "D'tor called - size : " << size << endl;
    }

    // copy c'tor
    MyVector(const MyVector& vobj): size(vobj.size), data(new int[size]){
        cout << "Copy C'tor called - size : " << size << endl;
        for(int i = 0; i < size; i++){
            data[i] = vobj.data[i];
        }
    }

    // Move c'tor
    MyVector(MyVector&& obj) noexcept: size(obj.size), data(obj.data){
        cout << "Move C'tor called - size : " << size << endl;
        obj.data = nullptr;
        obj.size = 0;
    }
};


int main() {

    MyVector v1(5); // Construct v1 using the regular constructor

    MyVector v2 = v1; // Copy constructor called - v2 is a copy of v1

    MyVector v3 = MyVector(10); // Move constructor called - v3 is constructed by moving the temporary object

   // MyVector v3 = std::move(v2);

    return 0;
}
