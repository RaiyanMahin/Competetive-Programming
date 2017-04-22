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
int a;
};
int dp[2][60][3001],ar[60][60];
int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;
    while(scanf("%d",&n)==1)
    {
        if(n==0)break;
        for(i=0;i<2*n-1;i++)
        {
            for(j=0;j<=n-1-abs(n-i-1);j++)
            {
                scanf("%d",&a);ar[i][j]=abs(a);
            }
        }

        memset(dp,-1,sizeof(dp));
        u=(2*n-2)%2;
        dp[u][0][ar[2*n-2][0]]=2*n-2;
        for(i=2*n-3;i>=0;i--)
        {
            u=i%2;
            for(j=0;j<=n-1-abs(n-1-i);j++)
            {
                for(k=3000;k>=0;k--)
                {
                    h=k+ar[i][j];
                    g=abs(k-ar[i][j]);
                    if(i<n-1)
                    {

                         if(dp[1-u][j][k]==i+1&&h<=3000)
                             dp[u][j][h]=i;
                         if(dp[1-u][j][k]==i+1)
                            dp[u][j][g]=i;
                        if(dp[1-u][j+1][k]==i+1&&h<=3000)
                             dp[u][j][h]=i;
                         if(dp[1-u][j+1][k]==i+1)
                            dp[u][j][g]=i;
                    }
                    else
                    {
                        if(j!=n-1-abs(n-1-i)){
                         if(dp[1-u][j][k]==i+1&&h<=3000)
                             dp[u][j][h]=i;
                         if(dp[1-u][j][k]==i+1)
                            dp[u][j][g]=i;
                        }
                         if(j>0&&dp[1-u][j-1][k]==i+1&&h<=3000)
                             dp[u][j][h]=i;
                         if(j>0&&dp[1-u][j-1][k]==i+1)
                            dp[u][j][g]=i;

                    }
                }
            }

        }
        for(i=0;i<=3000;i++)
            if(dp[0][0][i]==0)
                break;
      printf("%d\n",i);

    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/


