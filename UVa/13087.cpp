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
int dp[255][255],dpp[255][255][130];
char st[333];
int rec(int be,int en,int d)
{
    if(en-be<=d)
        {
            dp[be][en]=0;
            return 0;
        }
    int &ret=dp[be][en];
    if(ret!=-1)
        return ret;
    ret=0;
    ret=rec(be+1,en,d);
    //ret=max(ret,rec(be,en-1,d));
    int i=en;
    for(int i=be+d+1;i<=en;i++)
    {
        if((st[be]=='A'&&st[i]=='U')||(st[be]=='U'&&st[i]=='A')||(st[be]=='C'&&st[i]=='G')||(st[be]=='G'&&st[i]=='C'))
        {
            ret=max(ret,1+rec(be+1,i-1,d)+rec(i+1,en,d));
        }
    }
    return ret;
}
int rec2(int be,int en,int rem,int d)
{
    if(rem==0)
        return 1;
    if(en-be<=d)
        return 0;
    int &ret=dpp[be][en][rem];
    if(ret!=-1)
        return ret;
    ret=0;
    ll temp=0;
    temp=temp+rec2(be+1,en,rem,d);
   for(int i=be+d+1;i<=en;i++)
    {
        if(((st[be]=='A'&&st[i]=='U')||(st[be]=='U'&&st[i]=='A')||(st[be]=='C'&&st[i]=='G')||(st[be]=='G'&&st[i]=='C'))&&1+dp[be+1][i-1]+dp[i+1][en]==rem)
        {
              temp=(temp+rec2(be+1,i-1,dp[be+1][i-1],d)*rec2(i+1,en,dp[i+1][en],d));
        }
    }
    ret=temp-(temp/10007)*10007;
    return ret;
}
int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;

    //freopen(".txt","r",stdin);
    sn("%d",&t);
    while(t--)
    {
        sn("%d %s",&k,&st);
        memset(dp,-1,sizeof(dp));
        memset(dpp,-1,sizeof(dpp));
        a=rec(0,strlen(st)-1,k);
        pf("Case %d: %d %d\n",cs++,a,rec2(0,strlen(st)-1,a,k)%10007);
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/
