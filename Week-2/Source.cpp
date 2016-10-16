#include"functii.h"
using namespace std;
char s[100],pr[100];
int main()
{
	cout << "Stringul cautat este = ";
	cin >> pr;
	cout << '\n';
	cout << "Stringul in care cautam este = ";
	cin >> s;
	cout << '\n';
	cout << "Numarul de aparitii ale primului string in al doilea este:";
	cout << calculate_nr_app(pr, s)<<'\n';
	return 0;
}
