#include<stdio.h>
#include<string.h>
int main()
{
    long long int i,t,r,a,b,m,n,ar;

    scanf("%lld",&t);
    for(r=1;r<=t;r++)
    {
        scanf("%lld ",&n);m=0;
        for(i=0;i<n;i++)
            {
                scanf("%lld",&ar);
                if(ar>0)
                m=m+ar;
            }
        printf("Case %lld: %lld\n",r,m);
    }
    return 0;
}
