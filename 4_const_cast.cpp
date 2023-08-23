// const_cast<T> (v) can be used to change the const or volatile qualifiers of ptrs or references.
// Where, T must be a pointer, reference, or pointer-to-member type.

#include <iostream>

// 1. When the actual reference object/reference is not const.
// int main()
// {
//     int a1 {10};
//     const int *b1 {&a1};

//     ::std::cout << b1 << ::std::endl << *b1 << ::std::endl;

//     int *d1 = const_cast<int*>(b1);
//     *d1 = 20;
//     ::std::cout << d1 << std::endl;

//     ::std::cout << "After modification : " << a1 << ::std::endl;

//     return 0;
// }

// 2. When we need to use some 3rd party library where it is taking the variable/object as non-const but not changing that.

void thirdPartyLib(int* x)
{
    int k = 15;
    ::std::cout << k + (*x) << ::std::endl;
}

int main()
{
    const int x1 {10};
    const int *px1 {&x1};

    thirdPartyLib(const_cast<int*>(px1)); // 3rd party lib is taking non-const hence using const int cast with remove the constness of int ptr.
    return 0;
}