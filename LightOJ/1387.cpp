#include<stdio.h>
#include<string.h>
int main()
{
    long long int i,r,n,t,m,k=0;
    char st[100];
    scanf("%lld",&t);
    for(r=1;r<=t;r++)
{
     scanf("%lld",&n);
     k=0;
     printf("Case %lld:\n",r);
    for(i=1;i<=n;i++)
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
}
return 0;
}

