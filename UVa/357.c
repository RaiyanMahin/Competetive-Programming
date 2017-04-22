#include<stdio.h>
#include<string.h>
long long dp[30005];
int main()
{
    long long n,i,j,k,l;
    long long ar[5]={1,5,10,25,50};
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    for(i=0;i<5;i++)
        {
            for(j=ar[i];j<=30003;j++)
            {
                if(dp[j-ar[i]]!=0)
                    dp[j]+=dp[j-ar[i]];
            }
        }

    while(scanf("%lld",&n)!=EOF)
    {
          if(dp[n]>1)
            printf("There are %lld ways to produce %lld cents change.\n",dp[n],n);
        else
            printf("There is only 1 way to produce %lld cents change.\n",n);
    }
        return 0;
}
