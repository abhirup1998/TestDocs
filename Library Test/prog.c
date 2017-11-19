#include <stdio.h>
void test1(int *);
void test2(int *);
int main()
{
	int x;
	test2(&x);
	printf("Valx=%d\n", x);
	return 0;
}