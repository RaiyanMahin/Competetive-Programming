#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    int i,j,k,l,n,t,r,p,pr[10000],dp[40000];
    scanf("%d",&t);
    for(r=1;r<=t;r++)
    {
        scanf("%d %d",&n,&p);
        for(i=0;i<p;i++)
            scanf("%d",&pr[i]);
        memset(dp,0,sizeof(dp));
        l=0;
       for(i=0;i<p;i++)
       {
           for(j=pr[i];j<=n;j+=pr[i])
           {
                if(j%7!=0&&j%7!=6&&dp[j]==0)
                {
                    l++;dp[j]=1;
                }
           }
       }

       printf("%d\n",l);
    }

    return 0;
}
