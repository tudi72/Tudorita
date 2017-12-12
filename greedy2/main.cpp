#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
ifstream fin("date.in");
ofstream fout("date.out");
void ordonare(int a[],int n)
{
    for(int i = 1;i < n;i++)
    {
        for(int j = i+1;j <= n;j++)
        {
            if(a[i] < a[j])
            {
                swap(a[i],a[j]);
            }
        }
    }
}
void greedy(int a[],int n)
{
 if(a[1]*a[2] > a[n]*a[n-1])
 {
     fout << a[1] << " " << a[2];
 }
 else fout << a[n] << " " << a[n-1];
}
void afisare(int a[],int n)
{
    for(int i = 1;i<=n;i++)
    {
        fout << a[i] << " ";
    }
    fout << endl;
}
int main()
{
    int a[40],n;
    fin >> n;
    for(int i= 1;i<=n;i++)
    {
        fin >> a[i];
    }
    ordonare(a,n);
    greedy(a,n);
    return 0;
}
