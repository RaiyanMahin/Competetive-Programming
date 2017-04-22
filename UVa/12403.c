#include<stdio.h>
#include<string.h>
int main()
{
    long long int i,t,m,k=0;
    char st[100];
    scanf("%lld",&t);
    getchar();
    for(i=1;i<=t;i++)
    {
        scanf("%s",st);
        if(strcmp(st,"donate")==0)
        {
            scanf("%lld",&m);
            k=k+m;
        }
         if(strcmp(st,"report")==0)
        {
            printf("%lld\n",k);
        }
    }
return 0;
}
