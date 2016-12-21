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
class Bancomat
{
private:
	int bani = 0, plafon = 10000, client[10000],savedpin[10000],nrgres[10000];
public:
	Bancomat()
	{
		for (int i = 0; i <= 9999; i++)
		{
			client[i] = 0;
			savedpin[i] = 0;
			nrgres[i] = 0;
		}
	}
	void create()
	{
		int user,pin;
		cout << "Ce ID o sa aiba userul?: ";
		cin >> user;
		cout << "Ce PIN o sa aiba userul?: ";
		cin >> pin;
		savedpin[user] = pin;
	}
	int pin(int user)
	{
		int pin;
		cout << "Introduceti pinul: ";
		cin >> pin;
		if (savedpin[user] == pin)
			return 1;
		else
			return 0;
	}
	void retragere()
	{
		int cont;
		cout << "Dinn ce cont doriti sa retrageti bani? ";
		cin >> cont;
		if (nrgres[cont] > 3)
		{
			cout << "Cont blocat.\n";
			return;
		}
		try
		{
			if (pin(cont) == 0)
			{
				nrgres[cont]++;
				throw "Pinul este gresit.";
			}
		}
		catch (const char* msg)
		{
			cout << msg << endl;
			return;
		}
		int sum;
		cout << "Ce suma doriti sa retrageti?: ";
		cin >> sum;
		try
		{
			if (client[cont] < sum)
				throw "Nu aveti destui bani.";
			else
				if (sum > plafon)
					throw "Nu mai e plafon.";
				else
					client[cont] -= sum;
		}
		catch (const char* msg)
		{
			cout << msg << endl;
		}
		cout << "Sold curent:" << client[cont]<<'\n';
	}
	void adaugare()
	{
		int cont;
		cout << "In ce cont doriti sa adaugati bani? ";
		cin >> cont;
		if (nrgres[cont] > 3)
		{
			cout << "Cont blocat.\n";
			return;
		}
		try
		{
			if (pin(cont) == 0)
			{
				nrgres[cont]++;
				throw "Pinul este gresit.";
			}
		}
		catch (const char* msg)
		{
			cout << msg << endl;
			return;
		}
		int sum;
		cout << "Ce suma doriti sa introduceti?: ";
		cin >> sum;
		try
		{
			if (rand() % 10 == 1)
				throw "Banii sunt falsi.";
			else
				client[cont] += sum;
		}
		catch (const char* msg)
		{
			cout << msg << endl;
		}
		cout << "Sold curent:" << client[cont] << '\n';
	}
	void transfer()
	{
		int sender;
		cout << "Cine este senderul?: ";
		cin >> sender;
		if (nrgres[sender] > 3)
		{
			cout << "Cont blocat.\n";
			return;
		}
		try
		{
			if (pin(sender) == 0)
			{
				nrgres[sender]++;
				throw "Pinul este gresit.";
			}
		}
		catch (const char* msg)
		{
			cout << msg << endl;
			return;
		}
		int reciever;
		cout << "Cine este recieverul?: ";
		cin >> reciever;
		int sum;
		cout << "Ce suma doriti sa trimiteti?: ";
		cin >> sum;
		try
		{
			if (client[sender] < sum)
				throw "Nu aveti destui bani.";
			else
				if (sum > plafon)
					throw "Nu mai e plafon.";
				else
					if (savedpin[reciever] == 0)
						throw "Nu exista utilizatorul la care sa se faca transferul.";
					else
					{
						client[reciever] += sum;
						client[sender] -= sum;
					}
		}
		catch (const char* msg)
		{
			cout << msg << endl;
		}
		cout << "Sold curent pentru sender:" << client[sender] << '\n';
		cout << "Sold curent pentru reciever:" << client[reciever] << '\n';
	}
};
int main()
{
	Bancomat bcm;
	bcm.create();
	bcm.create();
	bcm.create();
	bcm.adaugare();
	bcm.adaugare();
	bcm.adaugare();
	bcm.adaugare();
	bcm.adaugare();
	bcm.adaugare();
	bcm.retragere();
	bcm.retragere();
	bcm.retragere();
	bcm.retragere();
	bcm.retragere();
	bcm.retragere();
	bcm.transfer();
	bcm.transfer();
	bcm.transfer();
	bcm.transfer();
	bcm.transfer();
	bcm.transfer();
	return 0;
}
