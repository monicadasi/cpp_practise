/* Syntax : dynamic_cast < new_type> (expression)
 * Used at the run-time to find out the right down-cast type
 * Note: Atlest one virtual function should be present in the base class.
 * 1. Cast is successful, returns the value of new_type.
 * 2. Cast fails, returns a NULL ptr of the new_type.
 * 3. Cast fails and new_type is a reference type, throws a exception
 */

#include <iostream>
using namespace std;

class Base{
    virtual void print()
    {
        cout << "Base" << endl;
    }
};

class Derived1: public Base{
    void print()
    {
        cout << "Derived1" << endl;
    }
};

class Derived2: public Base{
    void print()
    {
        cout << "Derived2" << endl;
    }
};

int main(){
    Derived1 d1;

    Base *bp = dynamic_cast<Base*>(&d1);
    Derived1 *dp2 = dynamic_cast<Derived1*>(bp);

    if (dp2 == nullptr){
        cout << "NULL ptr" << endl;
    }
    else{
        cout << "NOT NULL" << endl;
    }

    try
    {
        Derived2 &r1 = dynamic_cast<Derived2&> (d1);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

    return 0;
}

// 1. Works only on polymorphic base class (atleast one virtual function in base class), uses this info to decide on wrong down_cast
// 2. Used for up-cast (D->B) and down-cast (D->B), but mainly used for correct down-cast type.
// 3. Has run-time overhead as it check the object type at run time using RTTI (Run Time Type Information).
