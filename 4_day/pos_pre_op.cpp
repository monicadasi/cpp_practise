#include <iostream>

using namespace std;

int main()
{
    int i, k {};
    int j = 1;

    i = j++;
    k = ++j;
    cout << "value of i : " << i << "\t" << "value of j : "  << k << endl;
    return 0;
}