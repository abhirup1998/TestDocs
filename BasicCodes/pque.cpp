#include <queue>
#include <algorithm>
#include <iostream>
#include <stdlib.h>

using namespace std;
int main()
{
	priority_queue<int> pq;
	int sum = 0;
	for (int i = 0; i < 10; ++i)
	{
		/* code */
		pq.push(rand()%10 + 1);
	}
	while(!pq.empty())
	{
		sum += pq.top();
		cout << pq.top() << " ";
		pq.pop();

	}
	cout << endl;
	cout <<"Sum" << sum << endl;
	return 0;

}
