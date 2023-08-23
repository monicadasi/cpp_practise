#include <iostream>
#include <functional>
using namespace std;

int main()
{
    [](){}; // anonymous function - lambda function
    int res = [] (int a, int b) -> int
    {
        return a + b;
    }(10, 5);

    cout << "sum of 10 and 5 is " << res << endl;


    // traditional way of implementing using function pointers
    int (*fptr) (int, int);

    fptr = [](int a, int b) {
        return a+b;
    };

    cout << "calling with fptr sum of 11 and 9 is " << fptr(11, 9) << endl;

    // Function ptr using function  after C++11
    std::function<int(int, int)> f;

    f = [](int a, int b){
        return a + b;
    };
    cout << "printing using function : " << f(3,5) << endl;

    int x = 10;
    int y = 25;

    // calling lambda fun
    int z = [&x, &y]()
    {
        x = 4;
        return x + y;
    }();
    cout << "fun arg : " << z << endl;

    // pass by reference using all gobal variables
    int p = [&]()
    {
        x = 30;
        return x + y;
    }();
    cout << "fun arg v1 : " << p << endl;

    return 0;
}