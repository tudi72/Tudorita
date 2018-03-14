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
    }
}
void bf(int a[][10],int viz[],int n,int x,int &nr)
{
    int c[50],p,u;
    p = u = 1;
    viz[x] = nr;
     c[p] = x;
     int aux = c[p];
    int i = 1;
    fout << aux << " ";
    while(i <= n)
    {
        if(a[c[p]][i] == 1 && viz[i] == 0)
        {
            c[p] = i;
            fout << i << " ";
            viz[i] = nr;
            i = 1;
        }
        else i++;
    }
    fout << endl;
}
void comp_conex(int a[][10],int viz[],int n)
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
void inlaturare(int a[][10],int n)
{
    int viz[50]={0};
    comp_conex(a,viz,n);
    for(int i = 1;i<=n;i++)
    {
        for(int j = 1;j<=n;j++)
        {
            if(a[i][j] == 1 )
            {
                if(viz[i] != viz[j])
                {
                    fout << i << " " << j << endl;
                }
            }
        }
    }
}
int main()
{
    int a[10][10]={0},n,m;
    fin >> n >> m;
    formare(a,m);
    inlaturare(a,n);
    return 0;
}
