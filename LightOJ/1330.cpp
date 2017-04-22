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
int ar[100][100];

int main()
{
    int i,j,k,t,l,m,n,a,b,c,d,s,u,v,g,h,e,f,cs=1,r;
    sn("%d",&t);
    while(t--)
    {
        sn("%d %d",&n,&m);s=0;d=n+m+10;
        dinic_maxflow dm=dinic_maxflow(d+10,s,d);
        e=f=0;
        for(i=0;i<n;i++)
        {
            sn("%d",&u);
            e+=u;
            dm.add_edge(s,i+1,u);
        }
        for(i=0;i<m;i++)
        {
            sn("%d",&u);
            f+=u;
            dm.add_edge(n+i+1,d,u);
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                dm.add_edge(i+1,n+j+1,1);
            }
        }
        pf("Case %d:",cs++);
        if(e==f)
        {
            h=dm.dinic();
            if(h==f)
            {
                memset(ar,0,sizeof(ar));
                for(i=0;i<n;i++)
                {
                    for(j=0,k=dm.g[i+1].size();j<k;j++)
                    {
                        v=dm.g[i+1][j];
                        if(dm.e[v].b>0&&dm.e[v].b<d&&dm.e[v].flow==1)
                        {
                            u=dm.e[v].b-n-1;
                            dm.e[dm.g[0][i]].cap++;
                            dm.e[dm.g[d][u]^1].cap++;
                            h=dm.dinic();
                            if(h==0)
                            {
                                ar[i][u]=1;
                                dm.e[dm.g[0][i]].cap--;
                                dm.e[dm.g[d][u]^1].cap--;
                            }
                        }
                        else
                        {
                            dm.e[v].cap=0;
                        }
                    }

                }
                 pf("\n");
                for(i=0;i<n;i++)
                {
                    for(j=0;j<m;j++)
                    {
                        pf("%d",ar[i][j]);
                    }
                    pf("\n");
                }
            }
            else
            {
              pf(" impossible\n");
            }
        }
        else
            pf(" impossible\n");
    }
    return 0;
}
