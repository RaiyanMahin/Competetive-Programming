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
int x,y,n,c;
}ar[105];

int ct[205][205],cst[205][205];

map<string,int>sh;
int vis[305],par[305],vv,arr[205];
vector<int>Ed[205];
int bfs(int s,int d)
{
    queue<int>Q;
    int i,j,u,v,mm,p,h=0;
    Q.push(s);
    vis[s]=vv;par[s]=-1;
    while(!Q.empty())
    {
        if(h>0)break;
        u=Q.front();
        Q.pop();
        for(i=0,j=Ed[u].size();i<j;i++)
        {
            v=Ed[u][i];
            if(vis[v]!=vv&&cst[u][v]>0)
            {
                 vis[v]=vv;
                 par[v]=u;
                 Q.push(v);
            }
        }

    }
    if(vis[d]!=vv)return 0;

    v=d;mm=1000000;
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
    v=0;
    return mm;
}

int max_flow(int s,int d)
{
   int mx=0,m;
    while(1)
    {
        m=bfs(s,d);
        if(m==0)break;
        mx=mx+m;vv++;
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
     double dd,esp=1e-8;
     while(t--)
     {
         sn("%d %lf",&n,&dd);vv=1;
         memset(vis,0,sizeof(vis));
         memset(arr,0,sizeof(arr));
         memset(ct,0,sizeof(ct));
         s=0;
         for(i=1;i<=n;i++)
         {
             sn("%d %d %d %d",&ar[i].x,&ar[i].y,&ar[i].n,&ar[i].c);
             ct[i][i+100]=ar[i].c;
             Ed[i].pb(i+100);
             arr[i]=ar[i].n;
             s=s+ar[i].n;
         }
         dd=dd*dd;
         for(i=1;i<=n;i++)
         {
             ct[0][i]=ar[i].n;
             Ed[0].pb(i);
             for(j=i+1;j<=n;j++)
             {
                 int dx=abs(ar[i].x-ar[j].x);
                 int dy=abs(ar[i].y-ar[j].y),ds;
                 ds=dx*dx+dy*dy;
                 if(dd-(double)ds>esp)
                 {
                     Ed[i+100].pb(j);
                     Ed[j+100].pb(i);
                     Ed[j].pb(i+100);
                     Ed[i].pb(j+100);
                     ct[i+100][j]=ct[j+100][i]=1000000000;
                 }
             }
         }
         vector<int>ans;
         for(i=1;i<=n;i++)
         {
              for(j=0;j<=201;j++)
              {
                  if(j>0&&j<=n)
                  arr[j]=ar[j].n;
                  for(k=0;k<=201;k++)
                  {
                      cst[j][k]=ct[j][k];
                  }
              }
              cst[0][i]=0;
              h=max_flow(0,i);
              if(h>=s-ar[i].n)
                ans.pb(i-1);
              vv++;
         }
            pf("Case %d:",cs++);
            if(ans.size()==0)
                pf(" -1\n");
            else
            {
                for(i=0;i<ans.size();i++)
                    pf(" %d",ans[i]);
                     pf("\n");
            }
           for(i=0;i<202;i++)Ed[i].clear();
     }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/



