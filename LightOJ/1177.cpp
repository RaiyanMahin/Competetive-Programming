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
map<string,int>sh;
int cst[105][105],vis[105],par[105];
char ss[34],st[54];
int bfs(int s,int d)
{
    queue<int>Q;
    int i,j,u,v,mm;
    Q.push(s);
    memset(vis,0,sizeof(vis));
    memset(par,-1,sizeof(par));
    vis[s]=1;par[s]=-1;
    while(!Q.empty())
    {
        u=Q.front();
        Q.pop();
        for(i=0;i<=100;i++)
        {
            v=i;
            if(vis[v]==0&&cst[u][v]>0)
            {
                 vis[v]=1;
                 par[v]=u;
                 Q.push(v);
            }
        }
    }
    if(vis[d]==0)return 0;

    v=d;mm=1000000000;
    while(par[v]>-1)
    {
        mm=min(mm,cst[par[v]][v]);
        v=par[v];
    }
    v=d;
    while(par[v]>-1)
    {
       cst[par[v]][v]-=mm;
       cst[v][par[v]]+=mm;
        v=par[v];
    }
    return mm;
}

int max_flow(int s,int d)
{
   int mx=0,m;
    while(1)
    {
        m=bfs(s,d);
        if(m==0)break;
        mx=mx+m;
    }
    return mx;
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
         memset(cst,0,sizeof(cst));
         for(i=2;i<=n-1;i++)
         {
             sn("%d",&u);
             cst[i][i+50]=u;
             cst[i+50][i]=u;
         }
         for(i=0;i<m;i++)
         {
             sn("%d %d %d",&u,&v,&c);
             cst[u+50][v]=cst[v+50][u]=c;
         }
         h=max_flow(1+50,n);
            pf("Case %d: %d\n",cs++,h);
     }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/


