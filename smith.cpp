#include <vector>
#include <iostream>
#include <set>
#include <cmath>
using namespace std;
typedef unsigned long long ull;
int sumdig(ull nc)
{
	int s=0;
	while(nc>0)
	{
		s+=nc%10;
		nc/=10;
	}
	return s;
}
int main()
{
	ull n, sn=0, sd=0;
	cin >> n;
	if(n == 1)
	{
		cout << 0;
		return 0;
	}
	sn = sumdig(n);
	for(ull i=2; i<=n ;i+=(i>=3?2:1))
		while(n%i==0)
		{	sd+=sumdig(i);
			if(sd > sn)break;
			n/=i;
		}

	// for(auto f:pf)
	// {
	// 	cout << f << " " << nc/f << endl;
	// }
	if(sd == sn)
		cout << 1 << endl;
	else cout << 0 << endl;
}
