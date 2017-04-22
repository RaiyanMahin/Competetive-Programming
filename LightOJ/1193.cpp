//BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
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
ll dp[15005][2];
int main()
{
    ll i,j,k,l,t,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v,pre,cur;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld %lld %lld",&n,&k,&s);
        memset(dp,0,sizeof(dp));
        pre=0;cur=1;

        for(i=1;i<=n;i++)
        {
            a=b=0;
            if(i==1)
                  dp[0][pre]=1;
            else
                  dp[0][pre]=0;
            for(j=1;j<=s;j++)
            {
                a=a+dp[j-1][pre];
                if(j>k)
                {
                    a=a-dp[j-k-1][pre];
                }
                 if(j>k)
                {
                    b=b-(k*dp[j-k-1][pre]);
                }
                b=b+a;
                dp[j][cur]=b%100000007;
            }
            swap(pre,cur);
        }
        printf("Case %lld: %lld\n",r++,dp[s][pre]);
    }
    return 0;
}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);

  using namespace std;

  int main() { _

    return 0;
  }
*/

