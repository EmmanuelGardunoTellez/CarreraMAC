
#include "stdio.h"
#define N 100
int main()
{
	int n, a[N];
	int i = 0;
	n= 65536;
	while (n>0)
	{
		a[i] = n % 2;
		i = i + 1;
		n = n / 2;
	}
	for (i--; i >= 0; i--)
		printf("%d", a[i]);
	printf("\n");
	return 0;
}
