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
struct T{
int a;
};
ll dp[11][11],ar[11];
ll rec(ll st,ll cnt,ll en,ll m)
{
    if(cnt>=m)
    {
        return 1;
    }
    ll &ret=dp[st][cnt];
    if(ret!=-1)
        return ret;
    ret=0;
    for(int i=0;i<en;i++)
    {
        if(st==0||abs(ar[i]-st)<=2)
        {
            ret=ret+rec(ar[i],cnt+1,en,m);
        }
    }
    return ret;
}
int main()
{
    ll i,j,k,l,t,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld %lld",&n,&m);
        for(i=0;i<n;i++)
        {
            scanf("%lld",&ar[i]);
        }
        memset(dp,-1,sizeof(dp));
        printf("Case %lld: %lld\n",r++,rec(0,0,n,m));
    }
    return 0;
}
