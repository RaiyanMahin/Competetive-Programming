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
const int MAXN = 5000;
const int INF = 1000000000;
int nn,mm,vis[100][100];

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
	for(int i=0;i<nn;i++)
        {
            for(int j=0;j<mm;j++)
            {
               int  u=i*mm+j+1;
               if(j>0)
                pf(" ");
               for(int kk=0;kk<g[u].size();kk++)
               {
                    int v=g[u][kk];
                    if(e[v].b>=nn*mm+400)
                     {
                         pf("%d",e[v].flow+1);
                         vis[i][j]=e[v].flow;break;
                     }
               }
            }
            pf("\n");
        }
	return flow;
}
    dinic_maxflow( int _n, int _s, int _t ){
        n = _n; s = _s; t = _t;
    }
};
int ar[3][200],R[]={1,1},C[]={-1,1},cost[5000];
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
         dinic_maxflow dm=dinic_maxflow(4000-1,0,n*m+605);
         for(i=0;i<5000;i++)
            cost[i]=99;
         for(i=1;i<=n+m-1;i++)
         {
             sn("%d",&ar[0][i]);
         }
         for(i=1;i<=n+m-1;i++)
         {
             sn("%d",&ar[1][i]);
         }
            for(i=0;i<m;i++)
         {
             for(j=0;j<2;j++)
             {
                 int x=0,y=i;
                 if(j==0)
                 {
                     u=n*m+200+i+1;
                     x=0;y=i;
                 }
                 else
                 {
                     u=n*m+400+m-i;
                 }
                 while(x>=0&&x<n&&y>=0&&y<m)
                 {
                     a=x*m+y+1;
                    if(j==0)
                     ar[0][i+1]--;
                     else
                     ar[1][m-i]--;
                     x=x+R[j];
                     y=y+C[j];
                 }
             }
         }
        for(i=1;i<n;i++)
         {
             for(j=0;j<2;j++)
             {
                 int x=0,y=i;
                 if(j==0)
                 {
                     u=n*m+200+m+i;
                     x=i;y=m-1;
                 }
                 else
                 {
                     u=n*m+400+m+i;
                     x=i,y=0;
                 }

                 while(x>=0&&x<n&&y>=0&&y<m)
                 {
                     a=x*m+y+1;
                     if(j==0)
                     ar[0][m+i]--;
                     else
                     ar[1][m+i]--;
                     x=x+R[j];
                     y=y+C[j];
                 }
             }
         }
         for(i=0;i<m;i++)
         {
             for(j=0;j<2;j++)
             {
                 int x=0,y=i;
                 if(j==0)
                 {
                     u=n*m+200+i+1;
                     dm.add_edge(0,u,ar[0][i+1]);
                     x=0;y=i;
                 }
                 else
                 {
                     u=n*m+400+m-i;
                   //  x=i,y=m-1;
                     dm.add_edge(u,n*m+605,ar[1][m-i]);
                 }

                 while(x>=0&&x<n&&y>=0&&y<m)
                 {
                     a=x*m+y+1;
                     if(j==0)
                     dm.add_edge(u,a,cost[a]);
                     else
                     dm.add_edge(a,u,cost[a]);
                     x=x+R[j];
                     y=y+C[j];
                 }
             }
         }
        for(i=1;i<n;i++)
         {
             for(j=0;j<2;j++)
             {
                 int x=0,y=i;
                 if(j==0)
                 {
                     u=n*m+200+m+i;
                     dm.add_edge(0,u,ar[0][m+i]);
                     x=i;y=m-1;
                 }
                 else
                 {
                     u=n*m+400+m+i;
                     x=i,y=0;
                     dm.add_edge(u,n*m+605,ar[1][m+i]);
                 }

                 while(x>=0&&x<n&&y>=0&&y<m)
                 {
                     a=x*m+y+1;
                     if(j==0)
                     dm.add_edge(u,a,cost[a]);
                     else
                     dm.add_edge(a,u,cost[a]);
                     x=x+R[j];
                     y=y+C[j];
                 }
             }
         }
         nn=n,mm=m;
         pf("Case %d:\n",cs++);
         g=dm.dinic();
     }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/

