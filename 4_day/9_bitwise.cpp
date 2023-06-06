// Q: How to set, clear, toggle, check, change a single bit in C++

#include <iostream>
using namespace std;

int main()
{
    int num = 3; 
    
    // Set one bit [USe of Bitwise OR operator]
    int bitPos = 2;  // 0011 set the 3rd bit to 1 -> 0111
    num |= (1<<bitPos);
    cout << num << endl;

    // left shit and OR with 0011
    // 0100 | 0011 --> 0111

    num = 3; // re-assign to 3
    // Unset one bit [Use of Bitwise AND operator]
    bitPos = 1;  // 0011 unset the 1st bit to 0 -> 0001
    num &= ~(1<<bitPos);
    cout << num << endl;

    // 0010 negation -> 1101
    // 1101 & 0011 -> 0001

    // Toggle if 0 we make it 1 , if it is 1 we toggle to 0
    num = 3; // re-assign to 3
    // Unset one bit [Use of Bitwise XOR operator]
    bitPos = 0;  // 0011 unset the 1st bit to 0 -> 0001
    num ^= (1<<bitPos);
    cout << num << endl;

    // 0011  -> number
    // 0001  -> left shift with bitpos : 0
    //  0011 XOR 0001 -> 0010


    // Check the bit value at certain position
    num = 3; //0011
    // checking the bit value at a position
    bitPos = 1;

    int bit = (num >> bitPos) & 1;
    cout << bit << endl;

    // 0011 
    // Right shit with 1 -> 0001
    // AND with 1        -> 0001
    

    // Set the bit value at certain position with the given bit value
    num = 3; //0011
    // bit position to change
    int n = 3;
    // change the bit value to 1
    int bitVal = 1;
    num = num & ~(1 << n) | (bitVal << n);
    cout << num << endl;

    // 0011 & ~(1000) -> 0111 = 0011
    // 0001 << 3 -> 1000 = 1011

    return 0;
}