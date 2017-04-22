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
int ar[106],arr[8][2]={{1,1},{3,0},{2,3},{3,2},{3,1},{1,3}};
unsigned long long dp[(1<<8)+2][(1<<8)+2],dpp[102][(1<<8)+1];
bool vis[102][(1<<8)+1];
char st[1055];
unsigned long long rec(int p,int pmsk,int cmsk,int n,int m)
{
    if(p>=n)
    {
        if(cmsk==0)
            return 1;
        return 0;
    }
    unsigned long long &ret=dpp[p][cmsk];
    if(vis[p][cmsk]==1)
        return ret;
    vis[p][cmsk]=1;
    ret=0;
    int u=(1<<m)-1;u=u^cmsk;
    for(int i=0;i<(1<<m);i++)
    {
        if(dp[u][i]>0&&(i&ar[p+1])==0)
        {
            ret=ret+dp[u][i]*rec(p+1,(1<<m)-1,ar[p+1]|i,n,m);
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
        memset(ar,0,sizeof(ar));
        if(m<=8)
        {
            for(i=0;i<n;i++)
            {
                sn("%s",&st);
                for(j=0;j<m;j++)
                {
                    if(st[j]=='#')
                        ar[i]|=(1<<(m-j-1));
                }
            }
        }
        else
        {
            for(i=0;i<n;i++)
            {
                sn("%s",&st);
                for(j=0;j<m;j++)
                {
                    if(st[j]=='#')
                        ar[j]|=(1<<(n-i-1));
                }
            }
            swap(n,m);
        }
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;h=0;
        for(k=0;k<6;k++)
        {
            if(k>0)h=1;
           for(a=0;a<m-h;a++){
                u=(arr[k][0]<<a);
                v=(arr[k][1]<<a);
                for(i=0;i<(1<<m);i++)
                {
                    for(j=0;j<(1<<m);j++)
                    {
                        if((i&u)==0&&(j&v)==0)
                            {
                                dp[i|u][j|v]+=dp[i][j];
                            }
                    }
                }
           }
        }
        memset(vis,0,sizeof(vis));
        pf("Case %d: %llu\n",cs++,rec(0,(1<<m)-1,ar[0],n,m));
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/

