#include<stdio.h>
int main()
{
   long long int i,j,k,t,r,n,m;
    scanf("%lld",&t);
    for(r=1;r<=t;r++)
    {
        scanf("%lld %lld",&n,&m);
        k=n/(2*m);
        k=k*m*m;
        printf("Case %lld: %lld\n",r,k);
    }
    return 0;
}
