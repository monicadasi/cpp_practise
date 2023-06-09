// std::array (STL contains)
// Syntax: std::array<T, N> array; T -> type (template) and N -> size

#include <iostream>
#include <array>

using namespace std;

int main(){
    // declaration
    std::array<int, 5> myArr;

    //initialization
    myArr = {1,2,3,4,5};
    std::array<int, 5> myArr2 {1,2,3,4,5};

    try
    {
        cout << myArr2.at(4) << endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}