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
int a,b;

   bool operator<(const T &bb)const
   {
       return b>bb.b;
   }

}temp,tt;

int cost[205][205],dg[205][205],par[205],vis[205],inf=100000000,cx;
vector<int>Ed[206],ans;

int bfs(int s,int d,int hd)
{
    int i,j,k,u,v,mm,x=0;
    queue<int>Q;
    memset(vis,0,sizeof(vis));
    Q.push(s);vis[s]=1;
    par[s]=-1;
    while(!Q.empty())
    {

        u=Q.front();Q.pop();
        //u=tt.a;
        for(i=0,j=Ed[u].size();i<j;i++)
        {
            v=Ed[u][i];
            if(vis[v]==0&&cost[u][v]>0&&dg[u][v]<=hd)
            {
                vis[v]=1;par[v]=u;
                Q.push(v);
            }
        }
    }
    if(vis[d]==0)
        return 0;
     v=d;mm=1000000000;
    while(par[v]>-1)
    {
        mm=min(mm,cost[par[v]][v]);
        v=par[v];
    }
    v=d;
    int uu=0;
    while(par[v]>-1)
    {
       cost[par[v]][v]-=mm;
       cost[v][par[v]]+=mm;
        v=par[v];
    }
    return mm;

}
int max_flow(int s,int d,int hd,int nd)
{
    int mx=0,mm=0;
    while(1)
    {
        mm=bfs(s,d,hd);
        if(mm==0)
            break;
        //ans.pb(mm);
        mx++;
        if(mx>=nd)
            break;
    }
    return mx;
}
int cst[205][205];

void clsr()
{
    int i,j;
    for(i=0;i<205;i++)
                 {
                    for(j=0;j<205;j++)
                        cost[i][j]=cst[i][j];
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
         sn("%d",&n);
         memset(cst,0,sizeof(cst));
         memset(dg,0,sizeof(dg));
         memset(vis,0,sizeof(vis));
         sn("%d",&m);
         for(i=0;i<=n+1;i++)
         {
             if(i==0||i==n+1)
             {
                 Ed[i].pb(i+102);
                 Ed[i+102].pb(i);
                 cst[i][i+102]=inf;
                 cst[i+102][i]=inf;
                dg[i][i+102]=0;
                 dg[i+102][i]=0;
             }
             else
             {
                 Ed[i].pb(i+102);
                 Ed[i+102].pb(i);
                 cst[i][i+102]=1;
                 cst[i+102][i]=0;
                  dg[i][i+102]=0;
                 dg[i+102][i]=0;
             }
         }
         set<int>ckk;
         for(i=0;i<m;i++)
         {
             sn("%d %d %d",&u,&v,&c);
             if(ckk.count(c)==0)
             {
                 ckk.insert(c);
                 ans.pb(c);
             }
             if(u>v)swap(u,v);
             Ed[u+102].pb(v);
             Ed[v].pb(u+102);
             cst[u+102][v]=1;
             cst[v][u+102]=0;
             dg[u+102][v]=c;
             dg[v][u+102]=c;
         }
         cx=-1;
         sn("%d",&k);
         sort(ans.begin(),ans.end());
         int lw=0,hi=ans.size()-1,mid;
         pf("Case %d: ",cs++);
         while(lw<=hi)
         {
             clsr();
             mid=(lw+hi)/2;
             if(max_flow(0,n+1,ans[mid],k)>=k)
             {
                 cx=ans[mid];
                 clsr();
                 if(mid>0&&max_flow(0,n+1,ans[mid-1],k)>=k)
                 {
                     cx=ans[mid-1];
                     hi=mid-1;
                 }
                 else
                    break;
             }
             else
                lw=mid+1;
         }
         if(cx>0)
         {
             pf("%d\n",cx);
         }
         else
            pf("no solution\n");
         ans.clear();
         for(i=0;i<205;i++)
            Ed[i].clear();
     }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/

