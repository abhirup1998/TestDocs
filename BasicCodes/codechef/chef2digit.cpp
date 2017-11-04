#include <iostream>
#include <string>

using namespace std;

int main()
{
	int tc, i;
	int num[10];
	cin >> tc;
	string ans[tc];

	for (i = 0; i < tc; i++)
	{
		string str;
		cin >> str;
		for(int j = 0; j < 10; j++)num[j] = 0;
		// cout << str;
		for(int j = 0; j < str.length(); j++)
			num[str[j] - 48] += 1;
		for (int j = 65; j<= 90; j++)
		{
			if(num[j/10]>0 && num[j%10]>0)
			{
				if(j/10 == j%10)
					{
						if (num[j/10] > 1) 
				 	 	cout << (char)j;
				 	 }
			 	else
				 	cout << (char)j; 
			}
		}
		cout << endl;
	}
	// for(i = 0 ; i < 10; i++)
	// 	cout << num[i] << " ";
	// cout << endl;
	
}
