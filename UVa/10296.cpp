//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<queue>
#include<set>
#include <iostream>
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
int cost[20][20],dp[1<<16];
vector<int>Ed[20],ar;

int rec(int msk,int n)
{
    if(msk==(1<<n)-1)
        return 0;
    int &ret=dp[msk];
    if(ret!=-1)
        return ret;
    ret=100000000;
    for(int i=0;i<ar.size();i++)
       for(int j=0;j<ar.size();j++)
       {
          int u=(1<<i)|(1<<j);
          if(i!=j&&(msk&u)==0)
          {
              ret=min(ret,cost[ar[i]][ar[j]]+rec(msk|u,n));
          }
       }

    return ret;
}
int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;

    //freopen(".txt","r",stdin);
      while(sn("%d",&n)!=EOF)
      {
          if(n==0)break;
          sn("%d",&m);h=0;
          for(i=1;i<=n;i++)
             for(j=1;j<=n;j++)
             {
                 cost[i][j]=1000000000;
             }
          for(i=0;i<m;i++)
          {
              sn("%d %d %d",&u,&v,&c);
              h=h+c;
              Ed[u].pb(v);
              Ed[v].pb(u);
              cost[v][u]=min(cost[v][u],c);
              cost[u][v]=min(cost[u][v],c);
          }
          for(i=1;i<=n;i++)
          {
              for(j=1;j<=n;j++)
              {
                  for(k=1;k<=n;k++)
                  {
                      cost[i][j]=min(cost[i][j],cost[i][k]+cost[k][j]);
                  }
              }
          }
          for(i=1;i<=n;i++)
          {
              if(Ed[i].size()%2==1)
                ar.pb(i);
          }
          memset(dp,-1,sizeof(dp));
          pf("%d\n",h+rec(0,ar.size()));
          ar.clear();
          for(i=1;i<=n;i++)
            Ed[i].clear();
      }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/
