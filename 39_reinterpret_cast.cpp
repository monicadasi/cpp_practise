#include<iostream>
using namespace std;

class Mango{
    public:
        void eatMango(){ cout << "eating mango" << endl; }
};

class Banana{
    public:
        void eatBanana() { cout << "eating banana" << endl; }
};

int main(){

    Banana *b = new Banana();
    Mango *m = new Mango();

    Banana *newb = reinterpret_cast<Banana*>(m); // this is dangerous
    newb->eatBanana();

    return 0;
}