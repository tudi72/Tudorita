#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;
ifstream fin("date.in");
ofstream fout("date.out");
int compare(char a[],char b[])
{
    int i = 0;
    int j = 0;
    while(i < strlen(b) && j < strlen(a))
    {
        if(b[i] == a[j])
            {
                i++;
                j++;
            }
            else if(b[i] != a[j])
            {
                if(a[j] == '*')
                {
                    if(a[j+1] == '?')
                    {
                        j= j+2;
                        while(a[j] != b[i] && i <= strlen(b)) i++;
                        if(strlen(b) == i) return 0;
                    }
                    else
                    {
                        j++;
                        while(a[j] != b[i] && i <= strlen(b)) i++;
                        if(strlen(b) == i) return 0;
                    }

                }
                else if(a[j] == '?')
                {
                    j++;
                    i++;
                }
            }
            else return 0;
    }
    return 1;
}
int main()
{
    char a[50];
    char b[50];
    fin >> a;
    while(fin >> b)
        fout << compare(a,b);
    return 0;
}
