//BISMILLAHHIR RAHMANIR RAHIM
#include<stdio.h>
#include<math.h>
#define N 32000
int ar[N+5]={0},pr[N],dpr[1000][20];
int main()
{
    int i,j,k,n,t,r,a,m,c,b,d,dff;
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
        pr[k]=i;k++;
    }
    int g,h,l;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        if(n==0&&m==0)
            break;
            c=-1;d=-1;l=0;
         if(n>m)
         {
             g=n;n=m;m=g;
         }
         g=0;
        for(i=0;i<k;i++)
        {
            if(c<0&&pr[i]>=n)
            {
                c=i;
            }
            if(pr[i]<=m)
            {
                d=i;
            }
            else
                break;

        }

         for(i=c;;)
         {
             if((pr[i]-pr[i-1])==pr[i+1]-pr[i])
                c++;
             else
                break;
             i=c;
         }
         for(i=d;;)
         {
             if((pr[i]-pr[i-1])==pr[i+1]-pr[i])
                d--;
             else
                break;
             i=d;
         }

        dff=0;b=0;h=1;g=0;
        for(i=c+1;i<=d;i++)
      {
          j=pr[i]-pr[i-1];
          if(j==dff)
          {
                h=0;
             if(l==1)
                printf(" %d",pr[i]);
             else
                printf("%d %d %d",pr[b-1],pr[b],pr[i]);
                l=1;
          }
          else if(l==1)
          {
              printf("\n");l=0;h=1;
          }
          dff=j;
          b=i;
      }
      if(h==0)
        printf("\n");

    }
    return 0;
}

