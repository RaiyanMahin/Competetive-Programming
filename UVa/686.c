#include<stdio.h>
#include<math.h>
#define n 40000
int ar[n]={0};
int main()
{
    int i,j,k,N,m,t;
    for(i=3;i<=sqrt(n)+1;i+=2)
    {
        if(ar[i]==0)
        {
            for(j=i*i;j<=n;j+=i*2)
                if(j%i==0)
                ar[j]=1;
        }

    }
    while(scanf("%d",&N)!=EOF)
    {
        if(N==0)
            break;
            m=2;k=2;t=0;
        while(N-k>=k)
        {
          if(ar[k]==0&&ar[N-k]==0&&((N-k)%2==1||N-k==2))
          {
              t++;
          }
          if(k==2)
            k++;
          else
            k+=2;
        }

            printf("%d\n",t);
    }

    return 0;
}
