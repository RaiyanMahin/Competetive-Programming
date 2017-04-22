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
ll fact[1000005],invf[1000005],ar[10000];
int main()
{
    ll i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v,mod=1000000007;
  #ifdef O_judge
    //freopen(".txt","r",stdin);
  #endif
    fact[0]=1;
    for(i=1;i<=1000005;i++)
    {
        fact[i]=(i*fact[i-1])%mod;
        invf[i]=-1;
    }
    sn("%lld",&t);
    while(t--)
    {
        sn("%lld",&n);
        ll ans=1;s=0;
        for(i=0;i<n;i++)
        {
            sn("%lld",&ar[i]);
            if(i>0)
            {
               a=s+1;
               b=ar[i]-1;
               if(b>0)
               {
                   a=a+b-1;
                   if(invf[b]==-1)
                   invf[b]=bigmod(fact[b],mod-2,mod);
                   if(invf[a-b]==-1)
                   invf[a-b]=bigmod(fact[a-b],mod-2,mod);
                   b=(invf[b]*invf[a-b])%mod;
                   b=(fact[a]*b)%mod;
                   ans=(ans*b)%mod;
               }
            }
            s=s+ar[i];
        }
        pf("Case %lld: %lld\n",cs++,ans);
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/

