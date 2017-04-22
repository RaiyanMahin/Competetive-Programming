#include<stdio.h>
#include<string.h>
int main()
{
    int i,j,k,l;
    char ch[200],c[100000];

    while(gets(c))
    {
        i=strlen(c);
        ch['=']='-';ch['-']='0';ch['0']='9';ch['9']='8';ch['8']='7';ch['7']='6';ch['6']='5';ch['5']='4';ch['4']='3';ch['3']='2';ch['2']='1';ch['1']='`';
        ch['`']='`';ch['\\']=']';ch[']']='[';ch['[']='P';ch['P']='O';ch['O']='I';ch['I']='U';ch['U']='Y';ch['Y']='T';ch['T']='R';ch['R']='E';ch['E']='W';ch['W']='Q';ch['Q']='Q';ch['\'']=';';
        ch[';']='L';ch['L']='K';ch['K']='J';ch['J']='H';ch['H']='G';ch['G']='F';ch['F']='D';ch['D']='S';ch['S']='A';ch['A']='A';ch['/']='.';ch['.']=',';ch[',']='M';
        ch['M']='N';ch['N']='B';ch['B']='V';ch['V']='C';ch['C']='X';ch['X']='Z';ch['Z']='Z';ch[' ']=' ';
        for(k=0;k<i;k++)
           {
               if(c[k]=='\\')
               {
                   if(c[k]=='\\'&&c[k+1]=='\\')
                   {
                        printf("%c",ch[c[k]]);k++;
                   }
               }
               else
                printf("%c",ch[c[k]]);
           }
            printf("\n");
        }
        return 0;
}
