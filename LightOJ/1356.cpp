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

const int MAXN=50005;
const int MAXE=500005;
const int INF=(1<<29);

    int vis[MAXE]={0},fac[MAXE]={0},ar[MAXN];
    vector<int>pr;
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

void prim()
{
    int i,j,k=0;
    vis[0]=vis[1]=1;
    for(i=2;i<MAXE-1;i++)
    {
        if(vis[i]==0)
        {
            pr.pb(i);fac[i]=1;
            for(j=i+i;j<MAXE-1;j+=i)
            {
                vis[j]=1;
                fac[j]=fac[j/i]+1;
            }
        }
    }
   // pf("%d\n",pr.size());
}
int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;

    //freopen(".txt","r",stdin);
    prim();
    sn("%d",&t);
    while(t--)
    {
        sn("%d",&n);
        memset(vis,-1,sizeof(vis));
        int mm=0;
        for(i=0;i<n;i++)
        {
            sn("%d",&ar[i]);
            vis[ar[i]]=i;
            mm=max(mm,ar[i]);
        }
        init(n);
         for(i=0;i<n;i++)
         {
            for(j=0;j<pr.size();j++)
            {
                u=ar[i]*pr[j];
                if(u>mm)
                    break;
                if(vis[u]>-1)
                {
                    if(fac[ar[i]]&1)
                    add_edge(i+1,vis[u]+1);
                    else
                    add_edge(vis[u]+1,i+1);
                }
            }
        }
        pf("Case %d: %d\n",cs++,n-run());
    }
    return 0;
}

/*
1
6
6 9 4 2 3 12
*/


