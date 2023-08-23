#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    vector<int> my_vec;
    for(int i = 1; i <=10; ++i)
    {
        my_vec.push_back(i);
    }

    int even_count = 0;
    // lambda expression
    for_each(my_vec.begin(), my_vec.end(), [&even_count](int n)
    {
        cout << n;
        if (n % 2 == 0){
            cout << " : even " << endl;
            ++even_count;
        }
        else{
            cout << " : odd" << endl;
        }
    }); 

    cout << "There are " << even_count << " even numbers in the given vector" << endl;
    return 0;
}