//BISMILLAHHIR RAHMANIR RAHIM
#include<stdio.h>
#include<math.h>
#define N 10000

int ar[N]={0};

int main()
{
    int i,j,k,m,n,l,a,t,r,c,b,d,h,pr[N];

    for(i=3;i<=sqrt(N);i+=2)
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
          pr[k++]=i;
      }
    scanf("%d",&t);
    for(r=1;r<=t;r++)
    {
        scanf("%d",&n);
        for(a=0;a<k;a++)
            if(pr[a]>n)
            break;
        l=0;h=a-1;
        m=(l+h)/2;c=-1;
        d=-1;
       for(l=0;l<a;l++)
        {
            b=0;
            for(i=1;i<n;i++)
            {
                if((pr[l]*i)>n)
                    break;
                if((pr[l]*i)<=n&&(pr[l]*(i+1))>n)
                {
                    if((n-(i*pr[l]))>d)
                       {
                           b=i;d=(n-pr[l]*i);m=l;
                       }
                }

            }

        }

        printf("%d\n",pr[m]);

    }

  return 0;
}

