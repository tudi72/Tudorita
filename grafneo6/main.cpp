#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("date.in");
ofstream fout("date.out");
void formare(int a[][10],int m)
{
    int x,y;
    for(int i = 1;i<=m;i++)
    {
        fin >> x >> y;
        a[x][y] = 1;
        a[y][x] = 1;
    }
}
///metoda conexitatii
void breadthsearch(int a[][10],int n,int x,int &ok)
{
    int c[20],viz[20]={0};
    c[1] = x;
    viz[x] = 1;
    int p = 1;
    int u = 1;
    while(p <= u)
    {
        for(int i = 1;i<=n;i++)
        {
            if(a[i][c[p]] == 1 && viz[i] == 0)
            {
                u++;
                c[u] = i;
                viz[i] = 1;
            }
        }
        p++;
    }
    for(int i = 1;i<=n;i++)
    {
        if(viz[i] == 0) ok = 0;
    }
}
int grad(int a[][10],int n,int x)
{
    int s = 0;
    for(int i = 1;i<=n;i++)
    {
        if(a[i][x] == 1)
        {
            s++;
        }
    }
    return s;
}
int gradut(int a[][10],int n)
{
    int ok = 1;
    for(int i = 1;i<=n;i++)
    {
        if(grad(a,n,i) %2 != 0) return 0;
        breadthsearch(a,n,1,ok);
        if(ok == 0) return 0;
    }
    return 1;
}
int main()
{
    int a[10][10],n,m;
    fin >> n >> m;
    formare(a,m);
    fout << gradut(a,n);
    return 0;
}
