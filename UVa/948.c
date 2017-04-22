#include<stdio.h>
int main()
{
    long long int i,t,r,n,j,k,l,ar[100],m[100];
    ar[0]=1;ar[1]=2;
    for(i=2;i<50;i++)
    {
        ar[i]=ar[i-1]+ar[i-2];

    }
    scanf("%lld",&t);
    for(r=1;r<=t;r++)
    {
        scanf("%lld",&n);
        k=n;l=0;
        printf("%lld = ",n);
        if(n<=0)
            printf("0");
        else
        for(i=49;i>=0;i--)
        {
            if(k>=ar[i]&&k<ar[i+1])
            {
                k=k-ar[i];
                printf("1");
                l=1;
            }
            else if(l==1)
                printf("0");
        }
        printf(" (fib)\n");
    }
return 0;

}
