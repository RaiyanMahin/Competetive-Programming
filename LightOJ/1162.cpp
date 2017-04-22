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
vector<int>Ed[100005],cst[100005];
int par[100005][25],Lv[100005],minx[100005][25],maxx[100005][25],anx,any;
void  dfs(int u,int pr,int lv,int cc)
{

    Lv[u]=lv;
    par[u][0]=pr;
    minx[u][0]=cc;
    maxx[u][0]=cc;
    int i,j=Ed[u].size(),v;
    for(i=0;i<j;i++)
    {
        v=Ed[u][i];
        if(Lv[v]==-1)
        {
           dfs(v,u,lv+1,cst[u][i]);
        }
    }

}
void sparse_table(int n)
{
    int i,j,k,l;
    for(j=1;j<25;j++)
    {
        for(i=0;i<n;i++)
        {
            if(par[i][j-1]!=-1)
            {
                par[i][j]=par[par[i][j-1]][j-1];
                minx[i][j]=min(minx[i][j-1],minx[par[i][j-1]][j-1]);
                maxx[i][j]=max(maxx[i][j-1],maxx[par[i][j-1]][j-1]);
            }
        }
    }
}
int find_lca(int u,int v)
{
    int i,j,k,l,m,n;
    if(Lv[v]>Lv[u])
        swap(u,v);
    anx=1000000;any=0;
    for(j=24;j>=0;j--)
    {
        if(Lv[u]-(1<<j)>=Lv[v])
        {
            anx=min(anx,minx[u][j]);
            any=max(any,maxx[u][j]);
            u=par[u][j];
        }
    }
    if(u==v)
        return u;
    for(i=24;i>=0;i--)
    {
        if(par[u][i]!=-1&&par[u][i]!=par[v][i])
        {
            anx=min(anx,minx[u][i]);
            any=max(any,maxx[u][i]);
            anx=min(anx,minx[v][i]);
            any=max(any,maxx[v][i]);
            u=par[u][i];v=par[v][i];
        }
    }
    anx=min(anx,minx[u][0]);
    any=max(any,maxx[u][0]);
    anx=min(anx,minx[v][0]);
    any=max(any,maxx[v][0]);
    return par[u][0];
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
        sn("%d",&n);m=n-1;
        for(i=0;i<m;i++)
        {
            sn("%d %d %d",&u,&v,&c);
            u--;v--;
            Ed[u].pb(v);
            Ed[v].pb(u);
            cst[u].pb(c);
            cst[v].pb(c);
        }
        memset(par,-1,sizeof(par));
        memset(Lv,-1,sizeof(Lv));
        dfs(0,-1,0,0);
        sparse_table(n);
        int qry;
        sn("%d",&qry);
        pf("Case %d:\n",cs++);
        while(qry--)
        {
            sn("%d %d",&u,&v);
            u--;v--;
            h=find_lca(u,v);
            if(u==v)
                anx=any=0;
            pf("%d %d\n",anx,any);
        }
        for(i=0;i<=n;i++)
            Ed[i].clear(),cst[i].clear();
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/


