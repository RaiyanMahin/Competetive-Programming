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
double dp[1005][21];
int vis[1005][21];
double rec(int p,int a,int b,int c,int d)
{
    if(a<0||b<0||p>100)
    {
        if(b<0)
            return 1.0;
        return 0;
    }
    double &ret=dp[p][a];
    if(vis[p][a]!=0)
        return dp[p][a];
    vis[p][a]=1;
    ret=0.0;
    double P=c;
    P/=6.0;
    ret=ret+P*rec(p+1,a+d,b-d,c,d);
    ret=ret+(1.0-P)*rec(p+1,a-d,b+d,c,d);
    return ret;
}
int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;

    //freopen(".txt","r",stdin);
    while(sn("%d %d %d %d",&a,&b,&c,&d)!=EOF&&a+b+c+d)
    {
//        memset(vis,0,sizeof(vis));
//        pf("%.1lf\n",rec(0,a,b,c,d)*100.0);
          for(i=0;i<22;i++)
            dp[0][i]=0.0;
          dp[0][a]=1;
          f=0;
          double P=c;P/=6.0;
          double ans=0;
          for(i=1;i<=50;i++)
          {
              for(j=1;j<a+b;j++)
              {
                  if(a+b-j<=d)
                  {
                      ans=ans+P*dp[f][j];
                  }
              }
              for(j=1;j<a+b;j++)
              {
                  dp[1-f][j]=0;
                  if(j-d>0)
                  {
                      dp[1-f][j]+=dp[f][j-d]*P;
                  }
                  if(j+d<a+b)
                  {
                      dp[1-f][j]+=dp[f][j+d]*(1-P);
                  }
              }
              f=1-f;

          }


          pf("%.1lf\n",ans*100);
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/

