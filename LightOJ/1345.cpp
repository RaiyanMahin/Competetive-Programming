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
int dp[51][50][50][50][2],ans;

long long rec(int l,int h,int k,int p,int a)
{
    if(p>k)
        return 0;
    if(l==0&&h==0)
         return a;
    int &ret=dp[k][p][l][h][a];
    if(ret!=-1)
        return ret;
   ret=0;
   if(l>0){
       for(int i=1;i<=l;i++)
       {
           ret=(ret+rec(i-1,h+l-i,k,1,a))%1000000007;
       }
   }
   if(h>0)
   {
       for(int i=1;i<=h;i++)
       {
           if(p+1==k) a=1;
           ret=(ret+rec(l+i-1,h-i,k,p+1,a))%1000000007;
       }
   }
   return ret;
}

int main()
{
    int i,j,k,l,t,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;
    scanf("%d",&t);memset(dp,-1,sizeof(dp));
    while(t--){
        scanf("%d %d",&n,&m);
        ans=rec(0,n,m,0,0);
        printf("Case %d: %lld\n",r++,ans%1000000007);
    }
    return 0;
}


