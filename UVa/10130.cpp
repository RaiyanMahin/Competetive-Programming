//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<string.h>

int dp[10005];

int main()
{
    int i,j,k,t,r,l,m,n,w[1009],tp,tw,p[1009],g,mb[109];
    scanf("%d",&t);
    for(r=1;r<=t;r++)
    {
        scanf("%d",&n);tp=0;tw=0;
        for(i=0;i<n;i++)
        {
            scanf("%d %d",&p[i],&w[i]);
            if(w[i]>tw)
                tw=w[i];
        }
        scanf("%d",&g);
        for(i=0;i<g;i++)
        {
            scanf("%d",&mb[i]);
        }
        for(i=0;i<g;i++)
        {
            memset(dp,-1,sizeof(dp));
            dp[0]=0;l=0;
            for(j=0;j<n;j++)
            {
                for(k=32;k>=0;k--)
                    if(dp[k]!=-1&&k+w[j]<=mb[i])
                {
                    dp[k+w[j]]=(dp[k+w[j]]>(dp[k]+p[j]))?dp[k+w[j]]:(dp[k]+p[j]);
                    if(dp[k+w[j]]>l)
                        l=dp[k+w[j]];
                }
            }
            tp+=l;
        }
        printf("%d\n",tp);
    }
    return 0;
}
