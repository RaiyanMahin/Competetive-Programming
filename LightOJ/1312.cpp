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

const double PI=2.0*acos(0);

typedef long long int ll;
using namespace std;
struct T{
int a;
};
int inv[20000];
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
int dpp[10005][3],dp[10005][3];
vector<int>Ed[10005],cst[10005],cstt[10005];
int dfs(int u,int fl)
{
    int &ret=dpp[u][fl];
    if(ret!=-1)
        return ret;
    ret=0;
    if(fl==1)
    {
        for(int i=0;i<Ed[u].size();i++)
         ret=ret+dfs(Ed[u][i],0);
    }
    else
    {
        int s=0;
        for(int i=0;i<Ed[u].size();i++)
        {
            cst[u][i]=1+dfs(Ed[u][i],1);
            cstt[u][i]=dfs(Ed[u][i],0);
            s=s+cstt[u][i];
        }
        ret=s;
        for(int i=0;i<Ed[u].size();i++)
        {
            ret=max(ret,s-cstt[u][i]+cst[u][i]);
        }
    }
    return ret;
}
int rec(int u,int fl)
{
    int &ret=dp[u][fl];
    if(ret!=-1)
        return ret;
    ret=0;
    if(fl==1)
    {
        ret=1;
        for(int i=0;i<Ed[u].size();i++)
         ret=(ret*rec(Ed[u][i],0))%10007;
    }
    else
    {
        int s=0,ans=1;
        for(int i=0;i<Ed[u].size();i++)
        {
            cst[u][i]=rec(Ed[u][i],1);
            ans=(ans*rec(Ed[u][i],0))%10007;
            s=s+dpp[Ed[u][i]][0];
        }
        if(dpp[u][fl]==s)
        {
            ret=ans;
        }
        for(int i=0;i<Ed[u].size();i++)
        {
            if(dpp[u][fl]==s-dpp[Ed[u][i]][0]+1+dpp[Ed[u][i]][1])
            {
                ret=(ret+ans*(cst[u][i]*inv[dp[Ed[u][i]][0]]%10007))%10007;
            }
        }
    }
    ret=ret%10007;
    return ret;
}
int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;
    for(i=0;i<10007;i++)
        inv[i]=bigmod(i,10005,10007);
    //freopen(".txt","r",stdin);
    sn("%d",&t);
    while(t--)
    {
        sn("%d",&n);
        for(i=0;i<n;i++)
        {
            sn("%d %d",&u,&c);
            for(j=0;j<c;j++)
            {
                sn("%d",&v);
                Ed[u].pb(v);
                cst[u].pb(0);
                cstt[u].pb(0);
            }
        }
        memset(dp,-1,sizeof(dp));
        memset(dpp,-1,sizeof(dpp));
        m=dfs(1,0);
        pf("Case %d: %d %d\n",cs++,m,rec(1,0));
        for(i=0;i<=n;i++)
        {
            Ed[i].clear();
            cst[i].clear();
            cstt[i].clear();
        }
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/

