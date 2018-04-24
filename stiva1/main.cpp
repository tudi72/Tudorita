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
void adaugare(nod *&vf,int x)
{
    nod *p;
    p = new nod;
    p->inf = x;
    p->leg = vf;
    vf = p;
}
void creare(nod *&vf)
{
    int x;
    while(fin >> x)
    {
        adaugare(vf,x);
    }
}
void afisare(nod *vf)
{
    while(vf->leg != NULL)
    {
        fout << vf->inf<< " ";
        vf= vf->leg;
    }
    fout << endl;
}

void ster_prim_element(nod *vf)
{
    while(vf->leg->leg != NULL)
    {
        vf= vf->leg;
    }
    vf->leg = NULL;
    delete vf;
}
void sterg_ultim_elem(nod *vf,nod *&p)
{
    nod *aux = vf;
    vf = vf->leg;
    while(vf->leg !=NULL)
    {
        adaugare(p,vf->inf);
        vf = vf->leg;
    }
    aux->leg = NULL;
    delete aux;
}
void afisare2(int v[],int nr)
{
    for(int i = 1;i<nr;i++)
    {
        fout << v[i] << " ";
    }
    fout << endl;
}
void rearanjare_impare_inceput(nod *vf,int v[],int &nr)
{
    nr = 1;
   while(vf->leg != NULL)
   {
       v[nr++] = vf->inf;
       vf = vf->leg;
   }
    for(int i = 1;i< nr;i++)
    {
        for(int j = i+1;j<= nr;j++)
        {
            if((v[i]%2 == 0 && v[j]%2 == 1))
            {
                swap(v[i],v[j]);
            }
        }
    }
}
void adaugare_prima_stiva_la_a_doua(nod *vf,nod *p)
{
    for(nod *k = p;k->leg!=NULL;k = k->leg)
    {
        adaugare(vf,p->inf);
    }
}
void metoda_2(nod *vf)
{
    for(nod *k = vf;k->leg!=NULL;k=k->leg)
    {
        for(nod *p=k->leg;p!=NULL;p=p->leg)
        {
            if(k->inf %2 == 0 && p->inf %2 == 1)
            {
                swap(k->inf,p->inf);
            }
        }
    }
}
void comprimare(nod *vf,int v[],int nr)
{
    int i = 1;
    while(i < nr)
    {
        vf->inf = v[i];
        vf= vf->leg;
        i++;
    }
}
int main()
{
    nod *vf;
    nod *p;
    p = new nod;
    p->leg = NULL;
    vf = new nod;
    vf->leg = NULL;
    creare(vf);
    afisare(vf);
    int nr,v[500]={0};
    metoda_2(vf);
    rearanjare_impare_inceput(vf,v,nr);
    comprimare(vf,v,nr);
    adaugare_prima_stiva_la_a_doua(vf,p);
    afisare(vf);
    fout << vf->inf;
    return 0;
}
