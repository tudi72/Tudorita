#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("date.in");
ofstream fout("date.out");
int di[] ={1,-1,0,0};
int dj[] ={0,0,1,-1};
int dir[] ={12,13,14,15};
void citire(int a[][10],int n,int m)
{
    for(int i = 1;i<=n;i++)
    {
        for(int j = 1;j<=m;j++)
        {
            fin >> a[i][j];
        }
    }
}
void afisare(int a[][10],int n,int m)
{
    for(int i = 1;i<=n;i++)
    {
        for(int j = 1;j<=m;j++)
        {
            if(a[i][j] == 12) fout << "v" << " ";
            else if(a[i][j] == 13) fout << "^"<< " ";
            else if(a[i][j] == 14) fout << ">" << " ";
            else if(a[i][j] == 15) fout << "<" << " ";
            else if(a[i][j] == 1) fout << "X" << " ";
            else if(a[i][j] == 0) fout << "." << " ";
            else if(a[i][j] == -1) fout << "H"<< " ";
                else fout << a[i][j] << " ";
         }
        fout << endl;
    }
    fout << endl;
}

void backtrack(int a[][10],int b[][10],int n,int m,int x,int y,int &ok)
{
    if(ok <= 0)
        {
            int inou,jnou;
            for(int i = 0;i<=4;i++)
            {
                inou = di[i] + x;
                jnou = dj[i] + y;
                if(inou <= n && inou >= 1 && jnou <= m && jnou >= 1)
                {
                    if(b[inou][jnou] == 0)
                    {
                        int aux = b[x][y];
                        if(a[inou][jnou] == -1 )
                        {
                            ok++;
                            b[x][y] = dir[i];
                            b[inou][jnou] = 9;
                            afisare(b,n,m);
                        }
                        if(a[inou][jnou] == 0 || a[inou][jnou] == 1)
                        {
                            b[x][y] = dir[i];
                            backtrack(a,b,n,m,inou,jnou,ok);
                           // b[x][y] = aux;
                        }
                    }
                }
            }
    }
}
void formosa(int a[][10],int b[][10],int n,int m)
{
    for(int i = 1;i<=n;i++)
    {
        for(int j = 1;j<=m;j++)
        {
            if(a[i][j] >= 2)
                {
                    int ok = 0;
                    backtrack(a,b,n,m,i,j,ok);
                    ok = 0;
                }
        }
    }
}
int main()
{
    int a[10][10];
    int n,m;
    int b[10][10]={0};
    fin >> n >> m;
    citire(a,n,m);
    formosa(a,b,n,m);
    return 0;
}
