//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<string.h>

int dp[10005];

int main()
{
    int i,j,k,t,r,l,m,n,w[1009],tp,tw,p[1009],g,mb[109];
    char c;
    scanf("%d",&t);
    for(r=1;r<=t;r++)
    {
        tw=0;
       for(i=0;;i++)
       {
           scanf("%d%c",&w[i],&c);
           tw+=w[i];
           if(c=='\n')
            break;
       }
       memset(dp,0,sizeof(dp));
       dp[0]=1;
       n=i+1;m=tw/2;
       for(i=0;i<n;i++)
            {
                for(j=m;j>=0;j--)
                {
                    if(dp[j]!=0&&j+w[i]<=m)
                        dp[j+w[i]]++;
                }
            }
        if(dp[m]>0&&tw%2==0)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}

