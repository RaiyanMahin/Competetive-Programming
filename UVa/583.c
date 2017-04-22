#include<stdio.h>
#include<math.h>
#define n 1000000
int ar[n]={0};
int main()
{
    int i,j,k;
    for(i=3;i<=sqrt(n)+1;i+=2)
    {
        if(ar[i]==0)
        {
            for(j=i*i;j<=n;j+=i*2)
                if(j%i==0)
                ar[j]=1;
        }

    }k=0;
    for(i=3;i<=n;i+=2)
        if(ar[i]==0)
    {
        printf("%d\n",i);k++;

    }
    printf("%d\n",k);
    return 0;
}

