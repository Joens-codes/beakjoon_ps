#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int a ;
	int b;
	int c;
	int d;
	int f;
	int g = 0;
	
	scanf("%d", &a);
	b = a;
	while (1)
	{
		c = a % 10;
		d = a / 10;
		f = c * 10 + (c + d) % 10;
		a = f;
		g++;
		if (b == f)
			break;
	}
	printf("%d", g);
	return 0;
}