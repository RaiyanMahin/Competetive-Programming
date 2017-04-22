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
int ar[105],n;
ll dp[100005],md=100000007;
int main()
{
    int i,j,k,l,t,r,s,m,a,b,c,d,e,f,g,h,u,v;
    scanf("%d",&t);
    for(r=1;r<=t;r++)
    {
        scanf("%d %d",&n,&m);
        for(i=0;i<n;i++)
        {
            scanf("%d",&ar[i]);
        }
       dp[0]=1;
       for(i=1;i<=m;i++)
         dp[i]=0;
       for(i=0;i<n;i++)
       {
           for(j=ar[i];j<=m;j++)
           {
               if(dp[j-ar[i]]!=0)
               {
                   dp[j]=(dp[j]+dp[j-ar[i]])%100000007;
               }
           }
       }
        printf("Case %d: %lld\n",r,dp[m]%100000007);
    }
    return 0;
}

