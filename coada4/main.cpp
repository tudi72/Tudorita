#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("date.in");
ofstream fout("date.out");
struct nod
{
    int inf;
    nod *leg;
};
void adaugare(nod *&x,nod *&y,int nr)
{
    nod *p;
    p = new nod;
    p->leg = 0;
    p->inf = nr;
    if(x == 0)
    {
        x = y = p;
    }
    else
    {
        y->leg =p;
        y = p;
    }
}
void creare(nod *&x,nod *&y,int &k)
{
    int nr;
    x = NULL;
    while(fin >> nr && nr!=6)
    {
        k++;
        adaugare(x,y,nr);
    }
}
void afisare(nod *x)
{
    while(x!=NULL)
    {
        fout << x->inf << " ";
        x = x->leg;
    }
    fout << endl;
}
int main()
{
    nod *x,*y,*c,*d;
    int k = 0;
    creare(x,y,k);
    fout << k << endl;
    k = 0;
    creare(c,d,k);
    fout << k << endl;
    afisare(x);
    afisare(c);
    return 0;
}
