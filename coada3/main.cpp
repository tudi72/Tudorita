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
        y->leg = p;
        y = p;
    }
}
void creare(nod *&x,nod *&y,int &k)
{
    x = NULL;
    int nr;
    while(fin >> nr)
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
void schimbare_coada(nod *x,nod *&a,nod *&b,nod *&c,nod *&d,int nr)
{
    a = NULL;
    int i  = 0;
    while(i < nr/3)
    {
        x =x->leg;
        i++;
    }
    int j = 0;
    while(j< nr/3)
    {
        adaugare(a,b,x->inf);
        x = x->leg;
        j++;
    }
    c = NULL;
    while(x !=NULL)
    {
        adaugare(c,d,x->inf);
        x = x->leg;
    }
}
void sterg(nod *x,nod *a)
{
    while(x->leg->inf != a->inf)
    {
        x = x->leg;
    }
    x->leg = NULL;
}
int main()
{
    nod *x,*y,*a,*b,*c,*d;
    int k = 0;
    creare(x,y,k);
    fout << k << endl;
    schimbare_coada(x,a,b,c,d,k);
    sterg(x,a);
    afisare(x);
    afisare(a);
    afisare(c);
    return 0;
}
