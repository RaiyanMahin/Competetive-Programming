#include<stdio.h>
int main()
{
    long long int r,t,i,g,l,a,b;
    scanf("%lld",&t);
    for(r=0;r<t;r++)
    {
        scanf("%lld %lld",&a,&b);
        if((b%a==0)&&((b*a)/a)&&a!=0&&b!=0)
            printf("%lld %lld\n",a,b);
        else
            printf("-1\n");
    }
    return 0;
}
