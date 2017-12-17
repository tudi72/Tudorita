#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("date.in");
ofstream fout("date.out");
///problema bancnotelor
void citire(int a[],int n,int e)
{
    a[0] = 1;
    for(int i = 1;i<=n;i++)
    {
        a[i] = a[i-1]*e;
    }
}
void afisare(int a[],int n)
{
    for(int i = 1;i<=n;i++)
    {
        fout << a[i] << "  ";
    }
    fout << endl;
}
void ordon(int a[],int n)
{
    for(int i = 1;i<n;i++)
    {
        for(int j = 1+i;j<=n;j++)
        {
            if(a[i] < a[j])
            {
                swap(a[i],a[j]);
            }
        }
    }
}
void greedy(int a[],int n,int S)
{
    int aux = S;
    int nr;
    int i = 1;
    while(i <= n)
    {
        nr = 0;
        while(aux-a[i] >= 0)
        {
            nr++;
            aux-=a[i];
        }
        if(aux-a[i] < 0)
        {
            fout << a[i] << " de numar " << nr << endl;
            i++;
        }
    }
}
int main()
{
    int a[50];
    int S,n,e;
    fin >> n>> e >> S;
    citire(a,n,e);
    afisare(a,n);
    ordon(a,n);
    greedy(a,n,S);
    return 0;
}
