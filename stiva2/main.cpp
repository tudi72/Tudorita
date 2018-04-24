#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
ifstream fin("date.in");
ofstream fout("date.out");
struct nod
{
    char x[500];
    nod *leg;
};
void adaugare(nod *&vf,char cuv[])
{
    nod *p;
    p = new nod;
    strcpy(p->x,cuv);
    p->leg = vf;
    vf = p;
}
void creare(nod *&vf)
{
    char x[500];
    while(fin.getline(x,500))
    {
        adaugare(vf,x);
        adaugare(vf," ");
    }
}
void afisare(nod *vf)
{
    while(vf->leg != NULL)
    {
        fout <<vf->x;
        vf = vf->leg;
    }
    fout << endl << endl;
}
void incepe_cu_vocala(nod *vf)
{
    while(vf->leg!=NULL)
    {
        if(strchr("AEIOUaeiou",vf->x[0])!= 0)
        {
            fout << vf->x << endl;
        }
        vf = vf->leg;
    }
}
bool compare_rima(char a[],char b[])
{
    if(strchr(a,a[strlen(a)-2]) == strchr(b,b[strlen(b)-2]))
    {
        if(strchr(a,a[strlen(a)-1]) == strchr(b,b[strlen(b)-1]))
        {
            return 1;
        }
        else return 0;
    }
    else return 0;
}
void cuvinte_rimate(nod *vf)
{
    while(vf->leg != NULL)
    {
        if(compare_rima(vf->x,vf->leg->x) == 1)
        {
            fout << vf->x << " " << vf->leg->x << endl;
        }
            vf = vf->leg;
    }
    fout << endl;
}
int main()
{
    nod *vf;
    vf = new nod;
    vf->leg = NULL;
    creare(vf);
    //afisare(vf);
    //cuvinte_rimate(vf);
    fout << strchr(vf->x,vf->x[strlen(vf->x)-2]);
    return 0;
}
