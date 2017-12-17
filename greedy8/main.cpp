#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("date.in");
ofstream fout("date.out");
///problema camioanelor cu greutati
void citire(int v[],int n)
{
    for(int i = 1;i<=n;i++)
    {
        fin >> v[i];
    }
}
void ordon(int v[],int n)
{
    for(int i = 1;i < n;i++)
    {
        for(int j = i+1;j <=n;j++)
        {
            if(v[i] < v[j])
            {
                swap(v[i],v[j]);

            }
        }
    }
}
int suma(int v[],int k)
{
    int s=0;
    for(int i = 1;i<=k;i++)
    {
        s+=v[i];
    }
    return s;
}
void afisare(int b[],int n)
{
    for(int i = 1;i<n;i++)
    {
        for(int j = i+1;j <= n; j++)
        {
            if(b[i] == b[j])
            {
                fout << b[i] << " "<< b[j] << endl;
            }
        }
    }
    fout << endl;
}
void greedy(int a[],int n,int b[],int g)
{
    int i=1;
    int r= 0;
    while(i <= n)
    {
        int aux = g;
        r++;
        for(int j = 1;j <= n; j++)
        {
            if(a[j] <= aux && b[j] == 0)
            {
                b[j] = r;
                aux = aux - a[j];
                i++;
            }
        }
    }
}
int main()
{
    int n;
    fin >> n;
    int g;
    fin >> g;
    int a[50],b[50]={0};
    citire(a,n);
    ordon(a,n);
    greedy(a,n,b,g);
    afisare(b,n);
    return 0;
}
