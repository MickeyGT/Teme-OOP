#include "functii.h"

int calculate_nr_app(char prefix[100],char sir[100])
{
	int l = strlen(sir),len=strlen(prefix),nr=0,ok=1;
	for (int i = 0; i <= l - len; i++)
	{
		ok = 1;
		for (int j = i; j <= i + len-1; j++)
		{
			if (sir[j] != prefix[j-i])
			{
				ok = 0;
				break;
			}
		}
		if(ok)
			nr++;
	}
	return nr;
}


