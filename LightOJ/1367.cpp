
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
struct dinic_maxflow{


struct edge {
	int a, b, cap, flow;
	edge(int _a,int _b,int _cap,int _flow)
	{
	    a=_a,b=_b,cap=_cap,flow=_flow;
	}
};

int n, s, t, d[MAXN], ptr[MAXN], q[MAXN],fin;
vector<edge> e;
vector<int> g[MAXN];
vector<int>sat,tot,en;

void add_edge (int a, int b, int cap,int ty=0) {
	edge e1 = edge( a, b, cap, 0 );
	edge e2 = edge( b, a, 0, 0 );
	g[a].push_back ((int) e.size());
	if(ty==1){
        sat.pb(e.size());
	}
	if(ty==2)
        tot.pb(e.size());
    if(ty==3)
        en.pb(e.size());
    if(ty==4)
        fin=e.size();
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
    sn("%d",&t);
    while(t--){
        sn("%d %d",&n,&m);
        dinic_maxflow dm= dinic_maxflow(n+5,0,n+2);
        int sr=0,sd=n+2;
        vector<int>sav;
        for(i=0;i<m;i++){
            sn("%d %d %d %d",&u,&v,&a,&b);
            dm.add_edge(u,v,b-a,2);
            dm.add_edge(u,sd,a,1);
            dm.add_edge(sr,v,a,3);
            sav.pb(a);
        }
        dm.add_edge(n,1,INF,4);
       // dm.add_edge(sr,1,INF);
      //  dm.add_edge(n,sd,INF);
        int ans=dm.dinic();
       // pf("%d\n",ans);
        a=0;
        for(i=0;i<dm.sat.size();i++){
            if(dm.e[dm.sat[i]].flow!=sav[i])
                a=1;
            dm.e[dm.sat[i]].cap=0;
            dm.e[dm.sat[i]^1].cap=0;
            dm.e[dm.sat[i]].flow=0;
            dm.e[dm.sat[i]^1].flow=0;
            dm.e[dm.en[i]].cap=0;
            dm.e[dm.en[i]^1].cap=0;
            dm.e[dm.en[i]].flow=0;
            dm.e[dm.en[i]^1].flow=0;
        }
            dm.e[dm.fin].cap=0;
            dm.e[dm.fin^1].cap=0;
            dm.e[dm.fin].flow=0;
            dm.e[dm.fin^1].flow=0;
        if(a==0){
            pf("Case %d: yes\n",cs++);
            for(i=0;i<dm.sat.size();i++){
                pf("%d\n",sav[i]+dm.e[dm.tot[i]].flow);
            }
        }
        else{
            pf("Case %d: no\n",cs++);
        }
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/

