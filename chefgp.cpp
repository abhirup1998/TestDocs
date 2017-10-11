#include <iostream>
#include <string>
using namespace std;
int main()
{
	int tc; cin >> tc;
	for(int t=0; t<tc; t++)
	{

			string s, f;
			int x, y;
			cin >> s;
			cin >> x >> y;
			int fptr=-1, len = s.length();
			int a=0, b=0, A=0, B=0, k=0;
			for(int i=0; i<len;i++)
				s[i] == 'a' ? A++: B++;
			for(int i=0; i<len; i++)
			{
				char c = s[i];
				if(c == 'a')
				{	a++;
					if(fptr < x-1)
					{
						f += c;
						fptr++;
						// a++;
					}
					else if(B-b == 0)
					{
						// cout << "*: Searching prefix in " << fptr-x << endl;
						string pre = f.substr(fptr-x+1, x);
						// cout << "   pre " << pre << endl;
						int pb = pre.find("b"), px = pre.find("*");
						if(pb == string::npos && px == string::npos)
						{
							f += "*a";
							fptr+=2;
							k++;
						}
						else
						{
							f += "a";
							fptr++;
						}
					}			
					else 
					{
						// cout << "b: Searching prefix in " << fptr-x << endl;
						string pre = f.substr(fptr-x+1, x);
						// cout << "   pre " << pre << endl;
						int pb = pre.find("b"), px = pre.find("*");
						if(pb == string::npos && px == string::npos)
						{

							string post = s.substr(i+1, len);
							// cout << "   post " << post << endl;
							int j = post.find("b");
							// cout << "   b found at " << i+1+j << endl;
							s.erase(i+1+j, 1);
							f += "ba";
							fptr+=2;
							b++;
						}
						else
						{
							f += "a";
							fptr++;
						}
					}

				}
				else
				{	b++;
					if(fptr < y-1)
					{
						f += c;
						fptr++;
						// a++;
					}
					else if(A-a == 0)
					{
						// cout << "*: Searching prefix in " << fptr-y << endl;
						string pre = f.substr(fptr-y+1, y);
						// cout << "   pre " << pre << endl;
						int pa = pre.find("a"), py = pre.find("*");
						if(pa == string::npos && py == string::npos)
						{
							f += "*b";
							fptr+=2;
							k++;
						}
						else
						{
							f += c;
							fptr++;
						}
					}			
					else 
					{
						// cout << "a: Searching prefix in " << fptr-y << endl;
						string pre = f.substr(fptr-y+1, y);
						// cout << "   pre " << pre << endl;
						int pa = pre.find("a"), py = pre.find("*");
						if(pa == string::npos && py == string::npos)
						{

							string post = s.substr(i+1, len);
							// cout << "   post " << post << endl;
							int j = post.find("a");
							// cout << "   a found at " << i+1+j << endl;
							s.erase(i+1+j, 1);
							f += "ab";
							fptr+=2;
							a++;
						}
						else
						{
							f += c;
							fptr++;
						}
					}

				}
				// cout << "s " << s << endl;
				// cout << "f " << f << endl;
			} 
			cout<< f << endl;
	}
}
