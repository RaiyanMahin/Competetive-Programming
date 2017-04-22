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
const int maxn=30005;
int A[maxn],B[maxn],vis[maxn];
vector<int>adj[maxn],Ed[maxn];
int tp;
const int MAXN=20005;
const int MAXE=100001;
const int INF=(1<<29);
    int ptr[MAXN],next[MAXE],zu[MAXE];
    int node,edge,match[MAXN],D[MAXN],q[MAXN];
    void init(int _n){
        node=_n;
        edge=0;
        memset(ptr,~0,sizeof(int)*(node+1));
    }
    void add_edge(int u,int v){
        next[edge]=ptr[u];ptr[u]=edge;zu[edge]=v;++edge;
    }
    bool bfs(){
        int u,v;
        register int i;
        int qh=0, qt=0;
        for(i=1; i<=node; i++){
            if(!match[i]){
                D[i]=0;
                q[qt++]=i;
            }
            else D[i]=INF;
        }
        D[0]=INF;
        while(qh<qt){
            u=q[qh++];
            if(u!=0){
                for(i=ptr[u]; ~i; i=next[i]){
                    v=zu[i];
                    if(D[match[v]]==INF){
                        D[match[v]]=D[u]+1;
                        q[qt++]=match[v];
                    }
                }
            }
        }
        return D[0]!=INF;
    }
    bool dfs(int u){
        int v;
        register int i;
        if(u){
            for(i=ptr[u]; ~i; i=next[i]){
                v=zu[i];
                if(D[match[v]]==D[u]+1){
                    if(dfs(match[v])){
                        match[v]=u;
                        match[u]=v;
                        return true;
                    }
                }
            }
            D[u]=INF;
            return false;
        }
        return true;
    }
    int run(){
        int matching=0;
        memset(match,0,sizeof(match));
        register int i;
        while(bfs())
            for(i=1; i<=node; i++)
                {
                   if(!match[i] && dfs(i))
                    matching++;
                }
        return matching;
    }

void gen()
{
    int i,j,k,l;
    for(i=1;i<=10000;i++)
    {
        for(j=0;j<20;j++)
        {
            if(i&(1<<j)&&i+(1<<j)<=10000)
            {
                Ed[i].pb(i+(1<<j));
                //A[i+(1<<j)]++;
            }
        }
    }
}
vector<int>ar;
void dfs(int u,int l,int lv)
{
    vis[u]=tp;
    ar.pb(u);
    int i,j=Ed[u].size(),v;
    for(i=0;i<j;i++)
    {
        v=Ed[u][i];
        if(v<=l)
        {
            adj[u].pb(v+l+1);
            if(vis[v]!=tp)
            {
                dfs(v,l,lv+1);
            }
        }
    }
}
bool cmp(int x,int y)
{
    if(A[x]<A[y])
        return true;
    return false;
}
int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;
     //  freopen("out.txt","r",stdin);
      gen();
      sn("%d",&t);
      memset(vis,0,sizeof(vis));
      tp=1;
      while(t--)
      {
          sn("%d %d",&n,&m);
          tp++;l=m;
         memset(A,-1,sizeof(A));
         for(i=0;i<n;i++)
         {
             sn("%d",&u);
             dfs(u,m,1);
         }
         tp++;
        int max_match=0;
        init(m);
        for(i=0;i<ar.size();i++)//m=A ar total node
        {
            for(j=0;j<adj[ar[i]].size();j++)
            {
                add_edge(ar[i],adj[ar[i]][j]);
            }
        }
        pf("Case %d: %d\n",cs++,ar.size()-run());
        for(i=0;i<ar.size();i++)
            adj[ar[i]].clear();
            ar.clear();
         tp++;
      }
     return 0;
}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/

