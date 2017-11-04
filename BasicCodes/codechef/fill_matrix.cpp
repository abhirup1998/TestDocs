#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int tc, t;
	cin >> tc;
	bool ans[tc];
	for(t = 0; t<tc; t++)
	{
		int N, Q;
		cin >> N >> Q;

		vector< vector<int> > mat (N, vector<int>(N) );
		for(int k = 0; k < N; k++)
			for(int l = 0; l < N; l++)
				mat[k][l] = -1;
		for(int k = 0; k < Q; k++)
		{
			int i, j, val;

			if(i == j && val != 0)
			{
				ans[t] = false;
				continue;
			}

			if(mat[i][j] == -1)
			{
				mat[i][j] = val;
				mat[j][i] = val;
			}
			else 
				if(mat[i][j] == mat[j][i]) ans[t] = true;
			
		}	
	}
	for (t = 0; t < tc; t++)
	{
		cout << ans[t] << endl;
	}
}
