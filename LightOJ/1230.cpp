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
vector<int>Ed[1005],Edd[1005];
int vis[1005],viss[1005],dp[1005][2],dpp[1005][1005][3];
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
int rec(int u,int tk)
{
    int &ret=dp[u][tk];
    if(ret!=-1)
        return ret;
    ret=1;
    for(int i=0;i<Edd[u].size();i++)
    {
        ret=ret+rec(Edd[u][i],1);
    }
    if(tk)
    {
       int s=0;
       for(int i=0;i<Edd[u].size();i++)
        {
            s=s+rec(Edd[u][i],0);
        }
        ret=min(ret,s);
    }
    return ret;
}
int rec2(int u,int rem,int tk)
{
    int &ret=dpp[u][rem][tk];
    if(ret!=-1)
        return ret;
    ret=0;

    int sum=0;
    for(int i=0;i<Edd[u].size();i++)
    {
        sum=sum+dp[Edd[u][i]][1];
    }
    if(sum==rem-1)
    {
        if(tk==1)
          ret=1;
        for(int i=0;i<Edd[u].size();i++)
        {
            ret=ret+rec2(Edd[u][i],dp[Edd[u][i]][1],1);
        }
    }
    if(tk)
    {
       int s=0;
       int sum=0;
        for(int i=0;i<Edd[u].size();i++)
        {
            sum=sum+dp[Edd[u][i]][0];
        }
        if(sum==rem)
        {
            for(int i=0;i<Edd[u].size();i++)
            {
                s=s+rec2(Edd[u][i],dp[Edd[u][i]][0],0);
            }
        }
        ret=max(ret,s);
    }
    return ret;
}
vector<int>root;
int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;

    //freopen(".txt","r",stdin);
    sn("%d",&t);
    while(t--)
    {
        sn("%d %d",&n,&m);
        memset(vis,0,sizeof(vis));
        for(i=0;i<m;i++)
        {
            sn("%d %d",&u,&v);
            vis[u]++;vis[v]++;
            Ed[u].pb(v);
            Ed[v].pb(u);
        }

        memset(viss,0,sizeof(viss));
        memset(dp,-1,sizeof(dp));
        memset(dpp,-1,sizeof(dpp));
        a=b=0;
        for(i=0;i<n;i++)
        {
            if(vis[i]==1&&viss[i]==0){
               dfs(i,0);
               u=rec(i,1);
               a+=u;
               b+=rec2(i,u,2);
            }
        }
        c=m-b;
        pf("Case %d: %d %d %d\n",cs++,a,b,c);
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

