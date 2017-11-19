#include "date.h"
#include <stdio.h>
void main()
{
	struct date d;
	d.d=17;
	d.m=11;
	d.y=2017;
	printf("%d / %d / %d\n", d.d,d.m,d.y);
}