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
int vis[1005][1005],cn;
double dp[1005][1005];

double rec(int t,int d)
{
    if(t==0)
        return 1.0;
    double &ret=dp[t][d];
    if(vis[t][d]==cn)
        return ret;
    vis[t][d]=cn;
   double tw=(t*(t-1))/2,tm=t,td=t*d,dm=d,tt=tw+tm+dm+td;

   double c=tw*rec(t-2,d);
   if(d>0)
   c+=td*rec(t,d-1);
      c=c/tt;

   double cc=0.0;
   if(d>0)
   cc=dm*rec(t,d-1);
   cc=cc/tt;
   double ccc=0.0;
   if(d>0)
    ccc=dm*rec(t,d);
   ccc/=tt;

   return ret=max(c+cc,c+ccc);
}

int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;
    sn("%d",&t);memset(vis,0,sizeof(vis));cn=1;
    while(t--)
    {
        sn("%d %d",&a,&b);
        if(a%2==1)
        {
            pf("Case %d: 0\n",cs++);
        }
        else if(a==0)
        {
         pf("Case %d: 1\n",cs++);
        }
        else
        {

            pf("Case %d: %.9lf\n",cs++,rec(a,b)); cn++;
        }
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/


