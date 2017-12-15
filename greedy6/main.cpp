#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("date.in");
ofstream fout("date.out");
struct crab
{
    int inaltime[100];
}x[50];
void citire(crab x[],int n)
{
    for(int i =1;i<=n;i++)
    {
        fin >> x[1].inaltime[i];
    }
    for(int i = 1;i<=n;i++)
    {
        fin >> x[2].inaltime[i];
    }
}
void ordonare(crab x[],int n,int k)
{
    for(int i = 1;i< n;i++)
    {
        for(int j = i+1;j<=n;j++)
        {
            if(x[k].inaltime[i] > x[k].inaltime[j])
            {
                swap(x[k].inaltime[i],x[k].inaltime[j]);
            }
        }
    }
}
void greedy(crab x[],int n,int v[],int &nr)
{
    int pas = 1;
    int p = 1;
    for(int i = 1;i<=n;i++)
    {
        if(x[1].inaltime[i] < x[2].inaltime[pas] )
        {
            v[p++] = x[1].inaltime[i];
            v[p++] = x[2].inaltime[pas];
            nr++;
        }
        pas++;
    }
}
void afisare(int v[],int n)
{
    for(int i = 1;i<=n+n;i++)
    {
        fout << v[i] << " ";
    }
    fout << endl;
}
int main()
{
    int n,nr=0;
    fin >> n;
    int v[50]={0};
    citire(x,n);
    ordonare(x,n,1);
    ordonare(x,n,2);
    greedy(x,n,v,nr);
    afisare(v,n);
    fout << endl << "sunt " << nr << " baieti";
    return 0;
}
