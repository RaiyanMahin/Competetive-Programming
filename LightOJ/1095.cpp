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
ll mod=1000000007,dp[1004][1004];
ll fac[1009];
int main()
{
    ll i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;
  #ifdef O_judge
    //freopen(".txt","r",stdin);
  #endif
      sn("%lld",&t);
      fac[0]=1;
      for(i=1;i<=1005;i++)
        fac[i]=(i*fac[i-1])%mod;
      memset(dp,0,sizeof(dp));
      dp[1][1]=1;
      dp[1][0]=1;
      for(i=2;i<=1002;i++)
      {
          dp[i][0]=1;
          for(j=1;j<=1002;j++)
          {
              dp[i][j]=(dp[i-1][j]+dp[i-1][j-1])%mod;
              if(j>i)dp[i][j]=0;
          }
      }
     // pf("%lld\n",dp[6][3]);
      while(t--)
      {
          sn("%lld %lld %lld",&n,&m,&k);
          u=m-k;
          a=fac[n-m];
          v=0;
          for(i=1;i<=u;i++)
          {
              a=fac[n-k-i];
              b=(a*dp[u][i])%mod;
              if(i%2==1)
                v=(v+b)%mod;
              else
                v=(v-b+mod)%mod;
          }
          v=(fac[n-k]-v+mod)%mod;
          u=(dp[m][k]*v)%mod;
          pf("Case %lld: %lld\n",cs++,u);
      }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/
