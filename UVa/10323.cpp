#include<stdio.h>
int main()
{
    long long int i,j,k,l,n;
    while(scanf("%lld",&n)!=EOF)
    {
        if(n<0)
            i=n*-1;
        if(n<8&&n>=0)
            printf("Underflow!\n");
        else if(n>13)
            printf("Overflow!\n");
         else if(n<0)
        {
            if(i%2==0)
            printf("Underflow!\n");
            else if(i%2==1)
            printf("Overflow!\n");
        }
        else
        {
            k=1;
            for(i=2;i<=n;i++)
                k=k*i;
            printf("%lld\n",k);
        }
    }
    return 0;
}
