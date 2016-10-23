#ifndef ZARURI_H
#define ZARURI_H
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
};
#endif
