//BISMILLAHIR  RAHMINIR RAHIM
#include<stdio.h>
#include<math.h>
#include<string.h>
#define N 100000
 int ar[N]={0},pr[100000];
int main()
{
int i,j,k,n,a[10000],l,m;
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
        if(n==0)
            break;
        m=n;j=-1;
        memset(a,0,sizeof(a));
        for(i=0;i<k;i++)
        {
            if(m%pr[i]==0)
                j++;
            while(m%pr[i]==0)
            {
                a[j]=pr[i];
                m/=pr[i];
            }
            if(m==1)
                break;
            if(pr[i]>n/2)
                break;
        }
        if(j==-1||m!=1)
            a[++j]=m;
        m=1;l=1;
        for(i=0;i<=j;i++)
        {
            m*=a[i];
            l*=(a[i]-1);
        }
       //for uva 10179
       /*
        if(n==1)
            printf("1\n");
        else*/
        printf("%d\n",(n/m)*l);
    }
    return 0;
}
