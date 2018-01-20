#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;
ifstream fin("date.in");
ofstream fout("date.out");
int verificare(char s[],int in,int fn,int n)
{
    int nr = 0,nr2 = 0, p = in;
    while(p <= fn)
    {
        if(s[p] == 'A')
        {
            nr++;
        }
        else if(s[p] == 'B')
        {
            nr2++;
        }
        if(fn != n)
        {
            p++;
        }
    }
    if(nr == nr2)
    {
        return 1;
    }
    else return 0;

}
void afisare(char s[],int in,int fn)
{
    for(int i = in;i<=fn;i++)
    {
        fout << s[i];
    }
    fout << endl;
}
int main()
{
    char s[20];
    fin.getline(s,20);
    for(unsigned i = 0;i < strlen(s);i++)
    {
        for(unsigned j = i;j < strlen(s);j++)
        {
                if(verificare(s,i,j,strlen(s)) == 1)
                {
                    afisare(s,i,j);
                }
        }
    }
    return 0;
}
