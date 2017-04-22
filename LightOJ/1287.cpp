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
double dp[(1<<15)+1][15];
bool vis[(1<<15)+1][15];
vector<int>Ed[15];
vector<int>cost[15];
int dpp[(1<<15)+1][15];
int rec2(int p,int msk,int n)
{
    if(msk==(1<<n)-1)
        return 1;
    int &ret=dpp[msk][p];
    if(dpp[msk][p]!=-1)
        return ret;
    ret=0;
    double P=0,Q=0;
    int i,v,c=0;
        for(i=0;i<Ed[p].size();i++)
        {
            v=Ed[p][i];
            if((msk&(1<<v))==0)
                {
                    ret=max(ret,rec2(v,msk|(1<<v),n));
                }
        }
    return ret;
}
double rec(int p,int msk,int n)
{
    double &ret=dp[msk][p];
    if(vis[msk][p]==1)
        return ret;
    vis[msk][p]=1;
    ret=0;
    double P=0,Q=0;
    int i,v,c=0;
    for(i=0;i<Ed[p].size();i++)
    {
        v=Ed[p][i];
        if((msk&(1<<v))==0&&rec2(v,msk|(1<<v),n)==1)
            c++;
    }
    if(c)
    {
        P=(c+1);
        P=1/P;
        P=P*(1.0/(1-P));
        ret=5.0*P;
        for(i=0;i<Ed[p].size();i++)
        {
            v=Ed[p][i];
            if((msk&(1<<v))==0&&rec2(v,msk|(1<<v),n)==1)
                {
                    ret+=P*(cost[p][i]*1.0+rec(v,msk|(1<<v),n));
                }
        }
    }
    return ret;
}

int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;
    //freopen(".txt","r",stdin);
    sn("%d",&t);
    while(t--)
    {
        sn("%d %d",&n,&m);
        for(i=0;i<m;i++)
        {
            sn("%d %d %d",&u,&v,&c);
            Ed[u].pb(v);
            Ed[v].pb(u);
            cost[v].pb(c);
            cost[u].pb(c);
        }
        memset(vis,0,sizeof(vis));
        memset(dpp,-1,sizeof(dpp));
        pf("Case %d: %.9lf\n",cs++,rec(0,1<<0,n));
        for(i=0;i<n;i++)
            Ed[i].clear(),cost[i].clear();
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/
