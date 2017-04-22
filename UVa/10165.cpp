#include<stdio.h>
int main()
{
   long long int i,j,k,l,m,n;
    while(scanf("%lld",&n)!=EOF)
    {
        if(n==0)
            break;
        m=0;
         for(i=0;i<n;i++)
         {
             scanf("%lld",&l);
             m^=l;
         }
         if(m!=0)
            printf("Yes\n");
         else
            printf("No\n");
    }
         return 0;
}
