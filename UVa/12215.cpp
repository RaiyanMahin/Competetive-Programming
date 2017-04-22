//BISMILLAHIR RAHMANIR RAHIM
//LIGHTOJ 1262
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
const int MAXN = 5000;
const int INF = 1000000000;
int ans[50][50];
vector<int>cnt[50][50];
const int maxn=35;
int AA[maxn],BB[maxn],vis[maxn];
bool kuhn(int u,int n)
{
    int i,j=n,v;
    for(i=0;i<j;i++)
    {
        v=i;
        if(vis[v]==0&&ans[u][v]>0)
        {
            vis[v]=1;
            if(BB[v]==-1||kuhn(BB[v],n))
            {
                BB[v]=u;
                AA[u]=v;
                return true;
            }
        }
    }
    return false;
}
struct dinic_maxflow{


struct edge {
	int a, b, cap, flow;
	edge(int _a,int _b,int _cap,int _flow)
	{
	    a=_a,b=_b,cap=_cap,flow=_flow;
	}
};

int n, s, t, d[MAXN], ptr[MAXN], q[MAXN];
vector<edge> e;
vector<int> g[MAXN];

void add_edge (int a, int b, int cap,int r,int c) {

	edge e1 = edge( a, b, cap, 0 );
	edge e2 = edge( b, a, 0, 0 );
	if(r!=-1)
    {
       cnt[r][c].pb(e.size());
    }
	g[a].push_back ((int) e.size());
	e.push_back (e1);
	g[b].push_back ((int) e.size());
	e.push_back (e2);
}

bool bfs() {
	int qh=0, qt=0;
	q[qt++] = s;
	memset (d, -1, n * sizeof d[0]);
	d[s] = 0;
	while (qh < qt && d[t] == -1) {
		int v = q[qh++];
		for (size_t i=0; i<g[v].size(); ++i) {
			int id = g[v][i],
				to = e[id].b;
			if (d[to] == -1 && e[id].flow < e[id].cap) {
				q[qt++] = to;
				d[to] = d[v] + 1;
			}
		}
	}
	return d[t] != -1;
}

int dfs (int v, int flow) {
	if (!flow)  return 0;
	if (v == t)  return flow;
	for (; ptr[v]<(int)g[v].size(); ++ptr[v]) {
		int id = g[v][ptr[v]],
			to = e[id].b;
		if (d[to] != d[v] + 1)  continue;
		int pushed = dfs (to, min (flow, e[id].cap - e[id].flow));
		if (pushed) {
			e[id].flow += pushed;
			e[id^1].flow -= pushed;
			return pushed;
		}
	}
	return 0;
}

int dinic( ) {
	int flow = 0;
	for (;;) {
		if (!bfs())  break;
		memset (ptr, 0, n * sizeof ptr[0]);
		while (int pushed = dfs (s, INF))
			flow += pushed;
	}

	return flow;
}
    dinic_maxflow( int _n, int _s, int _t ){
        n = _n; s = _s; t = _t;
    }
};
int A[50],B[50],C[50][50];
int make_net(int n,int u)
{

    int i,j;
    for(i=0;i<50;i++)
         {
             for(j=0;j<50;j++)
             {
                 cnt[i][j].clear();
             }
         }
    dinic_maxflow dm=dinic_maxflow(4*n+5,4*n+1,4*n+2);
    for(i=0;i<n;i++)
    {
        dm.add_edge(i,2*n+i,B[i],-1,-1);
        dm.add_edge(3*n+i,n+i,A[i],-1,-1);
        dm.add_edge(4*n+1,i,u,-1,-1);
        dm.add_edge(n+i,4*n+2,u,-1,-1);
        for(j=0;j<n;j++)
        {
            dm.add_edge(i,n+j,C[j][i],i,j);
            dm.add_edge(2*n+i,3*n+j,1000000,i,j);
        }

    }
    if(n*u==dm.dinic())
      {
            memset(ans,0,sizeof(ans));
            for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                {
                    for(int k=0;k<cnt[i][j].size();k++)
                    {
                        ans[i][j]+=dm.e[cnt[i][j][k]].flow;
                    }
                }
            }
            return 1;
      }
    return 0;
}
int rc[505][505];
int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;

   // freopen("out.txt","w",stdout);
 // #endif
     sn("%d",&t);
     while(t--)
     {
         sn("%d",&n);
         for(i=0;i<n;i++)
         {
             sn("%d",&A[i]);
         }
         for(i=0;i<n;i++)
         {
             sn("%d",&B[i]);
         }
         for(i=0;i<n;i++)
         {
             for(j=0;j<n;j++)
             {
                 sn("%d",&C[i][j]);
             }
         }
         int lw=0,hi=500,mid;
         while(lw<=hi)
         {
             mid=(lw+hi)/2;
             if(make_net(n,mid)==1)
             {
                 if(make_net(n,mid+1)==1)
                    lw=mid+1;
                 else break;
             }
             else
                hi=mid-1;
         }
         pf("Case %d: %d\n",cs++,mid);
         make_net(n,mid);
         if(mid>500)
         {
             while(1)
             {
                 ;
             }
         }
         memset(rc,-1,sizeof(rc));
         for(i=0;i<mid;i++)
         {
             memset(AA,-1,sizeof(AA));
             memset(BB,-1,sizeof(BB));
             for(j=0;j<n;j++)
             {
                 memset(vis,0,sizeof(vis));
                kuhn(j,n);
             }
             for(j=0;j<n;j++)
             {
                 rc[i][AA[j]]=j;
                 ans[j][AA[j]]--;
             }
         }
         for(i=0;i<mid;i++)
         {
             for(j=0;j<n;j++)
             {
                 if(j!=0)pf(" ");
                 pf("%d",rc[i][j]);
             }
             pf("\n");
         }
     }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/


