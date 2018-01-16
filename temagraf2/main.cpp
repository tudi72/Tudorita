#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("date.in");
ofstream fout("date.out");
void citire(int a[][10],int n)
{
    int x,y;
    for(int i = 1;i<=n;i++)
    {
        fin >> x >> y;
        a[x][y] = 1;
        a[y][x] = 1;
    }
}
void afisare(int a[][10],int n)
{
    for(int i = 1;i<=n;i++)
    {
        for(int j = 1;j<=n;j++)
        {
            fout << a[i][j] << " ";
        }
        fout << endl;
    }
}
void adiacent(int a[][10],int n)
{
    for(int i = 1;i<=n;i++)
    {
        fout << i <<": ";
        for(int j = 1;j<=n;j++)
        {
            if(a[i][j] == 1)
            {
                if(a[i][j] == 1)
                    fout << j << " ";
            }
        }
        fout << endl;
    }
}
void generare(int a[][10],int n)
{
    int b[10][10]={0};
    int nr = 0;
    for(int i = 1;i<=n;i++)
    {
        for(int j =1;j<=n;j++)
        {
            if(a[i][j] == 1 && nr < 5 && i < j)
            {
                nr++;
                b[i][j] = 1;
            }
        }
    }
    afisare(b,n);
}
void nr_adiacent(int a[][10],int n,int &nr)
{
    for(int i = 1;i<=n;i++)
    {
        for(int j = 1;j<=n;j++)
        {
            if(i < j)
            {
                if(a[i][j] == 1)
                {
                    nr++;
                }
            }
        }
    }
    fout << "nr de adiacente = " << nr << endl;
}
void subgraf(int a[][10],int n)
{
    int b[10][10]={0};
    for(int i = 1;i<=4;i++)
    {
        for(int j = 1;j<=4;j++)
        {
            if(a[i][j] == 1)
            {
                b[i][j] = 1;
            }
        }
    }
    nr_adiacent(b,4,0);
    afisare(b,4);
}

int main()
{
    int a[10][10]={0},n,m;
    fin >> n >> m;
    citire(a,m);
    //afisare(a,n);
    //adiacent(a,n);
    //generare(a,n);
    //nr_adiacent(a,n);
    subgraf(a,n);
    int nr = 0;
    nr_adiacent(a,n,nr);

    return 0;
}
