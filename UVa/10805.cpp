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
int dis[30][30],lon[30],par[30],vis[30][30];
vector<int>Ed[30],Edd[30];
void bfs(int s,int n)
{
    int u,v,i,j,a=0;
    queue<int>Q;
    dis[s][s]=0;
    lon[s]=s;Q.push(s);
    memset(par,-1,sizeof(par));
    while(!Q.empty())
    {
        u=Q.front();Q.pop();
        for(i=0;i<Ed[u].size();i++)
        {
            v=Ed[u][i];
            if(dis[s][v]>dis[s][u]+1)
            {
                dis[s][v]=dis[s][u]+1;
                par[v]=u;
                Q.push(v);
            }
        }
    }

}

int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;

    //freopen("input.txt","w",stdout);
    sn("%d",&t);
    while(t--)
    {
        sn("%d %d",&n,&m);
        memset(vis,0,sizeof(vis));
        for(i=0;i<m;i++)
        {
            sn("%d %d",&u,&v);
            Ed[u].pb(v);
            Ed[v].pb(u);
            vis[u][v]=1;
            vis[v][u]=1;
        }
        for(i=0;i<30;i++)
        {
            for(j=0;j<30;j++)
            {
                dis[i][j]=1000;
            }
        }
        for(i=0;i<n;i++)
        {
            bfs(i,n);
        }
        int ans=10000;
        h=(1<<n)-1;
        for(i=0;i<n;i++)
        {
            memset(lon,0,sizeof(lon));
            for(j=0;j<n;j++)
            {
                for(k=0;k<n;k++)
                {
                    if(dis[j][k]<=i)
                    lon[j]|=1<<k;
                }
                if(lon[j]==h)
                {
                    ans=min(ans,2*i);
                }
            }
            for(j=0;j<n;j++)
            {
                for(k=0;k<n;k++)
                {
                    a=lon[j]|lon[k];
                    if(vis[j][k]==1&&a==h)
                    {
                        ans=min(ans,2*i+1);
                    }
                }
            }
        }
        pf("Case #%d:\n%d\n",cs++,ans);
        if(t!=0)
            pf("\n");
        for(i=0;i<=n;i++)
            Ed[i].clear();
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/

