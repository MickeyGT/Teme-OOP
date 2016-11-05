#include<fstream>
#include<string.h>
#include<ctype.h>
#include<iostream>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<array>
#include<deque>
#include<math.h>
#include<unordered_set>
#include<set>
#include<iomanip>
#include<bitset>
#include<time.h> 
#include "Zaruri.h"
using namespace std;

Zaruri::Zaruri()
{
	memset(freq, 0, sizeof(freq));
	memset(fr, 0, sizeof(fr));
	memset(prfreq, 0, sizeof(prfreq));
	prv_f1 = prv_f2 = 0;
}
int Zaruri::simulate_throw()
{
	return 1 + rand() % 6;
}
void Zaruri::add_res(int f1, int f2)
{
	freq[f1][f2]++;
	if ((f1 == prv_f1&&f2 == prv_f2) || (f1 == prv_f2&&f2 == prv_f1))
		prfreq[f2][f1]++;
	fr[f1]++;
	fr[f2]++;
	prv_f1 = f1;
	prv_f2 = f2;
}
void Zaruri::show_res()
{
	int max1 = -1 * 1 << 30, min1 = 1 << 30, maxcon = -1 * 1 << 30, ok = 1;
	for (int i = 1; i <= 6; i++)
		for (int j = 1; j <= 6; j++)
		{
			if (freq[i][j] > max1)
				max1 = freq[i][j];
			if (freq[i][j] < min1)
				min1 = freq[i][j];
			if (prfreq[i][j] > maxcon)
				maxcon = prfreq[i][j];
		}
	cout << "Perechea cu cele mai multe apartitii este: ";
	for (int i = 1; i <= 6; i++)
		for (int j = 1; j <= 6; j++)
			if (ok&&freq[i][j] == max1)
			{
				cout << i << ' ' << j << '\n';
				ok = 0;
			}
	ok = 1;
	cout << "Perechea cu cele mai multe apartitii consecutive este: ";
	for (int i = 1; i <= 6; i++)
		for (int j = 1; j <= 6; j++)
			if (ok&&prfreq[i][j] == maxcon)
			{
				cout << i << ' ' << j << '\n';
				ok = 0;
			}
	ok = 1;
	cout << "Perechea cu cele mai putine apartitii este: ";
	for (int i = 1; i <= 6; i++)
		for (int j = 1; j <= 6; j++)
			if (ok&&freq[i][j] == min1)
			{
				cout << i << ' ' << j << '\n';
				ok = 0;
			}
	cout << "Frecventa aparitiei fiecarei fete de pe zar este: ";
	for (int i = 1; i <= 6; i++)
	{
		cout << fr[i] << ' ';
	}
	cout << '\n';
}

int Zaruri::get_max_fr(int v[7])
{
	int maxim=0;
	for (int j = 1; j <= 6; j++)
		maxim = max(maxim,fr[j]);
	return maxim;
}

void Zaruri::get_fr(int v[7])
{
	for (int j = 1; j <= 6; j++)
		v[j] = fr[j];
}

void SefTribut::show_res()
{
	int vec[7];
	sefi.get_fr(vec);
	cout << "Rezultatele din primul tur sunt:\n";
	for (int i = 1; i <= 6; i++)
		cout << i<<" are "<<vec[i]<<" voturi.\n";
	int maxim = 0,poz=0;
	for (int j = 1; j <= 6; j++)
	{
		if (maxim < vec[j])
		{
			maxim = vec[j];
			poz = j;
		}
	}
	if (maxim > 4501)
	{
		cout << "Castigatorul este " << poz << " cu " << maxim << " voturi";
	}
	else
	{
		vec[poz] = 0;
		cout << "Se trece la turul 2 intre "<<poz<<" si ";
		int maxim2 = 0, poz2 = 0;
		for (int j = 1; j <= 6; j++)
		{
			if (maxim2 < vec[j])
			{
				maxim2 = vec[j];
				poz2 = j;
			}
		}
		cout << poz2 << ".\n";
		maxim = maxim2 = 0;
		for (int i = 1; i <= 9000; i++)
		{
			int rez=sefi.simulate_throw();
			if (rez >= 4)
				maxim++;
			else
				maxim2++;
		}
		cout << "Castigatorul este: ";
		if (maxim > maxim2)
			cout << poz<<" cu "<<maxim<<" voturi.";
		else
			if (maxim < maxim2)
				cout << poz2 << " cu " << maxim2 << " voturi.";
			else
				cout << " niciunul...egalitate.";
	}
}
