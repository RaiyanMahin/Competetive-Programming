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
struct vec{
double x,y;
 vec(double xx=0,double yy=0)
 {
     x=xx;y=yy;
 }
};
vec make_vac(vec p,vec q)
{
    return vec(q.x-p.x,q.y-p.y);
}
double dotproduct(vec p,vec q)
{
    return p.x*q.x+p.y*q.y;
}
double crossproduct(vec p,vec q)
{
    return p.x*q.y-q.x*p.y;
}
double vec_value(vec p)
{
    return sqrt(p.x*p.x + p.y*p.y);
}
vec unit_vec(vec p)
{
    double va=vec_value(p);
    return vec(p.x/va,p.y/va);
}
double dis(double px,double py,double qx,double qy)
{
    px=fabs(px-qx);
    py=fabs(py-qy);
    return sqrt(px*px+py*py);
}
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
vector<int>Ed[105],Edd[105];
int vis[105],viss[105],dp[105][105],cost[105][105],K,nxt[104];
void dfs(int u,int p)
{
    viss[u]=1;
    int i,j=Ed[u].size(),v;
    for(i=0;i<j;i++)
    {
        v=Ed[u][i];
        if(viss[v]==0)
        {
            Edd[u].pb(v);
             dfs(v,1);
        }
    }
}
int rec(int u,int tk,int par)
{
    int &ret=dp[u][tk];
    if(ret!=-1)
        return ret;
    ret=10000;
    for(int i=0;i<=tk;i++)
    {
        if(nxt[u]!=-1)
           {
               if(cost[par][u]<=i)
               {
                   if(Edd[u].size()>0)
                     ret=min(ret,rec(Edd[u][0],i-cost[par][u],u)+rec(nxt[u],tk-i,par));
                   else
                     ret=min(ret,rec(nxt[u],tk-i,par));
               }
               else
               {
                   if(Edd[u].size()>0)
                     ret=min(ret,1+rec(Edd[u][0],K,u)+rec(nxt[u],tk,par));
                   else
                     ret=min(ret,1+rec(nxt[u],tk,par));
               }
           }
        else
        {
             if(cost[par][u]<=i)
               {
                   if(Edd[u].size()>0)
                     ret=min(ret,rec(Edd[u][0],i-cost[par][u],u));
                   else
                     ret=0;
               }
               else
               {
                   if(Edd[u].size()>0)
                     ret=min(ret,1+rec(Edd[u][0],K,u));
                   else
                     ret=min(ret,1);
               }
        }
    }
   // pf("%d %d %d\n",par,u,ret);
    return ret;
}
int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;

    //freopen(".txt","r",stdin);
    sn("%d",&t);
    while(t--)
    {
        sn("%d %d",&n,&m);K=m;
        memset(vis,0,sizeof(vis));
        for(i=0;i<n-1;i++)
        {
            sn("%d %d %d",&u,&v,&c);u--;v--;
            cost[u][v]=cost[v][u]=c;
            vis[u]++;vis[v]++;
            Ed[u].pb(v);
            Ed[v].pb(u);
        }

        memset(viss,0,sizeof(viss));
        memset(dp,-1,sizeof(dp));
        memset(nxt,-1,sizeof(nxt));
        for(i=0;i<n;i++)
        {
            if(vis[i]==1)
             {
                 r=i;
                 break;
             }
        }
        dfs(r,0);
        for(i=0;i<n;i++)
        {
            for(j=1;j<Edd[i].size();j++)
            {
                nxt[Edd[i][j-1]]=Edd[i][j];
            }
        }
        cost[n][r]=cost[r][n]=10000;
        pf("Case %d: %d\n",cs++,rec(r,0,n));
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


