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
int dp[105][105][105];
int rec(int p,int st,int en)
{
    if(st>en)
        return 0;
    int &ret=dp[p][st][en];
    if(ret!=-1)
        return ret;
    ret=100000000;
    for(int i=st;i<=en;i++)
    {
        ret=min(ret,max(i+rec(p-1,st,i-1),i+rec(p,i+1,en)));
    }
    return ret;
}
int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;

    //freopen(".txt","r",stdin);
    memset(dp,0,sizeof(dp));
    //pf("%d\n",rec(2,1,6));
    u=100;v=100;
    for(i=1;i<=100;i++)
    {
        for(j=i;j<=100;j++)
        {
            dp[1][i][j]=(i+j)*(j-i+1)/2;
        }
    }
    for(i=2;i<=100;i++)
        for(j=1;j<=100;j++)
        dp[i][j][j]=j;
    for(i=2;i<=100;i++)
    {
       for(j=1;j<=100;j++)
        {
            for(k=j;k>0;k--)
            {
                dp[i][k][j]=1000000000;
                for(h=k;h<=j;h++)
                {
                    dp[i][k][j]=min(dp[i][k][j],h+max(dp[i-1][k][h-1],dp[i][h+1][j]));
                }
            }
        }
    }
    sn("%d",&t);
    while(t--)
    {
        sn("%d %d",&n,&m);
        pf("Case %d: %d\n",cs++,dp[n][1][m]);
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/

