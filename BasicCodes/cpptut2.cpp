#include <iostream>
#include "Foo.h"
using namespace std;
int main()
{
	cout << "in Main " << endl;
	Foo f(2, 3);
	f.Manipulate(2, 3);
	f.getFoo();
}