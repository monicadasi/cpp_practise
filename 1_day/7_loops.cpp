#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void print(int val) {cout << val << endl;}

int main()
{
    vector<int> my_vec;

    for(int i = 0; i <5; i++)
    {
        my_vec.push_back(i);
    }

    for(auto& i: my_vec)
    {
        cout << i << endl;
    }

    for_each(my_vec.begin(), my_vec.end(), [](int i){
        cout << i << endl;
    });

    for_each(my_vec.begin(), my_vec.end(), print);


    return 0;
}