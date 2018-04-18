#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("date.in");
ofstream fout("date.out");
void formare(int a[][100],int m,int &mn)
{
    int x,y,z;
    for(int i = 1;i<=m;i++)
    {
        fin >> x >> y >> z;
        a[x][y] = z;
        mn+= z;
    }
}
void afisare(int a[][100],int n)
{
    for(int i = 1;i<=n;i++)
    {
        for(int j = 1;j<=n;j++)
        {
            fout << a[i][j] << " ";
        }
        fout << endl;
    }
    fout << endl;
}


void roy_warshall(int a[][100],int n)
{
    for(int k = 1;k<=n;k++)
    {
        for(int i = 1;i<=n;i++)
        {
            for(int j = 1;j<=n;j++)
            {
                if(a[i][j] > a[i][k]+a[k][j] && a[i][k] > 0 && a[k][j] > 0 && i!=k && j!=k && i!=j)
                {
                    a[i][j] = a[i][k]+a[k][j];
                }
            }
        }
    }
}
int verificare(int b[],int pas,int y)
{
    for(int i = 1;i<=pas;i++)
    {
        if(b[i] ==y) return 1;
    }
    return 0;
}
int total(int a[][100],int b[],int pas)
{
    int cost = 0;
    for(int i = 2;i<=pas;i++)
    {
        cost+=a[b[i-1]][b[i]];
    }
    return cost;
}
void backtraking(int a[][100],int b[],int c[],int n,int x,int y,int &mn,int &sac,int pas)
{
    for(int i = 1;i<=n;i++)
    {
        b[pas] = i;
        if(a[b[pas-1]][b[pas]] !=0)
        {
            if(b[pas] == x)
            {
                if(verificare(b,pas,y))
                {
                    if(mn > total(a,b,pas))
                    {
                        for(int j = 1;j<=pas;j++)
                        {
                            c[j] = b[j];
                        }
                        mn = total(a,b,pas);
                        sac = pas;
                    }
                }
            } else if(pas <= n) backtraking(a,b,c,n,x,y,mn,sac,pas+1);
        }
    }
}
int main()
{
    int a[100][100]={0},n,m,x,y,b[500],mn = 0;
    fin >> n >> m;
    formare(a,m,mn);
    fin >> x >> y;
    int c[500];
    b[1] = x;
    int sac;
    backtraking(a,b,c,n,x,y,mn,sac,2);
    fout << "costul este egal: " << mn << endl;
    for(int i = 1;i<=sac;i++)
    {
        fout << c[i] << " ";
    }
    fout << endl;
    return 0;
}
