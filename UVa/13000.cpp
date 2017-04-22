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
const long long int INF = 10000000000;
struct dinic_maxflow{


struct edge {
	ll a, b;
	ll flow,cap;
	edge(ll _a,ll _b,ll _cap,ll _flow)
	{
	    a=_a,b=_b,cap=_cap,flow=_flow;
	}
};

ll n, s, t, d[MAXN], ptr[MAXN], q[MAXN];
vector<edge> e;
vector<ll> g[MAXN];

void add_edge (ll a, ll b, ll cap) {
	edge e1 = edge( a, b, cap, 0 );
	edge e2 = edge( b, a, 0, 0 );
	g[a].push_back ((ll) e.size());
	e.push_back (e1);
	g[b].push_back ((ll) e.size());
	e.push_back (e2);
}

bool bfs() {
	ll qh=0, qt=0;
	q[qt++] = s;
	memset (d, -1, n * sizeof d[0]);
	d[s] = 0;
	while (qh < qt && d[t] == -1) {
		ll v = q[qh++];
		for (size_t i=0; i<g[v].size(); ++i) {
			ll id = g[v][i],
				to = e[id].b;
			if (d[to] == -1 && e[id].flow < e[id].cap) {
				q[qt++] = to;
				d[to] = d[v] + 1;
			}
		}
	}
	return d[t] != -1;
}

ll dfs (ll v, ll flow) {
	if (!flow)  return 0;
	if (v == t)  return flow;
	for (; ptr[v]<(ll)g[v].size(); ++ptr[v]) {
		ll id = g[v][ptr[v]],
			to = e[id].b;
		if (d[to] != d[v] + 1)  continue;
		ll pushed = dfs (to, min (flow, e[id].cap - e[id].flow));
		if (pushed) {
			e[id].flow += pushed;
			e[id^1].flow -= pushed;
			return pushed;
		}
	}
	return 0;
}

ll dinic( ) {
	ll flow = 0;
	for (;;) {
		if (!bfs())  break;
		memset (ptr, 0, n * sizeof ptr[0]);
		while (ll pushed = dfs (s, INF))
			flow += pushed;
	}
	return flow;
}
    dinic_maxflow( ll _n, ll _s, ll _t ){
        n = _n; s = _s; t = _t;
    }
};
struct TT{
ll a,b,c,ar[55];
}arr[55];
ll ar[55];
ll go_flow(ll n,ll m,ll k,ll tt)
{
    dinic_maxflow dm=dinic_maxflow(n+m+10,0,n+m+8);
    ll s=0,d=n+m+8,rg=n+m+5,i,j;
    for(i=0;i<n;i++)
    {
        dm.add_edge(s,i+1,tt/ar[i]);
    }
    dm.add_edge(rg,d,k);
    for(i=0;i<m;i++)
    {
        dm.add_edge(n+i+1,d,arr[i].a);
        dm.add_edge(n+i+1,rg,arr[i].b);
        for(j=0;j<arr[i].c;j++)
        {
            dm.add_edge(arr[i].ar[j],n+i+1,INF);
        }
    }
    return dm.dinic();
}
int main()
{
    ll i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;
  #ifdef O_judge
    //freopen(".txt","r",stdin);
  #endif
     sn("%lld",&t);
     while(t--)
     {
         sn("%lld %lld %lld",&m,&n,&k);
         for(i=0;i<n;i++)
         {
             sn("%lld",&ar[i]);
         }
         s=0;
         for(i=0;i<m;i++)
         {
             sn("%lld %lld %lld",&arr[i].a,&arr[i].b,&arr[i].c);
             s=s+arr[i].a;
             for(j=0;j<arr[i].c;j++)
             {
                 sn("%lld",&arr[i].ar[j]);
             }
         }
         ll lw=0,hi=20000000000,mid;
         while(lw<=hi)
         {
             mid=(lw+hi)/2;
             if(go_flow(n,m,k,mid)==s+k)
             {
                 if(mid>0&&go_flow(n,m,k,mid-1)==s+k)
                    hi=mid-1;
                 else break;
             }
             else
             {
                 lw=mid+1;
             }
         }
         pf("Case %lld: %lld\n",cs++,mid);
     }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/


