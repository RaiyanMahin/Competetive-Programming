//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<queue>
#include<set>
#include <iostream>
#include<stack>
#include<map>
#include<string>
#include<vector>
#include<algorithm>
#define N 1000000
#define sn scanf
#define pf printf
#define pb push_back
#define mp make_pair

typedef long long int ll;
using namespace std;
struct T{
int a;
};
ll bigmod(ll a,ll b,ll mod)
{
    if(b==0)return 1;
    if(b%2==0)
    {
        ll hh=bigmod(a,b/2,mod);
        return (hh*hh)%mod;
    }
    else
    {
       return (a*bigmod(a,b-1,mod))%mod;
    }
}
vector<int>Ed[23];
int dp[(1<<15)+3],mod=10000,ar[16],tw[2000],dpp[(1<<15)+5];
char st[20][20];

int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;

    //freopen(".txt","r",stdin);
    sn("%d",&t);
    tw[0]=1;
    for(i=1;i<=1700;i++)
    {
        tw[i]=(tw[i-1]*2)%mod;
    }
   // for(i=0;i<17;i++)tw[i]--;
    while(t--)
    {
        sn("%d",&n);
        memset(dp,0,sizeof(dp));
        memset(dpp,0,sizeof(dpp));
        for(i=0;i<n;i++)
        {
            ar[i]=0;
            sn("%s",&st[i]);
            for(j=0;j<n;j++)
            {
                if(st[i][j]=='Y')
                    dp[(1<<i)|(1<<j)]=1;
            }
        }

        m=1<<n;
        for(i=1;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                for(k=j+1;k<n;k++)
                {
                    if((i&(1<<j))&&(i&(1<<k))&&st[j][k]=='Y')
                    {
                        dpp[i]++;
                    }
                }
            }
        }
        dpp[0]=0;
        for(i=1;i<m;i++)
        {
            dpp[i]=tw[dpp[i]];
        }
        dp[0]=1;
        for(i=0;i<n;i++)
            dp[1<<i]=1;
        for(i=1;i<m;i++)
        {
            Ed[__builtin_popcount(i)].pb(i);
        }
        dpp[0]=0;
     for(k=3;k<=n;k++)
        for(a=0,b=Ed[k].size();a<b;a++)
        {
            i=Ed[k][a];
            for(j=n-1;j>=0;j--)
            {
                if(i&(1<<j))
                {
                    u=j;break;
                }
            }
            v=i^(1<<u);
            u=1<<u;
            for(j=v;j>0;j=v&(j-1))
            {
               dp[i]+=(dp[u|j]*dpp[v^j])%mod;
            }
            dp[i]+=(dp[u|j]*dpp[v^j])%mod;
            dp[i]=dp[i]%mod;
            dp[i]=(mod-dp[i]+dpp[i])%mod;
            dp[i]=dp[i]%mod;
        }
        pf("Case %d: %d\n",cs++,dp[(1<<n)-1]);
        for(i=0;i<19;i++)
            Ed[i].clear();
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/

