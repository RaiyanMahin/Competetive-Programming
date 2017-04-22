//BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
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
#define pb push_back

typedef long long int ll;
using namespace std;
struct T{
int a;
};
ll dp[2][15001],mod=100000007;
int main()
{
    ll i,j,k,l,t,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld %lld %lld",&n,&m,&s);
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for(i=1;i<=n;i++)
        {
            u=i%2;
            //memset(dp[u],0,sizeof(dp[u]));
            for(a=0;a<=s;a++)
                dp[u][a]=0;
            for(j=1;j<=s;j++)
            {
                dp[u][j]=(dp[u][j-1]+dp[1-u][j-1])%mod;
                if(j-m-1>=0)
                dp[u][j]=((dp[u][j]-dp[1-u][j-m-1])%mod+mod)%mod;
            }
        }
        pf("Case %lld: %lld\n",r++,dp[u][s]%mod);
    }
    return 0;
}

