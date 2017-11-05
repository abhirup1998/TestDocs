#include <vector>
#include <set>
#include <iostream>
#include <cmath>
using namespace std;
typedef unsigned long long ull;
void simpleSieve(int lim, vector<int> &primes)
{
	vector<bool> sv(lim+1, true);
	for(int i=2; i*i<=lim; i+=i>=3?2:1)
	{
		if(primes[i] == true)
		{
			for(ull j=i<<1; j<=lim; j+=i)
				primes[j] = false;
		}
	}
	for(int i=2; i<=lim; i++)
		if(sv[i])
			primes.push_back(i);
	for(auto p:primes)
		cout << p << " ";
	cout << endl;
}

int main()
{
	ull m,n;
	int res=0;
	cin >> m >> n; n++;
	int lim = sqrt(n);
	vector<int> primes;
	simpleSieve(lim, primes);
	for(int i=0; i<primes.size()-1; i++)
	{
		if(primes[i+1] - primes[i] == 2)
			cout << primes[i] << " " << primes[i+1] << endl;
	}

	ull low, high;
	low = lim; high=2*lim;
	while(low < n)
	{   cout << "low " << low << "    high "<< high << endl;
		vector<bool> mark(lim+1, true);
		ull lowLim;
		for(int i=0; i<primes.size(); i++)
		{
			lowLim = floor(low/primes[i]) * primes[i];
			if(lowLim<low)
				lowLim+=primes[i];
			for(ull j= max((int)lowLim, primes[i]*2); j<high; j+=primes[i])
			{
				mark[j-low] = false;
			}

		}
		for(ull j=low; j<high; j++)
		{
			cout << j << "(" << mark[j-low] << ") ";
		}
		cout << endl;
		for(int i=max(m,low); i<high-2; i+=2)
			if(mark[i-low] && mark[i-low+2])
				cout << i << " " << i+2 << endl;
		ull lastprime=high-1;
		while(!mark[lastprime-low])
			lastprime--;
		low += lim;
		if(low-lastprime <=2)low=lastprime;
		high = low + lim;
		if(high >=n)high=n; 
	}
}
