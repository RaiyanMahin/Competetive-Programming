//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<math.h>
#define N 10000000
bool ar[N+5]={0};
long long pr[1000000+5];
int main()
{
     long long int i,j,k,l,m,n,a,b,t,r;
     ar[1]=1;ar[0]=1;
     for(i=3;i<=sqrt(N)+1;i+=2)
     {
         if(ar[i]==0)
         {
             for(j=i*i;j<=N;j+=i*2)
                if(j%i==0)
                ar[j]=1;
         }
     }
    k=2;pr[0]=2;pr[1]=3;
    for(i=5;i<=N;i+=6)
    {
        if(ar[i]==0)
            pr[k++]=i;
        if(ar[i+2]==0)
            pr[k++]=i+2;
    }
  while(scanf("%lld",&n)==1)
  {
      if(n==0)
        break;
        if(n<0)
            n*=-1;
      t=0;
      if(n<=10000000&&ar[n]==0&&(n==2||n%2==1))
        t=-1;
     if(t!=-1)
      {
          m=n;j=0;a=0;
          for(i=0;i<k;i++)
          {
              if(m%pr[i]==0)
              {
                   j++;a=pr[i];
              }
              while(m%pr[i]==0)
              {
                  m/=pr[i];

              }
               if(m<=10000000&&ar[m]==0&&(m==2||m%2==1))
                {
                    a=(a>m)?a:m; j++;
                    break;
                }
                if(pr[i]>=sqrt(n)+1)
                break;
          }
          if(m==n)
            t=-1;
          else if(m!=1&&a!=m)
          {
              j++;a=(a>m)?a:m;
          }
          if(j<2)
            t=-1;

      }
      if(t==-1)
        printf("-1\n");
      else
        printf("%lld\n",a);

  }
    return 0;
}
