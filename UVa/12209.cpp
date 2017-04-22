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
vector<int>wr[505],ln[503];
int vis[503],dp[503],dis[503][503],n,m,w;

int rec(int st)
{
    if(st>n)
        return 0;
    int &ret=dp[st];
    if(ret!=-1)
        return ret;
    ret=10000000;
   // int k=min(st+m,n);

    for(int i=st;i<=n;i++)
    {
        int d=dis[st][i];
        if(d+(i-st+1)>m)break;
        ret=min(ret,rec(i+1)+d);
    }
    return ret;
}
int main()
{
    int i,j,k,l,t,cs=1,r=1,s,a,b,c,d,e,f,g,h,u,v,mx;
     sn("%d",&t);
     while(t--)
     {
         sn("%d %d %d",&n,&m,&w);
         mx=0;
           for(i=0;i<=n;i++)
            wr[i].clear();
         for(i=0;i<w;i++)
         {
             sn("%d",&u);
             for(j=0;j<u;j++)
             {
                 sn("%d",&v);
                 wr[v].pb(i+1);
             }
         }
         pf("Case %d: ",cs++);
             memset(dp,-1,sizeof(dp));
             memset(dis,-1,sizeof(dis));
          for(i=1;i<=n;i++)
          {
              set<int>II;
              for(j=i;j<=n;j++)
              {
                  for(k=0;k<wr[j].size();k++)
                  {
                      II.insert(wr[j][k]);
                  }
                  dis[i][j]=II.size();
              }
          }
             g=rec(1);
        pf("%d\n",g>=1000000 ?-1:g);

     }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/

