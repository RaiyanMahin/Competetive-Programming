#include<stdio.h>
int main()
{
   long long int i,j,k,l,m,n,a,b,c,ar[11];
    while(scanf("%lld %lld",&n,&m)!=EOF)
    {
        if(n<0&&m<0)
            break;
        for(i=0,k=0;i<=9;i++)
        {
             k=k+i;
             ar[i]=k;
        }
        j=0;
        if(n!=0)
        n=n-1;
        while(n!=0)
        {
            a=(n/10)*45;
            j=j+a+ar[n%10];
            n/=10;
        }
        k=0;

        while(m!=0)
        {
             a=(m/10)*45;
            k=k+a+ar[m%10];
            m/=10;
        }
        printf("%lld\n",k-j);
    }
    return 0;
}
