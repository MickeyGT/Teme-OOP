#include"Polinoame.h"
using namespace std;
int n, m, v1[111], v2[111], rez[111],i,j,k;
int main()
{
	cout << "Dimeansiuena primului polinom = ";
	cin >> n;
	cout << '\n';
	v1[0] = n;
	cout << "Dimeansiunea celui de al doilea polinom = ";
	cin >> m;
	cout << '\n';
	v2[0] = m;
	cout << "Elementele primului polinom sunt:\n";
	for (i = 1; i <= n; i++)
		cin >> v1[i];
	cout << "Elementele celui de al doilea polinom sunt:\n";
	for (i = 1; i <= m; i++)
		cin>> v2[i];
	calculate_gcd(v1, v2, rez);
	cout << "Rezultatul este:\n";
	for (i = 1; i <= rez[0]; i++)
		cout<<rez[i]<<' ';
	return 0;
}
