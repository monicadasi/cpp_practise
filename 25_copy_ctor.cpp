#include<iostream>
using namespace std;

class Foo{
private:
    int* array, size;

public:
    Foo(int s){
        //cout << "default c'tor called" << endl;
        size = s;
        array = new int[size]{0};
    }

    // copy c'tor
    Foo(const Foo& rhs)
    {
        cout << "copy c'tor called" << endl;
        size = rhs.size;
        array = new int[size];

        for(int i = 0; i < size; i++)
        {
            array[i] = rhs.array[i];
        }
    }

    // d'tor
    ~Foo()
    {
        if(array)
        {
            delete[] array;
        }

    }

    // f + g in temp obj: cause an r-value to be created
    Foo operator+(const Foo& rhs)
    {
        cout << "operator+ executes" << endl;
        Foo temp(size + rhs.size);
        auto i = 0;
        for(; i< size; i++)
        {
            temp[i] = array[i];
        }

        for(auto j = 0; j < rhs.size; i++, j++)
        {
            temp[i] = rhs.array[j];
        }

        return temp;
    }

    // f = g
    Foo& operator=(const Foo& rhs)
    {
        cout << "copy assignment operator" << endl;
        if(this == &rhs)
        {
            return *this;
        }

        if(array)
        {
            delete [] array;
        }

        size = rhs.size;
        array = new int[size];

        for(int i = 0; i < size; i++)
        {
            array[i] = rhs.array[i];
        }
        return *this;
    }

    int& operator[] (int i)
    {
        return array[i];
    }

    int length() const{
        return size;
    }

    friend ostream& operator<<(ostream& o, const Foo& rhs)
    {
        for(int i = 0; i < rhs.size; i++)
        {
            o << rhs.array[i] << " ";
        }
        return o;
    }
};

int main(){
    Foo f(5);

    for(int i = 0; i < f.length(); i++)
    {
        f[i] = 3 * i;
    }
    cout << f << endl;

     Foo g(f);
     cout << g << endl;

    Foo h(3);
    // f + g creates an r-value, that's an unnamed memory location that is TEMPORARY
    // that temp r-value..
    h = f + g ;
    cout << h << endl;

    return 0;
}