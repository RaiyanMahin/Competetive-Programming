//BISMILLAHIR RAHMANIR RAHIM
//#include <bits/stdc++.h>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<queue>
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
ll Inf=1000000000000;

struct T{
int a;
};
ll cost[15][15],dp[1<<15];

 ll rec(ll st,ll en,ll msk,ll w)
 {
         if(msk==((1<<en)-1))
         {
             return 0;
         }
     ll &ret=dp[msk],s;
     if(ret!=-1)
        return ret;
      ret=Inf;
    for(int i=0;i<en;i++)
    {
        if(!(msk&(1<<i)))
           {
                s=cost[i][i];
              for(int j=0;j<en;j++)
                {
                    if(msk&(1<<j))
                     {
                        s=s+cost[i][j];
                     }
                }
                ret=min(ret,s+rec(i,en,msk|(1<<i),w));
           }
    }
     return ret;
 }

int main()
{
    ll i,j,k,l,t,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;
   //  freopen("Output.txt","r",stdin);
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                scanf("%lld",&cost[i][j]);
            }
        }
        ll ans=Inf;memset(dp,-1,sizeof(dp));
        for(i=0;i<n;i++)
        {
            ans=min(ans,cost[i][i]+rec(i,n,(1<<i),0));
        }
        printf("Case %lld: %lld\n",r++,ans);
    }
    return 0;
}

