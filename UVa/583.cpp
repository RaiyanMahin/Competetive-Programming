#include<stdio.h>
#include<math.h>
#define N 100000
int ar[N]={0};
int main()
{
    int i,j,k,n,l,m,pr[100000];
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
    {
        if(ar[i]==0)
        {
            pr[k]=i;
            k++;
        }
    }

    while(scanf("%d",&n)==1)
   {
       if(n==0)
        break;
        l=0;
        if(n==1)
                printf("%d = %d",n,n);
       else if(n<0)
        {
            printf("%d = -1",n);
            n=n*-1;l=1;
        }
       else
        printf("%d =",n);
        m=n;i=0;
        while(m!=1)
        {
            if(m%pr[i]==0)
            {
                if(l==0)
               {
                    printf(" %d",pr[i]);
                    l=1;
               }
               else
                printf(" x %d",pr[i]);
               m=m/pr[i];
            }
            else
                i++;
            if(pr[i]>sqrt(n)+2&&m!=1)
            {
                 if(l==0)
                    printf(" %d",m);
                 else
                  printf(" x %d",m);
                  m=m/m;
            }

        }

        printf("\n");
   }
    return 0;
}


