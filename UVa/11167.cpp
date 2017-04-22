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
const int MAXN = 50105;
const int INF = 1000000000;
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

void add_edge (int a, int b, int cap) {
	edge e1 = edge( a, b, cap, 0 );
	edge e2 = edge( b, a, 0, 0 );
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
int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;
  #ifdef O_judge
    //freopen(".txt","r",stdin);
  #endif
    // sn("%d",&t);
     while(1)
     {
         sn("%d",&n);
         if(n==0)break;
         sn("%d",&m);
         dinic_maxflow dm=dinic_maxflow(MAXN,MAXN-2,MAXN-1);
         s=MAXN-2;d=MAXN-1;
         g=0;
         int vis[50005]={0};
         for(i=0;i<n;i++)
         {
             sn("%d %d %d",&c,&u,&v);
             g=g+c;
             dm.add_edge(s,i+1+50000,c);
             for(j=u;j<v;j++)
             {
                 vis[j]=1;
                 dm.add_edge(i+1+50000,j,1);
             }
         }
         for(i=0;i<=50000;i++)
         {
             if(vis[i]==1)
                dm.add_edge(i,d,m);
         }
         h=dm.dinic();
         vector<int>ar[105],ans[105];
         if(h==g)
         {
             pf("Case %d: Yes\n",cs++);
             for(i=0;i<n;i++)
             {
                 u=i+1+50000;
                 for(j=0;j<dm.g[i+1+50000].size();j++)
                 {
                     c=dm.g[u][j];
                     if(dm.e[c].flow>0&&dm.e[c].b<=50000)
                     {
                         ar[i].pb(dm.e[c].b);
                     }
                 }
             }
             for(i=0;i<n;i++)
             {
                 k=-1;
                 sort(ar[i].begin(),ar[i].end());
                 for(j=0;j<ar[i].size();j++)
                 {
                     if(j==0)
                     {
                        ans[i].pb(ar[i][j]);
                        ans[i].pb(ar[i][j]+1);
                        k=k+2;
                     }
                     else
                     {
                         if(ans[i][k]==ar[i][j])
                         {
                             ans[i][k]++;
                         }
                         else
                         {
                             ans[i].pb(ar[i][j]);
                             ans[i].pb(ar[i][j]+1);
                             k=k+2;
                         }
                     }
                 }
             }
             for(i=0;i<n;i++)
             {
                 k=ans[i].size();
                 pf("%d",k/2);
                 for(j=0;j<k;j+=2)
                 {
                     pf(" (%d,%d)",ans[i][j],ans[i][j+1]);
                 }
                 pf("\n");
             }
         }
         else
         {
             pf("Case %d: No\n",cs++);
         }
     }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/


