//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
    int i,j,k,l,n,r=1,ar[16],dp[30];
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)
            break;
        for(i=0;i<n;i++)
            scanf("%d",&ar[i]);
        sort(ar,ar+n);
        l=0;memset(dp,0,sizeof(dp));
        for(i=0;i<n;i++)
        {
            if(dp[i]==0)
            {
                for(k=i;k<n;k++)
                {
                    if(k!=i&&dp[k]==0)
                        break;
                }
                if(dp[k]==0&&k!=i&&k<n)
                 for(j=0;j<n;j++)
                  {
                        if(ar[i]+ar[k]+ar[j]>=20&&dp[j]==0&&j!=i&&j!=k)
                        {
                            l++;
                            dp[i]=dp[k]=dp[j]=1;
                            break;
                        }
                  }
            }

        }

        printf("Case %d: %d\n",r,l);r++;
    }

    return 0;
}

