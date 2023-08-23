#include <iostream>
#include <memory>

using namespace std;

int main()
{
    int i = 5;
    int *j = &i;

    auto my_ptr = std::unique_ptr<int>(j);

    cout << "Is my pointer valid : " << !my_ptr << endl;

    return 0;
}
