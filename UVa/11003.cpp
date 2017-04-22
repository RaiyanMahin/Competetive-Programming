//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<queue>
#include<set>
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
int w,m,a;
}ar[1005];
int dp[6005];
/*
6
4 8
2 5
3 10
5 2
1 1
1 1
*/
int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;
    while(scanf("%d",&n)==1)
    {
        if(n==0)
            break;
        for(i=0;i<n;i++)
        {
            scanf("%d %d",&ar[i].w,&ar[i].m);
        }
        memset(dp,-1,sizeof(dp));
        int ans=1;dp[0]=0;
        for(i=n-1;i>=0;i--)
        {
            for(j=ar[i].m;j>=0;j--)
            {
                if(dp[j]!=-1&&dp[j+ar[i].w]<dp[j]+1)
                {
                    dp[j+ar[i].w]=dp[j]+1;
                    if(dp[j+ar[i].w]>ans)ans=dp[j+ar[i].w];
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/

