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
unsigned long long dp[55][55][3],ans;
unsigned long long rec(int l,int h,int p)
{
    if(l==0&&h==0)
         return 1;
    unsigned long long &ret=dp[l][h][p];
    if(ret!=-1)
        return ret;
   ret=0;
   if(p==0)
       for(int i=1;i<=l;i++)
       {
           ret=ret+rec(i-1,h+(l-i),1);
       }
   else if(p==1)
         for(int i=1;i<=h;i++)
         {
           ret=ret+rec(l+i-1,h-i,0);
         }
   return ret;
}
int main()
{
    int i,j,k,l,t,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&m);
        memset(dp,-1,sizeof(dp));
       if(n<=2)
        ans=1;
       else if(m==1&&n>2)
            ans=rec(1,n-3,0);
       else
            ans=rec(m-1,n-m,0);
        printf("Case %d: %llu\n",r++,ans);
    }
    return 0;
}


