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
int vis[10000]={0};
vector<int>pr;
void prim(int n)
{
    int i,j,k,l;
    for(i=3;i<=sqrt(n)+1;i+=2)
    {
        if(vis[i]==0)
        {
            for(j=i*i;j<=n;j+=i*2)
                if(j%i==0)
                vis[j]=1;
        }
    }
    pr.pb(2);
    for(i=3;i<=n;i+=2)
        if(vis[i]==0)
        {
           pr.pb(i);
       }
}
ll ar[505][505],dp[505][505],mod=1000000007;
ll rec(int n,int k)
{
    if(k==1)
    {
        return ar[k][n-1];
    }
    ll &ret=dp[n][k];
    if(ret!=-1)
        return ret;
    ret=0;

    for(int i=1;i<=n-k+1;i++)
    {
        ll u=(ar[k][i-1]*(pr[k-1]-1))%mod;
        ret=(ret+(u*rec(n-i,k-1)%mod))%mod;
    }
    return ret;
}

int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;
  #ifdef O_judge
    //freopen(".txt","r",stdin);
  #endif
     prim(5000);
     for(i=0;i<501;i++)
     {
         ar[i+1][0]=1;
         for(j=1;j<501;j++)
         {
             ar[i+1][j]=(ar[i+1][j-1]*pr[i])%mod;
         }
     }
     sn("%d",&t);
     memset(dp,-1,sizeof(dp));
     while(t--)
     {
         sn("%d %d",&n,&k);
         pf("Case %d: %lld\n",cs++,rec(n,k));
     }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/

