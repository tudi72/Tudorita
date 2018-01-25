#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("date.in");
ofstream fout("date.out");
///toate nodurile de lungime k
void citire(int a[][20],int m)
{
    int x,y;
    for(int i= 1;i<=m;i++)
    {
        fin >> x >> y;
        a[x][y] = 1;
        a[y][x] = 1;
    }
}
int verificare(int a[][20],int b[],int n,int pas)
{
    for(int i = 2;i<=pas;i++)
    {
        if(b[i-1] == b[i]) return 0;
        if(a[b[i-1]][b[i]] != 1 && b[i-1] != b[i]) return 0;
    }
    return 1;
}
void bak(int a[][20],int b[],int n,int k,int pas)
{
    for(int i = 1;i<=n;i++)
    {
        b[pas] = i;
        if(verificare(a,b,n,pas) == 1)
        {
            if(k+1 == pas)
            {
                for(int i = 1;i<=pas;i++)
                {
                    fout << b[i] << " ";
                }
                fout << endl;
            }
            else bak(a,b,n,k,pas+1);
        }
    }
}
int main()
{
    int a[20][20] = {0};
    int b[50] = {0};
    int n,m,k;
    fin >> n >> m >> k;
    citire(a,m);
    b[1] = 1;
    bak(a,b,n,k,2);
    return 0;
}
