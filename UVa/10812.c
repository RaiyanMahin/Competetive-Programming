#include<stdio.h>
int main()
{
    long long i,t,x,y,h,d;
    scanf("%lld",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%lld %lld",&h,&d);
        if(d>h)
        {
            printf("impossible\n");
        }
        else
        {
            x=(d+h)/2;
            y=h-x;
            if(x-y!=d)
                printf("impossible\n");
            else
            printf("%lld %lld\n",x,y);
        }
    }
    return 0;
}
