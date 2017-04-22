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
vector<int>Ed[16];
int vis[16][33000],viss[33000],dp[33000];

void dfs(int u,int msk)
{
    vis[u][msk]=1;
    viss[msk]=1;
    int i,j=Ed[u].size(),v;
    for(i=0;i<j;i++)
    {
        v=Ed[u][i];
        if(!vis[v][msk|(1<<v)])
            dfs(v,msk|(1<<v));
    }
}
int rec(int msk)
{
    if(msk==0)
        return 0;
    int &ret=dp[msk];
    if(ret!=-1)
        return ret;
    ret=1000;
    for(int i=msk;i>0;i=msk&(i-1))
    {
        if(viss[i])
        {
            ret=min(ret,rec(msk^i)+1);
        }
    }
    return ret;
}
int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;
  #ifdef O_judge
    //freopen(".txt","r",stdin);
  #endif
    sn("%d",&t);
    while(t--)
    {
        sn("%d %d",&n,&m);
        for(i=0;i<m;i++)
        {
            sn("%d %d",&u,&v);
            u--;v--;
            Ed[u].pb(v);
        }
        memset(vis,0,sizeof(vis));
        memset(viss,0,sizeof(viss));
        for(i=0;i<n;i++)
        {
            dfs(i,(1<<i));
        }

        memset(dp,-1,sizeof(dp));
        pf("Case %d: %d\n",cs++,rec((1<<n)-1));
        for(i=0;i<=n;i++)
        {
            Ed[i].clear();
        }
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/
