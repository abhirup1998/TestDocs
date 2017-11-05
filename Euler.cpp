#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef unsigned long long ull;

int main() {
    int t;cin >> t;
    while(t-->0)
    {
        ull a, m, b;int res=1;
        cin >> a >> m;
        b = (m-1)/2;
        a=a%m;
        while(b > 0)
        {
            if(b&a)
                res = (res*a)%m;
            a = (a*a)%m;
            b = b/2;
        }
        if(res == 1)
            cout << "YES"<<endl;
        else
            cout << "NO" << endl;
    }
}
