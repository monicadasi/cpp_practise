#include <iostream>

int main()
{
	using namespace std;
    int x = 10;
    
    cout << &x << endl;
    
    int *ptr = &x;
    
    cout << ptr << endl; // contains the address of x
    
    *ptr = 5; // assign the address of 5 to x
    
    int y = *ptr; // read the value from the address of x
    
    cout << y << endl;
    
    return 0;
}
