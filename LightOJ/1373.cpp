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
const int maxn=105;
int A[maxn],B[maxn],vis[maxn];
vector<int>adj[maxn],ad[maxn];
int tp;
bool kuhn(int u)
{
    int i,j=adj[u].size(),v;
    if(A[u]==0)
        return false;
    for(i=0;i<j;i++)
    {
        v=adj[u][i];
        if(vis[v]!=tp&&A[v]==-1)
        {
            vis[v]=tp;
            if(B[v]==-1||kuhn(B[v]))
            {
                B[v]=u;
                return true;
            }
        }
    }
    return false;
}
char st[105][105];
int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;
  #ifdef O_judge
    //freopen(".txt","r",stdin);
  #endif
    sn("%d",&t);tp=1;
    memset(vis,0,sizeof(vis));
    while(t--)
    {
        sn("%d %d",&n,&m);
        for(i=j=0;i<n;i++)
        {
            sn("%s",&st[i]);
        }
        s=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
              if(st[i][j]=='0')
              {
                  adj[i].pb(n+j);
                  ad[j].pb(i);
              }
              else s=1;
            }
         }
            memset(A,-1,sizeof(A));
            int ans=0;
            for(i=0;i<n;i++)
            {
                for(k=0;k<m;k++)
                {
                   if(st[i][k]=='1')
                    {
                        for(j=0;j<adj[i].size();j++)
                            A[adj[i][j]]=0;
                        for(j=0;j<ad[k].size();j++)
                            A[ad[k][j]]=0;
                        memset(B,-1,sizeof(B));h=0;
                        for(j=0;j<n;j++)
                        {
                            ++tp;
                            if(kuhn(j))
                            {
                                h++;
                            }
                            ++tp;
                        }
                        ans=max(ans,(int)(n+m-adj[i].size()-ad[k].size()-h));

                        for(j=0;j<adj[i].size();j++)
                            A[adj[i][j]]=-1;
                        for(j=0;j<ad[k].size();j++)
                            A[ad[k][j]]=-1;
                    }

                }
            }
            pf("Case %d: %d\n",cs++,ans*s);
            for(i=0;i<103;i++)
                adj[i].clear(),ad[i].clear();
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/



