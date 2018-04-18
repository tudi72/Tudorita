#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("date.in");
ofstream fout("date.out");
void formare(int a[][100],int m)
{
    int x,y;
    for(int i = 1;i<=m;i++)
    {
        fin >> x >> y;
        a[x][y] = 1;
    }
}
void bf(int a[][100],int viz[],int n,int x,int &nr)
{
    int c[500],p = 1,u= 1;
    viz[x] = nr;
    c[1] = x;
    while(p <= u)
    {
        for(int i = 1;i<=n;i++)
        {
            if(a[c[p]][i] == 1 && viz[i] == 0)
            {
                c[u++] = i;
                viz[i] = nr;
            }
        }
        p++;
    }
}
void comp_conex(int a[][100],int viz[],int n)
{
    int nr = 0;
    for(int i = 1;i<=n;i++)
    {
        if(viz[i] == 0)
        {
            nr++;
            bf(a,viz,n,i,nr);
        }
    }
}
int main()
{
    int a[100][100]={0},n,m,k,viz[500]={0};
    fin >> n >> m;
    formare(a,m);
    fin >> k;
    comp_conex(a,viz,n);
    for(int i = 1;i<=n;i++)
    {
        if(viz[k] == viz[i] && i!=k) fout << i << " ";
    }
    return 0;
}
