#include <iostream>
#include <cstring>

using namespace std;

class String{
 int len;
 char* res;
public:
	String(): res(nullptr), len(0){
        cout << "default c'tor" << endl;
    } // default c'tor // initializer list

	// parameterised c'tor
	String(const char* ch){
        cout << "parameterised c'tor" << endl;
		len = strlen(ch);
		res = new char[len+1]; // +1 to accomodate the null terminated character.
        strcpy(res, ch);
	}

    // copy c'tor
    String (const String& other){
        cout << "copy c'tor" << endl;
        len = other.len;
        res = new char[len + 1];
        strcpy(res, other.res);
    }

    // // copy assignment operator
    // String& operator = (const String& other){
    //     cout << "copy assignment operator" << endl;
    //     len = other.len;
    //     if (this != &other){
    //         delete[] res; // array of memory , whole memory will be deleted, potential memory leak
    //         len = other.len;
    //         res = new char[len +1];
    //         strcpy(res, other.res);
    //     }
    //     return *this;
    // }

    // copy assignment operator CAS -> copy and swap idiom
    String& operator = (String other){
        cout << "copy assignment operator" << *this << endl;
        _swap(*this, other);
        return *this;
    }

    void _swap(String &str1, String &str2)
    {
        std:swap(str1.res, str2.res);
        std::swap(str1.len, str2.len);
    }

    int length(){
        return len;
    }

    String (String&& other) noexcept{
        cout << "move c'tor called";
        len = other.len;
        res = other.res;
        other.len = 0;
        other = nullptr;
    }

    friend ostream& operator << (ostream& out, const String& str){
        out << str.res;
        return out;
    }

    friend istream& operator >> (istream& in, const String& str){
        in >> str.res;
        return in;
    }

    ~String(){
        if (res)
        {
            delete [] res;
            res = nullptr;
            len = 0;
        }
    }
};



int main()
{
	String str1; // instantiate the class with an empty string -> default c'tor
	String str2 = "Hello World!"; // constant string -> paramterized c'tor

	String str3 = str1; // copy c'tor
	str1 = str2; // copy assignment operator
	String str4(str3); // copy c'tor invoked

    int _len = str2.length();

	cout << str1; // operator oveload of <<
    cin >> str2;  // operator overload of >>

    String str5 = std::move(str2);
	
	return 0;
}