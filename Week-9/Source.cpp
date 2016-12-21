#include<fstream>
#include<string.h>
#include<ctype.h>
#include<iostream>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<array>
#include<functional>
#include<deque>
#include<math.h>
#include<unordered_set>
#include<queue>
#include<list>
#include<set>
#include<iomanip>
#include<bitset>
using namespace std;
template <class T>
class sortare
{
private:
	T vec[100];
	int n;
public:
	void creare()
	{
		cout << "Cate elemente sa aiba sirul?: ";
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cout << "vec[" << i << "]=";
			cin >> vec[i];
		}
		cout << "\n";
	}
	void afisare()
	{
		cout << "Se afiseaza sirul: ";
		for (int i = 1; i <= n; i++)
			cout << vec[i]<< " ";
		cout << "\n";
	}
	void sorteaza()
	{
		cout << "Se sorteaza sirul.\n";
		sort(vec + 1, vec + n+1);
	}
};

class matrice
{
private:
	int n, mat[100][100];
public:
	void creare()
	{
		cout << "Ce dimensiuni sa aiba matricea?:\n";
		cout << "n="; cin >> n;
		for (int j = 1; j <= n; j++)
			for (int k = 1; k <= n; k++)
			{
				cout << "vec[" << j << "][" << k << "]=";
				cin >> mat[j][k];
			}
		cout << "\n";
	}
	void afisare()
	{
		for (int j = 1; j <= n; j++)
		{
			for (int k = 1; k <= n; k++)
			{
				cout << mat[j][k] << " ";
			}
			cout << '\n';
		}
		cout << "\n";
	}
	
};

template <> class sortare <matrice>
{
private:
	int siz;
	matrice mat[100];
public:
	void creare()
	{
		cout << "Cate elemente sa aiba sirul?: ";
		cin >> siz;
		for (int i = 1; i <= siz; i++)
		{
			mat[i].creare();
		}
	}
	void afisare()
	{
		
		for (int i = 1; i <= siz; i++)
		{
			mat[i].afisare();
		}
	}
};
int main()
{
	/*
	sortare<int> myints;
	sortare<string> mystrings;
	sortare<float>myfloats;
	myints.creare();
	myints.afisare();
	myints.sorteaza();
	myints.afisare();
	mystrings.creare();
	mystrings.afisare();
	mystrings.sorteaza();
	mystrings.afisare();
	myfloats.creare();
	myfloats.afisare();
	myfloats.sorteaza();
	myfloats.afisare();
	*/
	sortare<matrice>mymatrix;
	mymatrix.creare();
	mymatrix.afisare();
	return 0;
}
