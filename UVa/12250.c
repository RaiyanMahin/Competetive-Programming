#include<stdio.h>
#include<string.h>
int main()
{
    int i=1,j,k,l;
    char st[20];
    while(scanf("%s",st)!=EOF)
    {
        if(!strcmp(st,"#"))
            break;
        if(!strcmp(st,"HELLO"))
            printf("Case %d: ENGLISH\n",i);
        else if(!strcmp(st,"HOLA"))
            printf("Case %d: SPANISH\n",i);
         else if(!strcmp(st,"HALLO"))
            printf("Case %d: GERMAN\n",i);
         else if(!strcmp(st,"BONJOUR"))
            printf("Case %d: FRENCH\n",i);
         else if(!strcmp(st,"CIAO"))
            printf("Case %d: ITALIAN\n",i);
             else if(!strcmp(st,"ZDRAVSTVUJTE"))
            printf("Case %d: RUSSIAN\n",i);
         else
            printf("Case %d: UNKNOWN\n",i);
        i++;
    }
    return 0;
}
