//BISMILLAHHIR RAHMANIR RAHIM
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
#define N 1000000
#define M 1000000000000
using namespace std;

long long int ar[N]={0},pr[N],ap[N],a;

long long int lower(long long int q,long long int l,long long int h)
{
      long long  int m=(l+h)/2;
        while(l<=h)
          {
            if(ap[m]>=q)
            {
                if(m!=0&&ap[m-1]>=q)
                    h=m-1;
                else
                    break;
            }
            else
                l=m+1;
            m=(l+h)/2;
          }
          if(l>h)
              return -1;
          else
            return m;
}


long long int upper(long long int q,long long int l,long long int h)
{
      long long  int m=(l+h)/2;
        while(l<=h)
          {
            if(ap[m]<=q)
            {
                if(m!=a-1&&ap[m+1]<=q)
                    l=m+1;
                else
                    break;
            }
            else
                h=m-1;
            m=(l+h)/2;
          }
          if(l>h)
              return -1;
          else
            return m;
}

int main()
{
   long long int i,j,k,t,r,n,m,b,c,d,l;
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
    a=0;
    for(i=2;i<=N;i+=2)
       {
            if(ar[i]==0)
           {
            pr[k]=i;k++;
            for(j=i*i;j<=M;j*=i)
            {
                ap[a]=j;a++;
            }
           }
           if(i==2)
            i=1;
       }
    sort(ap,ap+a);

    scanf("%lld",&t);
    for(r=1;r<=t;r++)
    {
        scanf("%lld %lld",&n,&m);

        b=lower(n,0,a-1);
        c=upper(m,0,a-1);
        if(b<0||c<0||(c-b)<0)
            printf("0\n");
        else
            printf("%d\n",abs(c-b)+1);

    }
    return 0;
}

