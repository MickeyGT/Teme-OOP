#ifndef ZARURI_H
#define ZARURI_H
using namespace std;
class Zaruri
{
private:
	int freq[7][7];
	int fr[7];
	int prv_f1, prv_f2;
	int prfreq[7][7];
public:
	Zaruri();
	int simulate_throw();
	void add_res(int f1, int f2);
	void show_res();
	void get_fr(int v[7]);
	int get_max_fr(int v[7]);
};

class SefTribut
{
private:
	Zaruri sefi;
public:
	void show_res();
	SefTribut()
	{
		for (int i = 1; i <= 9000; i++)
		{
			int zar1 = sefi.simulate_throw();
			int zar2 = sefi.simulate_throw();
			sefi.add_res(zar1, zar2);
		}
	}
};
#endif
