#include"Zaruri.h"
#include<iostream>
#include<time.h>
using namespace std;
int main()
{
	Zaruri zar;
	srand(time(NULL));
	for (int i = 1; i <= 9000; i++)
	{
		int zar1 = zar.simulate_throw();
		int zar2 = zar.simulate_throw();
		zar.add_res(zar1, zar2);
	}
	zar.show_res();
	return 0;
}
