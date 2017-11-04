#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s;
	cin >> s;
	cout << s <<  endl;
	int i= s.substr(0, 3).find('r');
	s.erase(i, 1);
	cout << s;
}