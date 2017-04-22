#include<stdio.h>
int main()
{
    long long int i,j,k,l,m,n,w,ar[10000],c;
    while(scanf("%lld",&n)==1)
    {
        if(n==0)
            break;
        for(i=0;i<n;i++)
        {
            scanf("%lld",&ar[i]);
        }

        m=n;m=0;
        for(i=0;i<n-1;i++)
        {
            for(j=i+1;j<n;j++)
           {
            if(ar[j]<ar[i])
            {
                k=ar[j];
                ar[j]=ar[i];
                ar[i]=k;
            }
          }
          for(j=i+2;j<n;j++)
           {
            if(ar[j]<ar[i+1])
            {
                k=ar[j];
                ar[j]=ar[i+1];
                ar[i+1]=k;
            }
          }

            ar[i+1]=ar[i]+ar[i+1];
            k=0;
            m=m+ar[i+1];
        }
                printf("%lld\n",m);


    }
    return 0;
}
