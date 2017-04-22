//BISMILLAHIR  RAHMINIR RAHIM
#include<stdio.h>
#include<math.h>
#include<string.h>
#define N 1000000
 int ar[N]={0},pr[100000];
int main()
{
int i,j,k,n,a[10000],p[1000l],m,l,an,ans,c,prime;
    for(i=3;i<=sqrt(N)+1;i+=2)
    {
        if(ar[i]==0)
        {
            for(j=i*i;j<=N;j+=i*2)
                if(j%i==0)
                ar[j]=1;
        }

    }k=1;pr[0]=2;
   for(i=3;i<=N;i+=2)
        if(ar[i]==0)
    {
       pr[k]=i;k++;

    }
    while(scanf("%d",&n)!=EOF)
    {
        m=n;j=-1;
        memset(a,0,sizeof(a));
        memset(p,0,sizeof(p));
        for(i=0;i<k;i++)
        {
            if(m%pr[i]==0)
                j++;
            while(m%pr[i]==0)
            {
                a[j]=pr[i];
                p[j]++;
                m/=pr[i];
            }
            if(m==1)
                break;
            if(pr[i]>n/2)
                break;
        }
        if(j==-1&&m==n)
         prime=0;
        else
            prime=1;

        if(j==-1||m!=1)
            {
                a[++j]=m;
                if(m!=n)
                p[j]=1;
            }
        m=1;l=1;c=1;
        for(i=0;i<=j;i++)
        {
            m*=a[i];
            l*=(a[i]-1);
            c*=(p[i]+1);
        }
         an=(n/m)*l;
         ans=n-(c+an-prime);

        printf("%d\n",ans);
    }
    return 0;
}

