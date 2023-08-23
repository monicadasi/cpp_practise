// Explicit constructor in C++
// Use of explicit keyword -> Avoids implicit call to the c'tor.

#include<iostream>
using namespace std;

class Base{
 int b_var;
public:
    Base() {}
    // Base(int var): b_var{var} {}
    explicit Base(int var): b_var{var} {}

    void print() {
        cout << b_var << endl;
    }
};

void fun(Base b){
    b.print();
}

int main()
{
    Base obj1(10); // Normal call to c'tor
   // Base obj2= 20; // Implicit call to c'tor , to avoid creating such class instances explicit is used
    Base obj2(20); // call to c'tor

    fun(obj1);

    return 0;
}