#include<stdio.h>
#include<math.h>
int main()
{
   long long  int i,j,k,l,t,n,r;
    scanf("%lld",&t);
    for(r=0;r<t;r++)
    {
        scanf("%lld",&n);
        j=1;
        k=4+(4*2*n);
        i=(sqrt(k)-1)/2;
        printf("%lld\n",i);
    }
    return 0;
}
