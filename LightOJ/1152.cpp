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

int lv[maxn];

int A[maxn],B[maxn],vis[maxn];
vector<int>adj[maxn];
int R[]={0,1,0,-1},C[]={1,0,-1,0};
bool kuhn(int u)
{
    int i,j=adj[u].size(),v;
    for(i=0;i<j;i++)
    {
        v=adj[u][i];
        if(vis[v]==0)
        {
            vis[v]=1;
           if(B[v]==-1||kuhn(B[v]))
            {
                B[v]=u;
                A[u]=v;
                return true;
            }

        }
    }
    return false;
}
char st[44][44];

int viss[44][44];
vector<int>ed;
void dfs(int x,int y,int h,int n,int m)
{
     viss[x][y]=1;
     if(h==0)
        ed.pb(m*x+y);
     int xx,yy;
     for(int i=0;i<4;i++)
     {
         xx=x+R[i];
         yy=y+C[i];
         if(xx>=0&&yy>=0&&xx<n&&yy<m&&viss[xx][yy]==0&&st[xx][yy]=='*')
         {
             adj[m*x+y].pb(m*xx+yy);
             dfs(xx,yy,(h+1)%2,n,m);
         }
        else if(xx>=0&&yy>=0&&xx<n&&yy<m&&viss[xx][yy]==1&&st[xx][yy]=='*')
         {
             adj[m*x+y].pb(m*xx+yy);
         }
     }
}
int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;

    //freopen("out.txt","w",stdout);

    sn("%d",&t);
    while(t--)
    {
        memset(A,-1,sizeof(A));
        memset(B,-1,sizeof(B));
        sn("%d",&n); sn("%d",&m);
        for(i=0;i<n;i++)
        {
            sn("%s",&st[i]);
        }
        f=0;
        memset(viss,0,sizeof(viss));
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(st[i][j]=='*')f++;
                if(st[i][j]=='*'&&viss[i][j]==0)
                {
                    dfs(i,j,0,n,m);
                }
            }
        }
        int max_match=0;
        for(i=0;i<ed.size();i++)//m=A ar total node
        {
            memset(vis,0,sizeof(vis));
            if(kuhn(ed[i]))
            {
                max_match++;
            }
        }
        pf("Case %d: %d\n",cs++,f-max_match);
        for(i=0;i<500;i++)
            adj[i].clear();
            ed.clear();
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/




