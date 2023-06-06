#include<iostream>

using namespace std;

class A{
private:
    int size, *data;

public:
    // default c'tor
    A(int s){
        cout << "default c'tor called" << endl;
        size = s;
        data = new int[size]{0};
    }

    // d'tor
    ~A()
    {
        if(data)
        {
            delete[] data;
        }
    }

    const int length() const{
        return size;
    }

    int& operator[](int i)
    {
        return data[i];
    }
};

int main()
{
    A a(5);

    for (int i = 0; a.length(); ++i){
        a[i] = i * 5;
    }
}