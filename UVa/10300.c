#include<stdio.h>
int main()
{
    int t,i;
    long long int p,f,s[30],d[30],a[30],j,k,l,m,n;
    while(scanf("%d",&t)!=EOF){

    for(i=0;i<t;i++)
    {
        scanf("%lld",&f);
        p=0;m=1;

        for(j=1;j<=f;j++)
        {
            scanf("%lld",&s[j]);

            scanf("%lld",&a[j]);

            scanf("%lld",&d[j]);

        }

        for(j=1;j<=f;j++)
            p=p+(s[j]*d[j]);
            printf("%lld\n",p);
    }
    }
    return 0;
}
