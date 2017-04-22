//BISMILLAHIR RAHMANIR RAHIM

#include<stdio.h>
#include<math.h>
#include<string.h>
#define N 40000
long long int pr[40000];
long long int ar[N]={0};
long long int prime(long long int n)
{
   long long   int i,j,k;
   if(n%2==0)
    return (n!=2)?1:0;
    if(n<=40000)
        return ar[n];
    for(i=0;;i++)
    {
        if(pr[i]*pr[i]>n)
            return 0;
        if(n%pr[i]==0)
            return 1;
    }
}
int main()
{
   long long int i,j,k,n;

    for(i=3;i<=sqrt(N)+1;i+=2)
    {
        if(ar[i]==0)
        {
            for(j=i*i;j<=N;j+=i*2)
                if(j%i==0)
                ar[j]=1;
        }

    }
    k=1;pr[0]=2;
    for(i=3;i<=N;i+=2)
        if(ar[i]==0)
    {
      pr[k]=i; k++;
    }
   long long int g,h,a,c,b,d,m,l;
    while(scanf("%lld",&n)!=EOF)
    {
        m=n/2;c=0;d=0;g=0;h=0;
        if(m==(n-m))
            m--;
        if(m%2==0)
            m--;
         if(n>4)
         {
             if(n%2==1)
             {
                 c=prime(n-2);
                 if(c==0)
                 {
                     g=2,h=n-2;
                 }
             }
             else
             {
               while(m>2)
               {
                   if(prime(m)==0&&prime(n-m)==0)
                   {
                       g=m;h=n-m;break;
                   }
                   m-=2;
               }
             }
         }

        if(g==0||h==0)
            printf("%lld is not the sum of two primes!\n",n);
        else if(g!=0&&h!=0)
            printf("%lld is the sum of %lld and %lld.\n",n,g,h);
    }
    return 0;
}
