// how to stop someone stealing the address of your object
// A1: Overload & operator and keep it private
// A2: delete * operator from your class

#include <iostream>
using namespace std;

class Base{
    int x;
public:
    Base(){}
    Base(int x): x{x} {}

    Base* operator & () = delete;
// private:
//     Base* operator & (){
//         cout << "calling from overload &" << endl;
//         return this;
//     }
};

int main(){
    Base b;
    // Base *bp = &b;
    // cout << &b << "\t" << bp << endl;
}