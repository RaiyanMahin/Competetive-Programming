//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<queue>
#include<stack>
#include<map>
#include<string>
#include<vector>
#include<algorithm>
#define N 1000000
#define sn scanf
#define pf printf

typedef long long int ll;
using namespace std;

struct T{
long long a,b;

}ar[100];
long long dp[500][500],s;

long long Min(long long a,long long b)
{
    return a>b?b:a;
}



int main()
{
    long long  i,j,k,l,t,r,m,n,a,b,c,d,e,f,g,h,u,v;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld %lld",&n,&m);
        for(i=0;i<n;i++)
        {
            scanf("%lld %lld",&ar[i].a,&ar[i].b);
        }
        for(i=0;i<=m;i++)
            for(j=0;j<=m;j++)
            dp[i][j]=1000000;
        s=1000000;
        ll ans=s;
      dp[0][0]=0;
        for(i=0;i<n;i++)
        {
            for(j=ar[i].a;j<=m;j++)
            {
                for(k=ar[i].b;k<=m;k++)
                {
                    if(dp[j-ar[i].a][k-ar[i].b]!=s&&j*j+k*k<=m*m)
                    {
                        dp[j][k]=Min(dp[j][k],dp[j-ar[i].a][k-ar[i].b]+1);
                        if(j*j+k*k==m*m)
                        {
                            if(ans>dp[j][k])
                                ans=dp[j][k];
                        }

                    }
                }
            }
        }
        if(ans==1000000)
            printf("not possible\n");
        else
        printf("%lld\n",ans);
    }
    return 0;
}

