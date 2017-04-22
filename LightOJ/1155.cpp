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

typedef int ll;
using namespace std;
struct T{
int a;
};
ll vis[205],par[205],cst[205][205],ar[205];


ll bfs(ll s,ll d,ll n)
{
    queue<ll>Q;
    ll i,j,u,v,mm;
    Q.push(s);
    memset(vis,0,sizeof(vis));
    memset(par,-1,sizeof(par));
    vis[s]=1;par[s]=-1;
    while(!Q.empty())
    {
        u=Q.front();
        Q.pop();
        for(i=0;i<=n;i++)
        {
            v=i;
            if(vis[v]==0&&cst[u][v]>0)
            {
                 vis[v]=1;
                 par[v]=u;
                 Q.push(v);
            }
            v=i+100;
            if(vis[v]==0&&cst[u][v]>0)
            {
                 vis[v]=1;
                 par[v]=u;
                 Q.push(v);
            }
             v=d;
            if(vis[v]==0&&cst[u][v]>0)
            {
                 vis[v]=1;
                 par[v]=u;
                 Q.push(v);
            }
        }
    }
    if(vis[d]==0)return 0;

    v=d;mm=1000000000;
    while(par[v]>-1)
    {
        mm=min(mm,cst[par[v]][v]);
        v=par[v];
    }
    v=d;
    while(par[v]>-1)
    {
       cst[par[v]][v]-=mm;
       cst[v][par[v]]+=mm;
        v=par[v];
    }
    return mm;
}

ll max_flow(ll s,ll d,ll n)
{
   ll mx=0,m;
    while(1)
    {
        m=bfs(s,d,n);
        if(m==0)break;
        mx=mx+m;
    }
    return mx;
}
int main()
{
   int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;

  sn("%d",&t);
    while(t--)
    {
        sn("%d",&n);
        memset(cst,0,sizeof(cst));
         for(i=0;i<n;i++)
        {
            sn("%d",&ar[i+1]);
            cst[i+1][i+1+100]=ar[i+1];
        }
        sn("%d",&m);

        for(i=0;i<m;i++)
        {
            sn("%d %d %d",&u,&v,&c);
            cst[u+100][v]+=c;
        }
        sn("%d %d",&a,&b);
        for(i=0;i<a;i++)
        {
            sn("%d",&u);
            cst[0][u]=1000000000;
        }
         for(i=0;i<b;i++)
            {
                sn("%d",&u);
                cst[u+100][n+2+100]=1000000000;
            }
        pf("Case %d: %d\n",cs++,max_flow(0,n+2+100,n+2));
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/

