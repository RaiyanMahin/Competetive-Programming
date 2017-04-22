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
int cst[80][80],vis[80],par[80];
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
        for(i=0;i<=75;i++)
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
     sh["XXL"]=1; sh["XL"]=2; sh["L"]=3; sh["M"]=4; sh["S"]=5; sh["XS"]=6;
     while(t--)
     {
         sn("%d %d",&n,&m);
         memset(cst,0,sizeof(cst));
         for(i=1;i<=6;i++)
         {
             cst[i][i+65]=n;
             cst[i+65][75]=1000000000;
         }
         for(i=0;i<m;i++)
         {
             sn("%s%s",&ss,&st);
             cst[10+i][sh[ss]]=1;
             cst[10+i][sh[st]]=1;
             cst[0][10+i]=1;
         }
         u=max_flow(0,75);
         if(u==m)
            pf("Case %d: YES\n",cs++);
          else
            pf("Case %d: NO\n",cs++);
     }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/

