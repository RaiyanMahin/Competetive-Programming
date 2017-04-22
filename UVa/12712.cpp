//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<queue>
#include<set>
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
ll dpp[10005],dp[10005],mod=10000000000007;
int main()
{
    ll i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;
     sn("%lld",&t);
    while(t--)
    {
       ll ans=0;
       sn("%lld %lld %lld",&n,&a,&b);
        u=1;
       for(i=n*n;i>=(n*n-b+1);i--)
       {
           u=(u*i)%mod;
           if(i<=(n*n-a+1))
           ans=(ans+u)%mod;
       }
       pf("Case %lld: %lld\n",cs++,ans);
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/

