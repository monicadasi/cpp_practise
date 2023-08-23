#include<iostream>
using namespace std;

int main()
{
    const char* cp = "Hello World!"; // points to the first element in the string , behaves like an array
    cout << *cp << endl;

    char arr[] = "Hello World";
    const char *cp1 = arr;
    const char *cp2 = &arr[0];

    cout << "cp1 : " << *cp1 << "\t cp2 : " << *cp2 << endl;

}