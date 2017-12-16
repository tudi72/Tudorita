#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
ifstream fin("date.in");
ofstream fout("date.out");
void citire(int a[],int n)
{
    for(int i = 1;i<=n;i++)
    {
        fin >> a[i];
    }
}
void afisare(int a[],int n)
{
    for(int i = 1;i<=n;i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
void ordonare(int a[],int n)
{
    for(int i = 1;i< n;i++)
    {
        for(int j =i+1;j<=n;j++)
        {
            if(a[i] > a[j])
            {
                swap(a[i],a[j]);
            }
        }
    }
}
void greedy(int a[],int b[],int n,int m)
{
    int pas = 1;
    int i = 1;
    while(i <= n)
    {
        if(pas <= m)
        {
            if(abs(a[i]-b[pas])!= 1)
            {
                while(abs(a[i]-b[pas])!= 1)
                {
                    pas++;
                }
            }
            if(abs(a[i]-b[pas])== 1)
            {
                fout << " (" << a[i] <<","<< b[pas] <<") ";
                pas = 1;
            }
        }
        i++;
    }
}
int main()
{
    int a[50],b[50],n,m;
    fin >> n >> m;
    citire(a,n);
    citire(b,m);
    ordonare(a,n);
    ordonare(b,m);
    afisare(a,n);
    afisare(b,m);
    if(n < m)
    {
        greedy(a,b,n,m);
    }
    else greedy(a,b,m,n);
    return 0;
}
