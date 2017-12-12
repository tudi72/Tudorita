#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("date.in");
ofstream fout("date.out");
struct crab
{
    int timp;
    int mas;
}a[50];
void citire(crab a[],int n)
{
    for(int i = 1;i <= n;i++)
    {
        fin >> a[i].mas >> a[i].timp;
    }
}
void ordonare(crab a[],int n)
{
    for(int i = 1;i < n;i++)
    {
        for(int j = i+1;i<=n;i++)
        {
            if(a[i].timp < a[j].timp)
            {
                swap(a[i],a[j]);
            }
        }
    }
}
void greedy(crab a[],int n,int t,int &nr)
{
    for(int i = 1;i <=n;i++)
    {
        if(t > 0)
        {
            fout << a[i].mas << "  ";
            nr++;
            t-=a[i].timp;
        }
    }
}
int main()
{
    int t,n;
    fin >> n >> t;
    citire(a,n);
    ordonare(a,n);
    int nr = 0;
    greedy(a,n,t,nr);
    fout << "vor fi reparare " << nr << "masini";
    return 0;
}
