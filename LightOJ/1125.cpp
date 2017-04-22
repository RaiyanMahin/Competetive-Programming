

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
ll ar[205],dp[201][11][21];

ll rec(ll p,ll q,ll md,ll m,ll k,ll n)
{
    if(p>=n)
    {
        if(q==m&&md==0)return 1;
        else return 0;
    }
    if(q==m)
    {
        if(md==0)return 1;
        else return 0;
    }

    ll &ret=dp[p][q][md];
    if(ret!=-1)
        return ret;
    ret=0;
    for(int i=p;i<n;i++)
    {
        ret=ret+rec(i+1,q+1,(md+ar[i])%k,m,k,n);
    }
    return ret;
}
int main()
{
    ll i,j,k,l,t,cs=1,r=1,s,m,n,a,q,b,c,d,e,f,g,h,u,v;
     sn("%lld",&t);
     while(t--)
     {
         sn("%lld%lld",&n,&q);
         for(i=0;i<n;i++)
         {
             sn("%lld",&ar[i]);
         }
         pf("Case %lld:\n",cs++);
         while(q--)
         {
             sn("%lld %lld",&k,&m);
             memset(dp,-1,sizeof(dp));
             pf("%lld\n",rec(0,0,0,m,k,n));
         }
     }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/
