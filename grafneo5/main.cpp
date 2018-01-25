#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("date.in");
ofstream fout("date.out");
///sa aflu lantul minim(
int verificare(int b[],int a[][10],int pas)
{
    for(int i = 2;i<= pas;i++)
    {
        if(b[i-1] == b[i]) return 0;
        if(a[b[i]][b[i-1]] != 1) return 0;
    }
    return 1;
}
int copiere(int b[],int pas)
{
    for(int i = 2;i < pas;i++)
        if(b[i-1] == b[i+1]) return 0;
    return 1;
}

/// sa afisam toate lanturile cele mai scurte dintre ele
void taru_san(int a[][10],int b[],int n,int pas,int y)
{
    for(int i = 1;i<= n;i++)
    {
        b[pas] = i;
        if(verificare(b,a,pas) == 1 && pas > 1)
        {
            if(b[pas] == y && copiere(b,pas) == 1)
            {
                for(int i = 1;i <= pas; i++)
                {
                    fout << b[i] << " ";
                }
                fout << endl;

            }
            else taru_san(a,b,n,pas+1,y);
        }
        //else taru_san(a,b,n,pas+1,y);
    }
}
int main()
{
    int a[10][10]={0},n,m,x,y;
    fin >> n >> m >> x >> y;

    int p,q;
    for(int i = 1;i<=m;i++)
    {
        fin >> p >> q;
        a[p][q] = 1;
        a[q][p] = 1;
    }
    int b[50];
    b[1] = x;
    taru_san(a,b,n,2,y);
    return 0;
}
