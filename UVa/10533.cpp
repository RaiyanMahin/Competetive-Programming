#include<stdio.h>
#include<math.h>
#define N 1000005
bool ar[N];
int main()
{
    int i,j,k,t,r,m,n,a,b;ar[0]=1;ar[1]=1;
    for(i=3;i<=sqrt(N)+1;i+=2)
    {
        if(ar[i]==0)
        {
            for(j=i*i;j<=N;j+=i*2)
                if(j%i==0)
                ar[j]=1;
        }

    }
    scanf("%d",&t);
    for(r=1;r<=t;r++)
    {
        scanf("%d %d",&a,&b);k=0;
        for(i=a;i<=b;i++)
        {
            if(ar[i]==0)
            {
                m=i;n=0;
                while(m!=0)
                {
                    n=n+m%10;
                    m/=10;
                }
                if(ar[n]==0)
                    k++;
             }
        }
         printf("%d\n",k);
    }

    return 0;
}

