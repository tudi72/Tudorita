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
    nod *p = new nod;
    p->inf = nr;
    p->leg = 0;
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
void adaugare_inceput(nod *&x,int nr)
{
    nod *p = new nod;
    p->inf = nr;
    p->leg = x;
    x = p;
}
void creare(nod *&x,nod *&y)
{
    x = NULL;
    int nr;
    while(fin >> nr)
    {
        adaugare(x,y,nr);
    }
}
void eliminare(nod *x)
{
    nod *p = x;
    while(p->leg != NULL)
    {
        for(nod *d = x;d!= NULL;d = d->leg)
        {
            if(d->inf == p->leg->inf && d != p->leg)
            {
                nod *aux = p->leg;
                p->leg = p->leg->leg;
                delete aux;
            }
        }
        p = p->leg;
    }
}
void adaug_la_inceput(nod *&a,nod *x)
{
    a = NULL;
    while(x !=NULL)
    {
        adaugare_inceput(a,x->inf);
        x = x->leg;
    }
}
void verificare(nod *x,nod *a)
{
    int ok = 1;
    while(x!=NULL)
    {
        if(x->inf != a->inf)
        {
            ok = 0;
        }
        x = x->leg;
        a = a->leg;
    }
    if( ok == 0) fout << " nu";
        else fout << " da";
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
int binar(int nr)
{
    int aux = 1;
    while(nr > 0)
    {
        aux = aux*10 + nr%2;
        nr = nr/2;
    }
    return aux;
}
void adag_cifra_complementara(nod *x)
{
    nod *p = x;
    while(p->leg != NULL)
    {
        nod *c = new nod;
        c->inf = binar(p->leg->inf);
        c->leg = p->leg;
        p->leg = c;
        p = p->leg->leg;
    }
}
void permut_circular(nod *x,int k)
{
    int aux;
    nod *p = x;
    while(k > 0)
    {
        p = x;
        aux = p->inf;
        while(p->leg != NULL)
        {
            p->inf = p->leg->inf;
            p = p->leg;
        }
        p->inf = aux;
        afisare(x);
        k--;
    }
}
void descompun_in_suma(nod *x)
{
    int aux = x->inf;
    while(x->leg!=NULL)
    {
        x = x->leg;
    }
}
int main()
{
    nod *x,*y,*a;
    creare(x,y);
    permut_circular(x,3);
    return 0;
}
