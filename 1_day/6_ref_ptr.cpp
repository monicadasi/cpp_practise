// Pointer and Reference

#include <iostream>
using namespace std;

int main()
{
    int i = 10;
    int &r = i;  // reference -> r refers to the addr of i, type bound
    int *ptr = &i; // pointer

    cout << &i << '\t' << &r << '\t' << ptr << endl;

    int var = 20;
    r = var;

    cout << "i value after assignment : " << i << endl;
    ptr = &var;

    cout << "Addr held by ptr : " << ptr << '\t' << "Adrr of ptr : " << &ptr << endl;
    *ptr = 35;
    cout << "Print var now : " << var << endl;

    int **p = &ptr; // Stores the address of the ptr
    int ***p1 = &p; // Stores the address of the p

    ***p1 = 100;
    cout << p << '\t' << p1 << endl;
    cout << "Var should be 100 now : " << var << endl;

    return 0;
}

// 1. Memory address
// 2. Reassignment of memory address is not possible with reference unlike pointer
// 3. NULL Value (Ptr cannot initialized to NULL, whereas the reference has to have valid address to hold)
// 4. Arithmetic Operations (Ptr can incremented which referes to next addr memory location)
// 5. Indirection