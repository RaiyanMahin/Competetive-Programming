//BISMILLAHIR RAHMANIR RAHIM
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
ll n,k,dp[26][200];
ll rec(ll p,ll w)
{
    if(p>=n)
    {
        if(w>=k)
            return 1;
        else
            return 0;
    }
    ll &ret=dp[p][w];
    if(ret!=-1)
        return ret;
    ret=0;
    for(int i=1;i<=6;i++)
    {
            ret=ret+rec(p+1,w+i);
    }
    return ret;
}
ll gcd(ll a,ll b)
{
    if(a%b==0)
        return b;
    else
        return gcd(b,a%b);
}
int main()
{
    ll i,j,l,t,r,s,m,a,b,c,d,e,f,g,h,u,v;
    scanf("%lld",&t);
    for(r=1;r<=t;r++)
    {
        scanf("%lld %lld",&n,&k);
        memset(dp,-1,sizeof(dp));
        a=1;
       for(i=0;i<n;i++)
       {
           a=a*6;
       }
       if(k<=n)
       {
           printf("Case %lld: 1\n",r);
       }
       else if(k>n*6)
       {
           printf("Case %lld: 0\n",r);
       }
       else
       {
           b=rec(0,0);
        g=gcd(a,b);
        a=a/g;
        b=b/g;
        printf("Case %lld: %lld/%lld\n",r,b,a);
       }
    }
    return 0;
}


