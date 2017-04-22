#include<stdio.h>
#include<string.h>
int main()
{
    int i,j,k,l,m,n,e,o,s;
    char st[2000];
    while(scanf("%s",st)!=EOF)
    {
        l=strlen(st);
        e=0;s=0;o=0;
        for(i=0;i<l;i++)
        {
            s=s+(st[i]-48);
            if(i%2==0)
                e=e+(st[i]-48);
            else
                o=o+(st[i]-48);
        }
        if(s==0)
            break;
        if(e-o==0||(e-o)%11==0)
            printf("%s is a multiple of 11.\n",st);
        else
             printf("%s is not a multiple of 11.\n",st);
    }
   return 0;
}
