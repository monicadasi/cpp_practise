#include<iostream>
#include <limits>
using namespace std;

int main()
{

int a=1;
int b = a++;
int c = ++a;

cout << "b :" << b << " , c :" << c << endl;
cout<<(b)*(c)<<endl;

cout << ::numeric_limits<size_t>::max() << endl;
return 0;
}