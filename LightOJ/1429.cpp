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
const int maxn=1005;
int A[maxn],B[maxn],vis[maxn];
vector<int>adj[maxn],Ed[maxn];

bool kuhn(int u,int p)
{
    if(vis[u]==1)
        return false;
    int i,j=adj[u].size(),v;
     vis[u]=1;
    for(i=0;i<j;i++)
    {
            v=adj[u][i];
            if(B[v]==-1||kuhn(B[v],B[v]))
            {
                B[v]=p;
                A[p]=v;
                return true;
            }
            if(kuhn(v,p))
                return true;
    }
    return false;
}
int viss[maxn];
vector<int>bk,Edd[maxn];
void dfs(int u)
{
    viss[u]=1;
    int i,j=Ed[u].size(),v;
    for(i=0;i<j;i++)
    {
        v=Ed[u][i];
        if(viss[v]==0)
        {
            dfs(v);
        }
    }
    bk.pb(u);
}
void dfs2(int u,int h)
{
      viss[u]=h;
    for(int i=0;i<Edd[u].size();i++)
    {
        int v=Edd[u][i];
        if(viss[v]==0)
        {
            dfs2(v,h);
        }
    }
}
int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;
  #ifdef O_judge
    //freopen(".txt","r",stdin);
  #endif
    sn("%d",&t);
    while(t--)
    {
        sn("%d %d",&n,&m);
        for(i=0;i<m;i++)
        {
            sn("%d %d",&u,&v);
            Ed[u].pb(v);
            Edd[v].pb(u);
        }
        memset(viss,0,sizeof(viss));
        for(i=1;i<=n;i++)
        {
            if(viss[i]==0)
                dfs(i);
        }

        memset(viss,0,sizeof(viss));
        for(i=bk.size()-1,j=1;i>=0;i--)
        {
            if(viss[bk[i]]==0)
                dfs2(bk[i],j),j++;
        }
       // pf("%d\n",j);
        h=j;
        for(i=1;i<=n;i++)
        {
            for(j=0;j<Ed[i].size();j++)
            {
                v=Ed[i][j];
                if(viss[i]!=viss[v])
                {
                    adj[viss[i]].pb(viss[v]);
                   // pf("%d %d\n",viss[i],viss[v]);
                }
            }
        }
        memset(A,-1,sizeof(A));
        memset(B,-1,sizeof(B));
        int max_match=0;
        for(i=1;i<h;i++)//m=A ar total node
        {
            memset(vis,0,sizeof(vis));
            if(kuhn(i,i))
                max_match=0;
        }
        for(i=1;i<h;i++)
        {
            if(B[i]==-1)
                max_match++;
        }
        pf("Case %d: %d\n",cs++,max_match);
        for(i=0;i<=n;i++)
            adj[i].clear(),Ed[i].clear(),Edd[i].clear();
            bk.clear();
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/
