#include<stdio.h>
#include<math.h>

int main()
{
    long long int i,j,k,s,n,m,a;
    while(scanf("%lld",&n)!=EOF)
    {
        s=sqrt(n);m=0;a=1;
        for(i=2;i<=s;i++)
        {
            if(n%i==0)
            {
                m=1;break;

            }
        }
        if(m==0)
        {
            a=n;k=0;
            while(a!=0)
            {
                k=k*10+(a%10);
                a/=10;
            }
            a=0;
            for(i=2;i<=sqrt(k);i++)
            {
                if(k%i==0)
                {
                    a=1;break;

                }
            }

        }
        if(m==0&&a==0&&k!=n)
            printf("%lld is emirp.\n",n);
        else if(m==0&&n!=0)
            printf("%lld is prime.\n",n);
        else
            printf("%lld is not prime.\n",n);
    }
    return 0;
}
