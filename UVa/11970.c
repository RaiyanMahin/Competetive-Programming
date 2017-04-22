#include<stdio.h>
#include<math.h>
int main()
{
    long long int l,n,x,i,j,k,t,r;
    scanf("%lld",&t);
    for(r=1;r<=t;r++)
    {
        scanf("%lld",&n);
        k=sqrt(n);
        printf("Case %lld:",r);
        for(i=k;i>=1;i--)
        {
            x=n-(i*i);
            if(x%i==0&&x!=0)
                printf(" %lld",x);
        }
        printf("\n");
    }
    return 0;
}
