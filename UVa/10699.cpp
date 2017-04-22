//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<math.h>
#define N 1000006
int ar[N]={0};
int pr[100000];
int main()
{
    int i,j,k,n,cnt;
    ar[1]=1;ar[0]=1;
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
        pr[k]=i;
        k++;

    }
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)
            break;
            cnt =0;
        for(i=0;i<k;i++)
        {
            if(n%pr[i]==0)
            {
                cnt++;
            }
            if(pr[i]>n/2)
                break;

        }
        if(ar[n]==0&&n%2==1)
            cnt++;
        printf("%d : %d\n",n,cnt);

    }

    return 0;
}

