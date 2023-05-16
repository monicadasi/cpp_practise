#include <iostream>
#include <typeinfo>

using namespace std;

string isPalindrome()
{

    string s = "10101";
    if (s == string(s.rbegin(), s.rend()))
    {
        return "YES";
    }
    return "NO";
}

int main()
{
    cout << isPalindrome();
    return 0;
}
