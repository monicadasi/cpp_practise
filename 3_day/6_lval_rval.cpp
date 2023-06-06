#include<iostream>

using namespace std;

void printValue(const int& value)
{
    cout << "[lvalue] -> " << value << endl;
}

// overload of the function that accepts temp objects(r-values)
void printValue(int&& value)
{
    cout << "[rvalue] -> " << value << endl;
}

int main()
{
    int i = 10;
    int j = 20;

    int k = i + j;
    printValue(k);
    printValue(i+j);
}