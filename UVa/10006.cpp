
#include<stdio.h>
#include<string.h>
#include<math.h>
#define N 66000
long long int ar[N]={0},cal[N]={0};
long long int p;
 long long int Bigmod(long long int a,long long int b)
 {
     long long int half,k,m;
     if(b==0)
        return 1;
     if(b%2==0)
     {
         half=Bigmod(a,b/2);
           return ((half%p)*(half%p))%p;

     }
     else
        {
            return ((a%p)*Bigmod(a,b-1)%p)%p;
        }
 }
 void calmel()
 {
     int m,i,l;
     for(p=20;p<=65000;p++)
     {
          if(ar[p]==1&&p%2==1)
        {
            m=0;
            for(i=2;i<p;i++)
            {
                l=Bigmod(i,p);
                if(i!=l)
                {
                   m=1;break;
                }
            }
            if(m==0)
              cal[p]=1;
        }
     }
 }
int main()
{
    long long int i,j,k,l,m,n;
    memset(cal,0,sizeof(cal));
    memset(ar,0,sizeof(ar));
     for(i=3;i<=sqrt(N)+1;i+=2)
    {
        if(ar[i]==0)
        {
            for(j=i*i;j<=N;j+=i*2)
                if(j%i==0)
                ar[j]=1;
        }

    }
    calmel();
    while(scanf("%lld",&n)!=EOF)
    {
        if(n==0)
            break;

        if(cal[n]==1)
            printf("The number %lld is a Carmichael number.\n",n);
        else
            printf("%lld is normal.\n",n);
    }
  return 0;
}

