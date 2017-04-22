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
ll dp[25][10005],ar[]={1,8,27,64,125,216,343,512,729,1000,1331,1728,2197,2744,3375,4096,4913,5832,6859,8000,9261};

ll rec(ll w,ll p)
{
    if(p>=21)
    {
        if(w==0) return 1;
        else return 0;
    }
    if(dp[p][w]!=-1)
        return dp[p][w];
    ll r1=0,r2=0;
        if(w-ar[p]>=0)
           r1=r1+rec(w-ar[p],p);
           r2=r2+rec(w,p+1);
   return dp[p][w]=r1+r2;
}

int main()
{
    ll i,j,k,l,t,r,s,m,n,a,b,c,d,e,f,g,h,u,v;
    memset(dp,-1,sizeof(dp));
     while(scanf("%lld",&n)==1)
     {
         printf("%lld\n",rec(n,0));
     }
    return 0;
}

