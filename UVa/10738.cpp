//BISMILLAHHIR RAHMANIR RAHIM
#include<stdio.h>
#include<math.h>
#define N 1000000
int ar[N+5]={0};
int sum[N+5],mu[N+5],pr[N],dv[N+5]={0};
int mun(int n)
{
    int i,j=0,k=0,l,m=n;
    if(ar[n]==0&&(n%2==1||n==2))
       return -1;
       if(dv[n]<0)
            return 0;
    if(dv[n]%2==0)
        return 1;
    else if(dv[n]%2==1)
         return -1;

}
int main()
{
    int i,j,k,n,a,b,c,d;ar[1]=1;
    for(i=2;i<=N+1;i+=2)
    {
        if(ar[i]==0)
        {
            for(j=i+i;j<=N;j+=i)
                if(j%i==0)
               {
                   if(j%(i*i)==0)
                     dv[j]=-1000000;
                    else
                    dv[j]++;
                    ar[j]=1;
               }
        }
        if(i==2)
            i=1;

    }
    sum[1]=1;mu[1]=1;
    for(i=2;i<=N;i++)
    {
        mu[i]=mun(i);
        sum[i]=sum[i-1]+mu[i];
    }
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)
            break;
        printf("%8d%8d%8d\n",n,mu[n],sum[n]);
    }
    return 0;
}

