#include<stdio.h>
int main()
{
   long long int t,e,b,i,n,h;

   while(scanf("%lld%lld",&n,&b)!=EOF)
    {
        e=n;
        for(h=0;e>=b;h++)
        {

            e=e+1-b;

        }
        printf("%lld\n",h+n);
    }
    return 0;
}

