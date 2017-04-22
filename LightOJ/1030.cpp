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
int ar[105],vis[105][105];
double dp[105][105];

double rec(int p,int n)
{
  if(p==n-1) return (double)ar[p];
  if(p>=n)   return 0.0;

 double &ret=dp[p][n];

 if(vis[p][n]!=-1)return ret;
   vis[p][n]=1;
  ret=(double)ar[p];
  int k=min(6,n-p-1);

  double pp=1.0/(double)k;

  for(int j=0,i=p+1;j<k&&i<n;j++,i++)
  {
    ret=ret+(pp*rec(i,n));
  }
   return ret;
}
int main()
{
    int i,j,k,l,t,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;
     scanf("%d",&t);
     while(t--){
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d",&ar[i]);
        }
        memset(vis,-1,sizeof(vis));
        printf("Case %d: %.9lf\n",r++,rec(0,n));
     }
    return 0;
}




