#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("date.in");
ofstream fout("date.out");
void citire(int a[],int c[],int n)
{
    for(int i = 1;i<=n;i++)
    {
        fin >> a[i];
        c[i] = 1;
    }
}
void dinamica(int a[],int c[],int n)
{
    unsigned long long s;
    for(int i = 2;i <= n;i++)
    {
        s = 0;
        for(int j = 1;j < i; j++)
        {
            if(a[i] > a[j])
            {
                s = s + c[j];
            }
        }
        c[i] = c[i] + s;
    }
    int nr = 0;
    for(int i = 1;i <= n;i++)
    {
        nr = nr + c[i];
    }
    fout << "numarul de subsiruri egal:" << nr;
}
int main()
{
    int a[50],n;
    int c[50];
    fin >> n;
    citire(a,c,n);
    dinamica(a,c,n);
    return 0;
}
