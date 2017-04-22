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
int maxx(int a,int b)
{
    return a>b?a:b;
}

int n,w,k,ar[200],dp[200][200];
int rec(int p,int m)
{
    if(m>=k||p>=n)
        return 0;
    if(dp[p][m]!=-1)
        return dp[p][m];
   int mx=0,i,j,l=0;
    j=ar[p]+w;
    for(i=p;i<n;i++)
    {
        if(ar[i]<=j) l++;
    }
    mx=maxx(mx,rec(p+1,m));
    mx=maxx(mx,l+rec(p+l,m+1));
   return dp[p][m]=mx;
}
int main()
{
    int i,j,l,t,r,s,m,a,b,c,d,e,f,g,h,u,v;
       scanf("%d",&t);
    for(r=1;r<=t;r++)
     {
        scanf("%d %d %d",&n,&w,&k);
        for(i=0;i<n;i++)
        {
            scanf("%d %d",&a,&ar[i]);
        }
        sort(ar,ar+n);
        memset(dp,-1,sizeof(dp));
        printf("Case %d: %d\n",r,rec(0,0));
     }
    return 0;
}

