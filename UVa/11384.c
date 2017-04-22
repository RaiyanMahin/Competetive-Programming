#include<stdio.h>
int main()
{
    long long int i,j,k,n,m;
    while(scanf("%lld",&n)!=EOF)
    {
        m=1;k=0;
        for(i=1;i<100;i++)
        {
             if(n>k&&n<=m)
                break;
            k=m;
            m=m+(m*2);

        }
        printf("%lld\n",i);
    }

}
