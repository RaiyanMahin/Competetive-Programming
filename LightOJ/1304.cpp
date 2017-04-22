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
const int MAXN = 20005;
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
	 //pf("%d %d\n",v,g[v].size());
	for (; ptr[v]<(int)g[v].size(); ++ptr[v]) {
		int id = g[v][ptr[v]],
			to = e[id].b;
		if (d[to] != d[v] + 1)  continue;
		int pushed = dfs (to, min (flow, e[id].cap - e[id].flow));
		if (pushed) {
			e[id].flow += pushed;
			e[id^1].flow -= pushed;
           // pf("%d %d %d\n",v,to,id);
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
int ar[10005][2],rc[20005],rr[20005];
char st[105][105],R[]={0,1},C[]={1,0};
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
         for(i=0;i<n;i++)
         {
             sn("%s",&st[i]);
         }
         memset(ar,-1,sizeof(ar));
         memset(rc,-1,sizeof(rc));
         h=1;
         for(i=0;i<n;i++)
         {
             for(j=0;j<m;j++)
             {
                 if(st[i][j]=='W')
                    continue;
                 u=i*m+j;
                 if(ar[u][0]==-1)
                 {
                     rc[h]=0;
                     ar[u][0]=h;h++;
                 }
                 if(ar[u][1]==-1)
                 {
                     rc[h]=1;
                     ar[u][1]=h;h++;
                 }
                 for(k=0;k<2;k++)
                 {
                     int xx=i+R[k];
                     int yy=j+C[k];
                     v=xx*m+yy;
                     if(xx>=0&&yy>=0&&xx<n&&yy<m&&st[xx][yy]!='W')
                     {
                         if(k==0)
                         ar[v][0]=ar[u][0];
                         else
                         ar[v][1]=ar[u][1];
                     }
                 }
             }
         }
         s=0;d=h+1;
         dinic_maxflow dm=dinic_maxflow(d+3,s,d);
         for(i=1;i<h;i++)
         {
             if(rc[i]==0)
             {
                 dm.add_edge(s,i,1);
             }
             else
             {
                 dm.add_edge(i,d,1);
             }
         }
         for(i=0;i<n;i++)
         {
             for(j=0;j<m;j++)
             {
                 if(st[i][j]!='.')
                    continue;
                 u=i*m+j;
                 dm.add_edge(ar[u][0],ar[u][1],1);
                 rr[u]=dm.g[ar[u][0]][dm.g[ar[u][0]].size()-1];
                // pf("%d %d %d\n",ar[u][0],ar[u][1],rr[u]);
             }
         }
         pf("Case %d: %d\n",cs++,dm.dinic());
         for(i=0;i<n;i++)
         {
             for(j=0;j<m;j++)
             {
                 u=i*m+j;
                 if(st[i][j]=='.')
                 {
                      if(dm.e[rr[u]].flow>0)
                       pf("T");
                      else
                        pf("%c",st[i][j]);
                 }
                 else
                 pf("%c",st[i][j]);
             }
             pf("\n");
         }
     }
    return 0;

}

/*

	Author       :	Jan
	Problem Name :
	Algorithm    :
	Complexity   :

#include <set>
#include <map>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

const int MM = 105;

int cases, caseno, m, n, v[MM][MM], h[MM][MM],
	M, N, L[MM*MM], R[MM*MM], vis[MM*MM], xv[MM*MM], yh[MM*MM];
char grid[MM][MM];

vector <int> adj[MM*MM];

void takeGrid() {
	for( int i = 1; i <= m; i++ ) scanf("%s", grid[i] + 1);
	for( int i = 0; i <= m + 1; i++ ) grid[i][0] = grid[i][n + 1] = 'W', grid[0][n + 2] = 0;
	for( int i = 0; i <= n + 1; i++ ) grid[0][i] = grid[m+1][i] = 'W';
	m += 2, n += 2;

	memset( v, -1, sizeof(v) );
	memset( h, -1, sizeof(h) );
}

void buildGraph() {
	M = 0, N = 0;
	for( int i = 0; i < m; i++ ) for( int j = 0, k; j < n; j++ ) if( grid[i][j] == '.' ) {
		adj[M].clear();
		xv[M] = i;
		for( k = j; grid[i][k] != 'W'; k++ ) h[i][k] = M;
		j = k;
		M++;
	}
	for( int i = 0; i < n; i++ ) for( int j = 0, k; j < m; j++ ) if( grid[j][i] == '.' ) {
		yh[N] = i;
		for( k = j; grid[k][i] != 'W'; k++ ) v[k][i] = N;
		j = k;
		N++;
	}
	for( int i = 0; i < m; i++ ) for( int j = 0; j < n; j++ ) if( grid[i][j] == '.' ) adj[ h[i][j] ].push_back( v[i][j] );
}

bool bpm( int u, int step ) {
	for( int i = 0; i < adj[u].size(); i++ ) {
		int v = adj[u][i];
		if( vis[v] == step ) continue;
		vis[v] = step;

		if( R[v] == -1 || bpm( R[v], step ) ) {
			L[u] = v, R[v] = u;
			return true;
		}
	}
	return false;
}

int main() {
	freopen("site.in", "r", stdin);
	freopen("site.ans", "w", stdout);

	double cl = clock();

	scanf("%d", &cases);
	while( cases-- ) {
		scanf("%d %d", &m, &n);
		takeGrid();

		buildGraph();

		int res = 0;
		memset( vis, -1, sizeof(vis) );
		memset( R, -1, sizeof(R) );
		memset( L, -1, sizeof(L) );
		for( int i = 0; i < M; i++ ) if( bpm(i, i) ) res++;
		printf("Case %d: %d\n", ++caseno, res);

		for( int i  = 0; i < M; i++ ) if( L[i] != -1 ) grid[ xv[i] ][ yh[ L[i] ] ] = 'T';
		for( int i = 1; i < m - 1; i++ ) {
			grid[i][n - 1] = 0;
			puts(grid[i] + 1);
		}
	}

	cl = clock() - cl;
	fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

	return 0;
}
*/


