#include<stdio.h>
#include<math.h>
int main()
{
    long long int i,t,r,j,k,n,m,w;
    scanf("%lld",&t);
    for(r=1;r<=t;r++)
    {
        scanf("%lld",&w);


        if(w%2!=0)
            printf("Case %lld: Impossible\n",r);
        else
            {
                n=1;
                while(w%2==0)
                {
                    w=w/2;
                    n=n*2;
                }
                printf("Case %lld: %lld %lld\n",r,w,n);
            }

    }
    return 0;
}
