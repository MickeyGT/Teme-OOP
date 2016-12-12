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
#include<set>
#include<iomanip>
#include<bitset>
using namespace std;
class Bancomat
{
private:
    int bani=0,plafon=10000;
public:
    void retragere()
    {
        int sum;
        cout<<"Ce suma doriti sa retrageti?: ";
        cin>>sum;
        try
        {
        if(bani<sum)
            throw "NAAAAH";
        else
            if(sum>plafon)
                throw "NAAAAAH";
                else
                    bani-=sum;
        }
        catch (const char* msg)
        {
            cout << msg << endl;
        }
    }
    void adaugare()
    {
        int sum;
        cout<<"Ce suma doriti sa introduceti?: ";
        cin>>sum;
        bani+=sum;
    }
};
int main()
{
    Bancomat bcm;
    bcm.adaugare();
    bcm.retragere();
    return 0;
}
