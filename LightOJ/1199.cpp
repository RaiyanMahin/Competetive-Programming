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
int dp[10005],vis[10005];
int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;
    s=0;
    dp[0]=dp[1]=dp[2]=0;
    for(i=3;i<=10005;i++)
    {
        dp[i]=0;
        for(j=1;j<i-j;j++)
        {
            vis[(dp[j]^dp[i-j])]=i;
            dp[i]=max(dp[i],(dp[j]^dp[i-j]));
        }
        for(j=0,k=dp[i];j<=k;j++)
        {
            if(vis[j]!=i)
                break;
        }
        dp[i]=j;
    }
    sn("%d",&t);
    while(t--)
    {
        sn("%d",&n);
        s=0;
        for(i=0;i<n;i++)
        {
            sn("%d",&a);
            s=s^dp[a];
        }
        pf("Case %d: ",cs++);
        if(s==0)
        {
            pf("Bob\n");
        }
        else
            pf("Alice\n");
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/

