#include<stdio.h>
int main()
{
    long long int i,a,s,n,j,k;
    while(scanf("%lld %lld",&n,&a)!=EOF)
    {
        for(i=1,k=1,s=0;i<=n;i++)
        {
            k=k*a;
            s=s+(i*k);

        }
        printf("%lld\n",s);
    }
}
