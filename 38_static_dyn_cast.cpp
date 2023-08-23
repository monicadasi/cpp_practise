#include <iostream>
using namespace std;

// // Dont use static_cast for private base
// class Base{
// };

// class Derived: private Base {};


// int main(){
//     Derived d1;
//     Base *bp1 = (Base*) &d1; // allowed at compile time C-style casting
//    // Base *bp2 = static_cast<Base*> (&d1); // Not allowed at compile time , if base is public this works
// }

// USe for all up-casts, but never use for ambiguous down cast.
class Base{};
class Derived1: public Base {};
class Derived2: public Base{};

int main()
{
    Derived1 d1;
    Derived2 d2;

    Base *bp1 = static_cast<Base*> (&d1); // up_cast
    Base *bp2 = static_cast<Base*> (&d2); // up_cast

    Derived1 *dp1 = static_cast<Derived1*> (bp2); // wrong down cast
    Derived2 *dp2 = static_cast<Derived2*> (bp1); // wrong down cast

    return 0;
}