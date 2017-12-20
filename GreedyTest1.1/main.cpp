#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("date.in");
ofstream fout("date.out");
///grad de vizibilitate
void citire(int a[],int n)
{
    for(int i = 1;i<=n;i++)
    {
        fin >> a[i];
    }
}

void greedy(int a[],int n)
{
    int nr = 0;
    int pas = 1;
    for(int i = 2;i<=n;i++)
    {
        if(a[pas] < a[i])
        {
            nr++;
            fout << a[pas] << " ";
            pas = i;
        }
        if(i == n)
        {
            nr++;
            fout << a[pas] << " ";
        }
    }
    fout << "gradul de vizibilitate este " << (float)nr/n;
}
int main()
{
    int a[50];
    int n;
    fin >> n;
    citire(a,n);
    greedy(a,n);
    return 0;
}
