#include <iostream>


using namespace std;


int main()
{
    char buff[512];

    cout << "Enter your name : " << endl;
    // cin >> buff;
	cin.getline(buff, 64, '\n');
    cout << "Given Name :" << buff << endl;

    return 0;
}
