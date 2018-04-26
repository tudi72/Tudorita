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
void adaug(nod *&x,nod *&y,int nr)
{
    nod *p;
    p = new nod;
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
void creare(nod *&x,nod *&y)
{
    int nr,n;
    fin >> n;
    x = NULL;
    for(int i = 1;i <= n;i++)
    {
        fin >> nr;
        adaug(x,y,nr);
    }
}
void afisare(nod *x)
{
    while(x != NULL)
    {
        fout<<x->inf<<" ";
        x = x->leg;
    }
    fout<<endl;
}
void note_succesoare(nod *x)
{
    int ok = 0;
    while(x !=NULL)
    {
        if(x->inf == 4 && x->leg->inf ==10) ok = 1;
        x = x->leg;
    }
    if(ok == 1) fout << "am gasit";
        else fout << "nu am gasit";
        fout << endl;
}
void medie_si_teza(nod *x)
{
    int m = 0;
    int c = 0;
    while(x->leg != NULL)
    {
        m = m+x->inf;
        c++;
        x = x->leg;
    }
    fout <<endl << "media: " << float(((m/c)*3+x->inf)/4);
}
int main()
{
    nod *x,*y;
    creare(x,y);
    afisare(x);
    note_succesoare(x);
    medie_si_teza(x);
    return 0;
}
