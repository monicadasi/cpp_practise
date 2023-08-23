#include <iostream>
#include <typeinfo>

using namespace std;

string isPalindrome(int i)
{
    auto x = 20.5l;
    cout << typeid(x).name() << endl;

    string s = "10101";
    if (s == string(s.rbegin(), s.rend()))
    {
        return "YES";
    }
    return "NO";
}

int main()
{
    auto i = 1001;
    cout << isPalindrome(i);
    return 0;
}
