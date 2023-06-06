#include<iostream>
using namespace std;

#define MY_FILE_SIZE 25


class Base{
public:
    Base()
    {
        cout << "Bingo!" << endl;
    }
};

int main(){
    cout << MY_FILE_SIZE << endl;

    Base b[10];
    return 0;
}