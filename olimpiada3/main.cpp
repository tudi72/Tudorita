#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;
ifstream fin("date.in");
ofstream fout("date.out");
void sfincter(char a[],char b[],unsigned i,unsigned &j,int &ok)
{
    if(a[i] != b[j] && j < strlen(b))
    {
        j++;
        sfincter(a,b,i,j,ok);
    }
    else
    {
        if(j == strlen(b)) ok = 1;
        if(a[i] == b[j]) ok = 2;
    }

}
void marakesh(char a[],char b[],int &pas)
{
    if(a[strlen(a)-pas] == b[strlen(b)-pas])
    {
        pas++;
        marakesh(a,b,pas);
    }
}
void barbat(char a[],char b[],unsigned &i,unsigned &j)
{
    if(a[i] == '*' || a[i] == '?')
    {
        if(a[i] == '?') j++;
        i++;
        barbat(a,b,i,j);
    }
}
void compare(char a[],char b[],unsigned i,unsigned j,int pas,int &bine)
{
    if(i == strlen(a)-1 && a[i] == '*' && bine == 1)
    {
        bine = 2;
        compare(a,b,i,j,pas,bine);
    }
    else
    if(a[i] == b[j] && bine == 1)
    {
         compare(a,b,i+1,j+1,pas,bine);
    }
    else if(a[i] == '*' && bine == 1)
    {
        int ok = 0;
        if(a[i+1] != '*' && a[i+1] != '?')
        {
            sfincter(a,b,i,j,ok);
        }
        else barbat(a,b,i,j);
        {
            sfincter(a,b,i,j,ok);
        }
        if(ok == 2)
        {
            compare(a,b,i,j,pas,bine);
        }
        else if(ok == 1)
        {
            bine = 0;
            compare(a,b,i,j,pas,bine);
        }
    }
    else if(a[i] == '?' && bine == 1)
    {
        return compare(a,b,i+1,j+1,pas,bine);
    }
    else if(a[i] != b[j] && (a[i] != '*' && a[i]!='?') && bine == 1 && j < strlen(b))
                {
                    bine = 0;
                    compare(a,b,i,j,pas,bine);
                }
}
int main()
{
    char a[50];
    char b[50];
    fin >> a;
    while(fin >> b)
    {
        int bine = 1;
        compare(a,b,0,0,0,bine);
        fout << bine << endl;
    }

    return 0;
}
