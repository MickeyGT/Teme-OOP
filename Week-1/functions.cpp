#include "Polinoame.h"

int MIN(int x, int y)
{
	if (x<y)
		return x;
	else
		return y;
}

int cmmdc(int a, int b)
{
	if (b == 0) 
		return a;
	return cmmdc(b, a%b);
}

void calculate_gcd(int vec1[], int vec2[], int vec3[])
{
	int i, n = MIN(vec1[0], vec2[0]);
	vec3[0] = n;
	for (i = 1; i <= n; i++)
	{
		vec3[i] = cmmdc(vec1[i], vec2[i]);
	}
}


