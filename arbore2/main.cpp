#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("date.in");
ofstream fout("date.out");
void formare(int a[][10])
{
    int x,y;
    while(fin >> x >> y)
    {
        a[x][y] = 1;
        a[y][x] = 1;
    }
}
///arbore partial
void breadthsearch(int a[][10],int n,int x)
{
    int c[50]={0},viz[50]={0},p = 1,u = 1;
    viz[x] = 1;
    c[1] = x;
    int b[50]={0};
    while( p <= u)
    {
        for(int i = 1;i<=n;i++)
        {
            if(a[i][c[p]] == 1 && viz[i] == 0)
            {
                u++;
                c[u] = i;
                b[u] = c[p];
                //fout << c[p] << " " << i << endl;
                viz[i] = 1;
            }
        }
        p++;
    }
    for(int i = 1;i<=n;i++)
    {
        fout << b[i] << " ";
    }
}
int main()
{
    int a[10][10],n;
    fin >> n;
    formare(a);
    breadthsearch(a,n,1);
    return 0;
}
