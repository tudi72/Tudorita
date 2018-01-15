#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("date.in");
ofstream fout("date.out");
void citire(int a[][10],int n)
{
    for(int i = 1;i<=n;i++)
    {
        for(int j = 1; j<=n;j++)
        {
            fin >> a[i][j];
        }
    }
}
void afisare(int a[][10],int n)
{
    int i=1;
    int j = 1;
    while(i <= n)
    {
        j = 1;
        while(j <= n)
        {
            if(i < j)
            {
                if(a[i][j] == 1) fout << i << " "<< j << endl;
            }
            j++;
        }
        i++;
    }
}
int main()
{
    int a[10][10],n;
    fin >> n;
    citire(a,n);
    afisare(a,n);
    return 0;
}
