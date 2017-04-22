#include<stdio.h>
int main()
{
    long long int t,r,d,h,b,m,n,i,j,k;
    scanf("%lld",&t);
    for(r=0;r<t;r++)
    {
        scanf("%lld",&d);
        h=d;m=0;n=0;
        while(d!=0)
        {
            if(d%2==1)
                m++;
            d/=2;
        }
        i=1;d=0;
        while(h!=0)
        {
            k=h%10;
            d=d+(k*i);
            i*=16;
            h/=10;
        }
        while(d!=0)
        {
            if(d%2==1)
                n++;
            d/=2;
        }
        printf("%lld %lld\n",m,n);
    }
    return 0;
}
