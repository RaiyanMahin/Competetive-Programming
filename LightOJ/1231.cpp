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

typedef long long int ll;
using namespace std;
struct T{
int a;
};
ll ar[100],aa[100],dp[55][1005],n,md=100000007;

ll rec(ll w,ll p)
{

    if(p>=n||w<=0)
    {
        if(w==0) return 1;
        else  return 0;
    }
    if(dp[p][w]!=-1)
        return dp[p][w];
    ll r1=0,r2=0;
    for(int i=1;i<=aa[p];i++)
        if(w-ar[p]*i>=0)
         {
             r1=(r1+rec(w-ar[p]*i,p+1))%md;
         }
         else
            break;
      r2=(r2+rec(w,p+1))%md;
    return dp[p][w]=(r1+r2)%md;
}
int main()
{
    ll i,j,k,l,t,r,s,m,a,b,c,d,e,f,g,h,u,v;
     scanf("%lld",&t);

     for(r=1;r<=t;r++)
     {
         scanf("%lld %lld",&n,&k);
         for(i=0;i<n;i++)
         {
             scanf("%lld",&ar[i]);
         }
         for(i=0;i<n;i++)
         {
             scanf("%lld",&aa[i]);
         } memset(dp,-1,sizeof(dp));
        printf("Case %lld: %lld\n",r,rec(k,0)%md);
     }
    return 0;
}

