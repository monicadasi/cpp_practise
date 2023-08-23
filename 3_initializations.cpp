#include <iostream>
#include <typeinfo>

using namespace std;

// Uniform initialization
int main()
{
	int a1 ; // uninitialized
	int a2 = 0; // legacy type initialization
	
	int a3(5); // direct initialization

	auto b1 {2.555};

	auto b2 {5};

	cout << typeid(b2).name() << endl;
	
	std::string s1;
	auto s2 {"C++"};

	cout << s2 << endl;
	cout << typeid(s2).name() << endl;
}