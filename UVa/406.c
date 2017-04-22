
#include<stdio.h>
#include<math.h>
#define N 1000
int ar[N]={0};
int main()
{
    int i,j,k,n,c,r,m,l,pr[10000];
    for(i=3;i<=sqrt(N)+1;i+=2)
    {
        if(ar[i]==0)
        {
            for(j=i*i;j<=N;j+=i*2)
                if(j%i==0)
                ar[j]=1;
        }

    }
    while(scanf("%d %d",&n,&c)!=EOF)
    {
        pr[0]=1;pr[1]=2;k=2;
        if(n==1)
            k=1;
        for(i=3;i<=n;i+=2)
        {
            if(ar[i]==0)
                pr[k++]=i;
        }
        printf("%d %d:",n,c);
        if(k%2==0)
            {
                r=k/2;l=c*2;
            }
        else
            {
                r=(k/2)+1;l=c*2-1;
            }
        i=r-c;l=l+i;
        if(i<0)
          i=0;
        for(;(i<l&&i<k);i++)
            printf(" %d",pr[i]);
        printf("\n");
    }
    return 0;
}
