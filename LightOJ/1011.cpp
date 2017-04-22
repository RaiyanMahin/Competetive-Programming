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
int maxx(int a,int b)
{
    return a>b?a:b;
}
int dp[18][70000],ar[30][30],vis[30];
int rec(int p,int mask,int n)
{
    if(p>=n)
        return 0;
    if(dp[p][mask]!=-1)
      return dp[p][mask];
    int m=0;
    for(int i=0;i<n;i++)
    {
        if(!(mask&(1<<i)))
            m=maxx(m,ar[p][i]+rec(p+1,(mask|(1<<i)),n));
    }
    return dp[p][mask]=m;
}

int main()
{
    int i,j,k,l,t,r,s,m,n,a,b,c,d,e,f,g,h,u,v;
     scanf("%d",&t);
     for(r=1;r<=t;r++)
     {
         scanf("%d",&n);
         for(i=0;i<n;i++)
         {
             for(j=0;j<n;j++)
             {
                 scanf("%d",&ar[i][j]);
             }
         }
         memset(dp,-1,sizeof(dp));
         memset(vis,0,sizeof(vis));
         printf("Case %d: %d\n",r,rec(0,0,n));
     }
    return 0;
}

