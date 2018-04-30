#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
ifstream fin("date.in");
ofstream fout("date.out");
struct nod
{
    char cap[500];
    nod *leg;
};
void adaugare(nod *&x,nod *&y,char cuv[])
{
    nod *p;
    p = new nod;
    strcpy(p->cap,cuv);
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
void creare(nod *&x,nod *&y)
{
    char cuv[500];
    x = NULL;
    while(fin.getline(cuv,500))
    {
        adaugare(x,y,cuv);
    }
}
void afisare(nod *x)
{
    while(x != NULL)
    {
        fout << x->cap << " ";
        x = x->leg;
    }
    fout << endl;
}
void perechi_acceasi_litera(nod *x)
{
    for(nod *p = x;p->leg!=NULL;p=p->leg)
    {
        for(nod *d=x;d!=NULL;d=d->leg)
        {
            if(p->cap[0] ==d->cap[0] && p!=d )
            {
                fout << p->cap << " " << d->cap << endl;
            }
        }
    }
}
int palindrom(char a[])
{
    for(int i = 0; i<strlen(a)/2;i++)
    {
        if(a[i] != a[strlen(a)-i-1])
            return 0;
    }
    return 1;
}
void afis_palindrom(nod *x)
{
    while(x !=NULL)
    {
        if(palindrom(x->cap)) fout << x->cap << " ";
        x = x->leg;
    }
}
int compare(char a[],char b[])
{
    int i = 0;
    while(i <strlen(a))
    {
        if(a[i] == b[i]) i++;
            else
        if(a[i] > b[i]) return 1;
            else return 0;
    }
}
void ordonare_alfabetica(nod *x)
{
    for(nod *a = x;a->leg!=NULL;a=a->leg)
    {
        for(nod *b= a->leg;b!=NULL;b=b->leg)
        {
            if(compare(a->cap,b->cap)) swap(a->cap,b->cap);
        }
    }
    afisare(x);
}
int main()
{
    nod *x,*y;
    creare(x,y);
    afis_palindrom(x);
    perechi_acceasi_litera(x);
    ordonare_alfabetica(x);
    return 0;
}
