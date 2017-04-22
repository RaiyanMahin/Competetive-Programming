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
const int MAXE=500001;
const int INF=(1<<29);

int vis[205][205],viss[205][205],R[]={-2,-2,-1,-1,1,1,2,2},C[]={-1,1,-2,2,-2,2,-1,1};

//struct hopcroftKarp{

    int ptr[MAXN],next[MAXE],zu[MAXE];
    int n,m,match[MAXN],D[MAXN],q[MAXN];
    void init(int _n){
        n=_n;
        m=0;
        memset(ptr,~0,sizeof(int)*(n+1));
    }
    void add_edge(int u,int v){
        next[m]=ptr[u];ptr[u]=m;zu[m]=v;++m;
    }
    bool bfs(){
        int u,v;
        register int i;
        int qh=0, qt=0;
        for(i=1; i<=n; i++){
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
            for(i=1; i<=n; i++)
                {
                   if(!match[i] && dfs(i))
                    matching++;
                }
        return matching;
    }
//};

int main()
{
    int i,j,k,l,t,cs=1,r=1,s,mm,nn,a,b,c,d,e,f,g,h,u,v;

     sn("%d",&t);
     while(t--)
     {
        sn("%d %d %d",&nn,&mm,&k);
        memset(vis,0,sizeof(vis));
        f=nn*mm;
        for(i=0;i<k;i++)
        {
            sn("%d %d",&u,&v);
            f--;
            vis[u][v]=1;
        }
        init(nn*mm);
        for(i=1;i<=nn;i++)
        {
            for(j=1;j<=mm;j++)
            {
                if(vis[i][j]==0)
                {

                    for(h=0;h<8;h++)
                    {
                        int x=i+R[h];
                        int y=j+C[h];
                        if(x>0&&y>0&&x<=nn&&y<=mm&&vis[x][y]==0)
                        {
                            //if(viss[i][j]==0)
                             add_edge((i-1)*mm+j,(x-1)*mm+y);
                        }
                    }
                }
            }
        }
        pf("Case %d: %d\n",cs++,f-run());
     }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/


