#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ::std::vector<int> v = {1,5,7,4,3};
    // descending order
    //::std::sort(v.begin(), v.end(), [](int a, int b){return a > b;});

    // ascending order
    std::sort(v.begin(), v.end());

    // Display the sorted vector
    for (int num : v) {
        std::cout << num << " ";
    }

    // find number 4 from the vector
    auto it = std::find(v.begin(), v.end(), 4);
    if(it != v.end()){
        // element found
        cout << "\n" << *it << endl;
    }

    

    return 0;
}