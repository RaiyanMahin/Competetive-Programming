//BISMILLAHIR  RAHMINIR RAHIM
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int dp[500005],A[105];

int main()
{
    int n,i,w,j,t,r,m,a,s,d;

    scanf("%d",&t);
    for(r=1;r<=t;r++)
    {
        memset(dp,0,sizeof(dp));s=0;
        scanf("%d",&n);

        for(i=0;i<n;i++)
            {
                scanf("%d",&A[i]);
                s=s+A[i];
            }
        m=s/2;
        dp[0]=1;
        for(i=0;i<n;i++)
        {
            for(j=m;j>=0;j--)
            {
                if(dp[j]!=0&&j+A[i]<=m)
                    dp[j+A[i]]++;
            }
        }
        for(i=m;i>=0;i--)
            if(dp[i]>0)
            break;
        d=abs(s-(2*i));
        printf("%d\n",d);
    }
    return 0;
}

