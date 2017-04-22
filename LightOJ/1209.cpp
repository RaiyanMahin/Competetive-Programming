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
const int maxn=505;
int A[maxn],B[maxn],vis[maxn];
vector<int>adj[maxn];

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
char st[10],ss[10];
vector<int>M[105],F[105],MM[104],FF[105];
int viss[505][505];
int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;
  #ifdef O_judge
    //freopen(".txt","r",stdin);
  #endif
    sn("%d",&t);
    while(t--)
    {
        sn("%d %d %d",&n,&m,&g);
        for(i=0;i<g;i++)
        {
            sn("%s %s",&st,&ss);
            l=strlen(st);u=0;
            for(j=1;j<l;j++)
            {
                u=u*10+st[j]-'0';
            }
            if(st[0]=='F')
                F[u].pb(i);
            if(st[0]=='M')
                M[u].pb(i);
            l=strlen(ss);u=0;
            for(j=1;j<l;j++)
            {
                u=u*10+ss[j]-'0';
            }
            if(ss[0]=='F')
                FF[u].pb(i);
            if(ss[0]=='M')
                MM[u].pb(i);
        }
        memset(viss,0,sizeof(viss));
        for(i=1;i<=n;i++)
        {
            for(j=0;j<M[i].size();j++)
            {
                u=M[i][j];
                for(k=0;k<MM[i].size();k++)
                {
                    v=MM[i][k];
                    if(viss[u][v]==0)
                    {
                        viss[u][v]=1;
                        adj[u].pb(v);
                       // pf("%d %d\n",u,v);
                    }
                }
            }
        }
        for(i=1;i<=m;i++)
        {
            for(j=0;j<FF[i].size();j++)
            {
                u=FF[i][j];
                for(k=0;k<F[i].size();k++)
                {
                    v=F[i][k];
                    if(viss[u][v]==0)
                    {
                        viss[u][v]=1;
                        adj[u].pb(v);
                      //  pf("%d %d\n",u,v);
                    }
                }
            }
        }
        memset(A,-1,sizeof(A));
        memset(B,-1,sizeof(B));
        int max_match=0;
        for(i=1;i<=n;i++)//m=A ar total node
        {
          for(j=0;j<M[i].size();j++)
          {
            memset(vis,0,sizeof(vis));
            if(kuhn(M[i][j]))
            {
                max_match++;
            }
          }
        }
        pf("Case %d: %d\n",cs++,g-max_match);
        for(i=0;i<=g;i++)
            adj[i].clear();
        for(i=0;i<=100;i++)
        {
            F[i].clear();
            FF[i].clear();
            MM[i].clear();
            M[i].clear();
        }
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/

