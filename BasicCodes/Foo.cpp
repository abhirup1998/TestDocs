#include "Foo.h"
#include <iostream>
using namespace std;
Foo::Foo(){
	x=5;y=10;
}
Foo::Foo(int a, int b)
{
	x=a;
	y=b;
}
void Foo::Manipulate(int g, int h)
{
	x += g;
	y += h;
}
void Foo::getFoo()
		{
			cout << "x: "<< x << " y: "<< y << endl;
		}
