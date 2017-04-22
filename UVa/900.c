#include<stdio.h>

int main()
{
   long long int l,n,i,j,k;
    while(scanf("%lld",&n)!=EOF)
    {
        if(n==0)
            break;
            l=1;
        for(i=1;i<=n;i++)
        {
            if(i==1)
                {
                    l=1;j=1;
                }
            else if(i==2)
                {
                    l=2;k=2;
                }
            else
            {
                l=j+k;
                j=k;
                k=l;
            }
        }

        printf("%lld\n",l);
    }
    return 0;
}
