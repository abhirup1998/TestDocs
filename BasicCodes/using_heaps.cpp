#include <algorithm>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>

#def 
using namespace std;
int min_heap_comaparator(int x, int y)
{
	if (x < y)
		return x;
}
void display(priority_queue<int, vector<int>, greater<int> > pq)
{
	while(!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
	}
}
int main()
{
	priority_queue <int, vector<int>, greater<int> > pq;
	pq.push(1);
	pq.push(8);
	pq.push(2);
	pq.push(9);
	pq.push(12);
	pq.push(3);
	display(pq);
	
}
