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
ll dpp[55][55][55];

ll rec(int ps,int re,int mx)
{
    if(ps==0&&re==0)
        return 1;
    if(ps<=0||re==0)
        return 0;
    ll &ret=dpp[ps][re][mx];
    if(ret!=-1)
        return ret;
    ret=0;
    for(int i=1;i<=mx;i++)
        if(re-i>=0)
        ret+=rec(ps-1,re-i,mx);
    return ret;
}
int main()
{
    ll i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;
    memset(dpp,-1,sizeof(dpp));

    sn("%lld",&t);
    while(t--)
    {
        sn("%lld %lld %lld",&n,&k,&m);
        a=0;
        pf("Case %lld: %lld\n",cs++,rec(k,n,m));
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/
