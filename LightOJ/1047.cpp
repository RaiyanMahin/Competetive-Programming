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
    return a<b?a:b;
}
int dp[30][3000],ar[30][30],vis[30];
int rec(int p,int j,int n)
{
    if(p>=n)
        return 0;
    if(dp[p][j]!=-1)
      return dp[p][j];
    int m=2000000000,i;
    for(i=0;i<3;i++)
    if(i!=j)
      m=maxx(m,ar[p][i]+rec(p+1,i,n));
    return dp[p][j]=m;
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
             for(j=0;j<3;j++)
             {
                 scanf("%d",&ar[i][j]);
             }
         }
         memset(dp,-1,sizeof(dp));
         memset(vis,0,sizeof(vis));
         printf("Case %d: %d\n",r,rec(0,30,n));
     }
    return 0;
}


