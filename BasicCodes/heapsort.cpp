#include <iostream>
#include <cmath>
using namespace std;

int len = 20, hsize = 0;
#define left(p) 2*p
#define right(p) 2*p+1
void build_heap(int*);
void max_heapify(int*, int);
void display_heap(int*);
int n_largest(int, int *);
void build_heap(int *ar)
{
	hsize = len;
	for (int i = (len-1)/2 ; i >= 1; --i)
	 {
	 	/* code */
	 	max_heapify(ar, i);
	 	// display_heap(ar);
	 	// cout << "------------------" << endl;
	 } 
}
void max_heapify(int*ar, int i)
{
	int l = left(i), r = right(i), largest = i;
	// cout << l << " " << r << endl;
	if(r < hsize && ar[r] > ar[i])
		largest = r;
	if(l < hsize && ar[l] > ar[largest])
		largest = l;
	if(largest != i)
	{
		// cout << "swapping -- " << ar[i] << " and " << ar[largest] << endl;
		int temp = ar[largest];
		ar[largest] =ar[i];
		ar[i] = temp; 
		max_heapify(ar, largest);
	}
}
void display_heap(int*ar)
{
	cout << "--Heap-- " << endl;
	for (int i = 1; i < len; ++i)
	{
		/* code */
		cout << ar[i] << "(" << i/2 << ")" << endl;;
	}
	cout << endl;
}
int n_largest(int n, int *ar)
{
	if(n > hsize-1)n = hsize - 1;
	if(n == 1) return ar[1];
	while(n > 1)
	{
		int temp = ar[hsize-1];
		ar[hsize-1] = ar[1];
		ar[1] = temp;
		n--;hsize--;
		max_heapify(ar, 1);
	}
	int x = ar[1];
	build_heap(ar);
	return x;
}
int main()
{
	int ar[9] = {0, 9, 67, 1, 3, 15, 23, 47, 44};
	len = 9;int p;
	cout << "Enter max_heapify "; 
	cin >> p;
	cout << endl;
	build_heap(ar);
	display_heap(ar);
	int n;
	do{
		cout << "n_largest? ";
		cin >> n;
		cout << n_largest(n, ar) << endl;
	}while(1);
}