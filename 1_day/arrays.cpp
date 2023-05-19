#include <iostream>
#include <iterator>

using namespace std;

int main()
{
	int myarr[] = {1, 2, 3};
	cout << myarr[0] << "," << ::std::size(myarr) << endl;
	cout << "Size of array : " << end(myarr) - begin(myarr) << endl;

	return 0;
}
