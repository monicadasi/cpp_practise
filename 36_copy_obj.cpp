//Q. How to stop someone copying your object
// 1. Keep the copy constructor and assignment operator private'
// 2. Inherit dummy class with private copy c'tor and assignment operator
// 3. Delete the copy c'tor and assignment operator from your class


#include <iostream>
using namespace std;
// // first approach
// class Base{
//     int _x;
// public:
//     Base(){}
//     Base(int x): _x{x} {
//         cout << "Implicit Constructor Called" << endl;
//     }
// private:
//     Base(const Base& obj): _x{obj._x}{}
//     Base& operator=(const Base& rhs) 
//     { 
//         _x = rhs._x;
//          return *this;
//     }
// };

// third approach
// first approach
class Base{
    int _x;
public:
    Base(){}
    Base(int x): _x{x} {
        cout << "Implicit Constructor Called" << endl;
    }
    Base(const Base& obj) = delete;
    Base& operator=(const Base& rhs) = delete;
};

int main(){
    Base b1(10);
    Base b2(20);

    // Base b3;
    // b3 = b2; // error due private c'tor

    return 0;
}