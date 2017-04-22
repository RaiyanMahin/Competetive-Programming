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
ll n,k,dp[35][1000];
ll rec(ll p,ll m,ll w)
{
     if(m==k)
     {
         return w*(n-p)*(n+1-m);
     }
     ll &ret=dp[p][m];
     if(ret!=-1)
        return ret;
     ret=0;
     for(int i=p;i<n;i++)
     if((n-i)>=k-m)
     {
         ret=ret+rec(i+1,m+1,w*(n+1-m));
     }
    return ret;
}
int main ()
{
    ll i,j,l,m,t,r;
    sn("%lld",&t);
    for(r=1;r<=t;r++)
    {
        sn("%lld %lld",&n,&k);
        memset(dp,-1,sizeof(dp));
        m=0;
        if(k<=n)
        m=rec(0,1,1);
        if(k==0)
            m=1;
        pf("Case %lld: %lld\n",r,m);
    }
    return 0;
}
