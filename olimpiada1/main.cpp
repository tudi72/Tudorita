#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("date.in");
ofstream fout("date.out");
///  ora/valoare
struct cub
{
    int ora;
    int valoare;
}x[50];
int main()
{
    int n;
    fin >> n;
    int i = 1;
    while(i <= n)
    {
        fin >> x[i].ora >> x[i].valoare;
        i++;
    }
     cub aux;
    for(int i = 1;i< n;i++)
    {
        for(int j = i+1;j<=n;j++)
        {
            if(x[i].valoare < x[j].valoare)
            {
                aux = x[i];
                x[i] = x[j];
                x[j] = aux;

            }
        }
    }
    int nr = 0;
    int val = 0;
    i = 1;
    while(i <= n)
    {
        if(nr + x[i].ora <= 24 && nr <= x[i].ora)
        {
            nr++;
            val+=x[i].valoare;
        }
        i++;
    }
    fout << "valoare ceruta " << val;;
    return 0;
}
