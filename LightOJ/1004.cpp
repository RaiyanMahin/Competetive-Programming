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
int ar[300][300],dp[300][300],n;

int maxx(int a,int b)
{
    return a>b?a:b;
}
int recur(int i,int j)
{
       if(ar[i][j]==0)
          return 0;
       if(dp[i][j]!=-1)
       {
           return dp[i][j];
       }
       dp[i][j]=maxx(dp[i][j],ar[i][j]+recur(i+1,j));
       dp[i][j]=maxx(dp[i][j],ar[i][j]+recur(i+1,j+1));
      return dp[i][j];
}
int main()
{
    int i,j,k,l,t,r,s,m,a,b,c,d,e,f,g,h,u,v;
      scanf("%d",&t);

      for(r=1;r<=t;r++)
      {
           memset(ar,0,sizeof(ar));
          scanf("%d",&n);a=1;
          m=2*n-1;b=0;  h=0;
          for(i=0;i<2*n-1;i++)
          {
              for(j=0,c=0;c<a;j++)
              {
                  if(j>=b)
                  scanf("%d",&ar[i][j]),c++;
              }
              if(a<n&&h==0)
                 a++;
              else
                a--,b++,h=1;

          }
          memset(dp,-1,sizeof(dp));
          pf("Case %d: %d\n",r,recur(0,0));
      }
    return 0;
}

