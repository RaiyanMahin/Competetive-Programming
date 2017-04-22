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
int l,h;
}ar[20000];
ll mod=21092013,dp[10002][51],dpp[10002][51],vis[10002],dd[10005][51];
vector<int>Ed[10005],Edd[10005];
vector<int>gd[55],gv[55];
ll gc[55][55]={0},cnt[55];
ll gcd(ll a,ll b)
{
     if(a%b==0)
        {
            return b;
        }
    else
      return gcd(b,a%b);
}
void dfs(int u)
{
    vis[u]=1;
    int i,j=Ed[u].size(),v,k,g,nn=50;
    for(i=0;i<j;i++)
    {
        v=Ed[u][i];
        if(vis[v]==0)
        {
            Edd[u].pb(v);
            dfs(v);
        }
    }
    memset(cnt,0,sizeof(cnt));
    for(i=0;i<Edd[u].size();i++)
    {
        v=Edd[u][i];
        for(j=1;j<=nn;j++)
        {
            for(k=1;k<=nn;k++)
            {
                g=gc[j][k];
                dpp[u][g]=(dpp[u][g]+(dp[v][j]*cnt[k]%mod));
                while(dpp[u][g]>=mod)
                    dpp[u][g]-=mod;
            }

        }
        for(j=1;j<=nn;j++){
            cnt[j]=(cnt[j]+dp[v][j]);
            while(cnt[j]>=mod)
                    cnt[j]-=mod;
        }
    }
    for(i=ar[u].l;i<=ar[u].h;i++)
    {
        for(j=1;j<=nn;j++)
        {
           g=gc[i][j];
            dd[u][g]=(dd[u][g]+dpp[u][j]);
            while(dd[u][g]>=mod)
                    dd[u][g]-=mod;
        }
    }
    for(i=ar[u].l;i<=ar[u].h;i++)
    {
        dp[u][i]++;
        for(j=0;j<Edd[u].size();j++)
        {
            v=Edd[u][j];
            for(k=1;k<=nn;k++)
            {
                g=gc[i][k];
                dp[u][g]=(dp[u][g]+dp[v][k]);
                while(dp[u][g]>=mod)
                    dp[u][g]-=mod;
            }
        }
    }
    for(i=1;i<=nn;i++)
    {
        dd[u][i]=(dd[u][i]+dp[u][i]);
        while(dd[u][i]>=mod)
                dd[u][i]-=mod;
    }
}
int main()
{
    ll i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;

    //freopen(".txt","r",stdin);
    sn("%lld",&t);
    memset(gc,0,sizeof(gc));
    for(i=1;i<51;i++)
    {
        for(j=1;j<51;j++)
        {
            gc[i][gcd(i,j)]++;
        }
        for(j=1;j<=50;j++)
        {
            if(gc[i][j]>0)
            {
                gd[i].pb(j);
                gv[i].pb(gc[i][j]);
            }
        }
    }

    while(t--)
    {
        sn("%lld",&n);
        for(i=0;i<n-1;i++)
        {
            sn("%lld %lld",&u,&v);
            Ed[u].pb(v);
            Ed[v].pb(u);
        }
        for(i=1;i<=n;i++)
           sn("%d",&ar[i].l);
        for(i=1;i<=n;i++)
           sn("%d",&ar[i].h);

        memset(vis,0,sizeof(vis));
        memset(dp,0,sizeof(dp));
        memset(dpp,0,sizeof(dpp));
        memset(dd,0,sizeof(dd));
         dfs(1);
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=50;j++)
            {
                dd[0][j]=(dd[0][j]+dd[i][j])%mod;
            }
        }
        pf("Case %lld:\n",cs++);
        for(i=1;i<=50;i++)
        {
            pf("%lld: %lld\n",i,dd[0][i]);
        }
        for(i=0;i<=n;i++)
        {
            Ed[i].clear();
            Edd[i].clear();
        }
    }
    return 0;

}

/*
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
int l,h;
}ar[20000];
ll mod=21092013,dp[10002][51],dpp[10002][51],vis[10002],dd[10005][51],cnt[10005][51],cn[51];
vector<int>Ed[10005],Edd[10005];

ll gc[55][55]={0};
ll gcd(ll a,ll b)
{
     if(a%b==0)
        {
            return b;
        }
    else
      return gcd(b,a%b);
}
void dfs(int u,int p)
{
    vis[u]=1;
    int i,j=Ed[u].size(),v,k,g,nn=50;
    for(i=0;i<j;i++)
    {
        v=Ed[u][i];
        if(vis[v]==0)
        {
            Edd[u].pb(v);
            dfs(v,u);
        }
    }
    memset(cn,0,sizeof(cn));
    for(i=0;i<Edd[u].size();i++)
    {
        v=Edd[u][i];
        for(j=1;j<=nn;j++)
        {
            cn[j]=(cn[j]+dp[v][j]);
            if(cn[j]>=mod)
                cn[j]-=mod;
        }
    }
    for(i=ar[u].l;i<=ar[u].h;i++)
    {
        dp[u][i]++;
        for(j=1;j<=nn;j++)
        {
            g=gc[i][j];
            dp[u][g]=(dp[u][g]+cn[j]);
            if(dp[u][g]>=mod)
                dp[u][g]-=mod;
        }
    }
    for(i=1;i<=nn;i++)
    {
        dd[u][i]=(dd[u][i]+dp[u][i]);
        while(dd[u][i]>=mod)
                dd[u][i]-=mod;
    }
      if(u==1)
        return;
       for(i=1;i<=nn;i++)
       {
           for(j=1;j<=nn;j++)
           {
               g=gc[i][j];
               dd[p][g]=(dd[p][g]+(dpp[p][i]*dp[u][j]%mod));
               if(dd[p][g]>=mod)
                dd[p][g]-=mod;
           }
       }
        for(i=ar[p].l;i<=ar[p].h;i++)
        {
            for(j=1;j<=nn;j++)
            {
                g=gc[i][j];
                dpp[p][g]=(dpp[p][g]+dp[u][j]);
                if(dpp[p][g]>=mod)
                dpp[p][g]-=mod;
            }
        }

}
int main()
{
    ll i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;

    //freopen(".txt","r",stdin);
    sn("%lld",&t);
    for(i=1;i<51;i++)
    {
        for(j=1;j<51;j++)
        {
            gc[i][j]=gcd(i,j);
        }
    }
    while(t--)
    {
        sn("%lld",&n);
        for(i=0;i<n-1;i++)
        {
            sn("%lld %lld",&u,&v);
            Ed[u].pb(v);
            Ed[v].pb(u);
        }
        for(i=1;i<=n;i++)
           sn("%d",&ar[i].l);
        for(i=1;i<=n;i++)
           sn("%d",&ar[i].h);

        memset(vis,0,sizeof(vis));
        memset(dp,0,sizeof(dp));
        memset(dpp,0,sizeof(dpp));
        memset(dd,0,sizeof(dd));
        //memset(cnt,0,sizeof(cnt));
         dfs(1,0);
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=50;j++)
            {
                dd[0][j]=(dd[0][j]+dd[i][j])%mod;
            }
        }
        pf("Case %lld:\n",cs++);
        for(i=1;i<=50;i++)
        {
            pf("%lld: %lld\n",i,dd[0][i]);
        }
        for(i=0;i<=n;i++)
        {
            Ed[i].clear();
            Edd[i].clear();
        }
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/

