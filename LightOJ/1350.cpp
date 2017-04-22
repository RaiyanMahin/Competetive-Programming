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
int a,b;
 bool operator <(const T &bb)const
 {
      return b<bb.b;
 }
};
const int MAXN = 500;
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
char st[50];
int id[60],node[200],X[55],Y[55],Z[55],val[200];
int ar[10005][55];
int arr[10005][55],siz[10005];
int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;

   // freopen("E:\\uva\\1.unsubmitt\\LightOj\\Unsubmitted\\in.txt","r",stdin);

     sn("%d",&t);
     u=1;
     for(i='a';i<='z';i++)
        id[u++]=i;
     for(i='A';i<='Z';i++)
        id[u++]=i;
     while(t--)
     {
         sn("%d %d %d %d",&n,&a,&b,&m);
         dinic_maxflow dm=dinic_maxflow(201,0,200);
         int sr=0,des=200;
         s=0;h=0;
         for(i=0;i<n;i++)
         {
             sn("%d %d %d",&u,&v,&f);
             X[i]=u;Y[i]=v;Z[i]=f;
             node[h++]=u;
             node[h++]=v;
             dm.add_edge(sr,i+1,f);
             s=s+f;
         }
         sort(node,node+h);
         c=1;
         for(i=1;i<h;i++)
         {
             if(node[c-1]!=node[i])
                node[c++]=node[i];
         }
         node[c]=m;
         for(i=0;i<c;i++)
         {
             val[i]=node[i+1]-node[i];
         }
         for(i=0;i<n;i++)
         {
             for(j=0;j<c;j++)
             {
                 if(node[j]>=X[i]&&node[j]<Y[i])
                 {
                     dm.add_edge(i+1,n+j+1,val[j]);
                 }
             }
         }
         for(i=0;i<c;i++)
            dm.add_edge(n+i+1,des,val[i]*a*b);
         int ans=dm.dinic();
         memset(ar,0,sizeof(ar));
         memset(arr,0,sizeof(arr));
         memset(siz,0,sizeof(siz));
         if(ans==s)
         {
             pf("Case %d: Yes\n",cs++);
             h=0;
             for(i=0;i<n;i++)
             {
                 for(j=0;j<dm.g[i+1].size();j++)
                 {
                     g=0;u=dm.e[dm.g[i+1][j]].b-n-1;
                     if(u<0)
                        continue;
                    // Z[i]-=dm.e[dm.g[i+1][j]].flow;
                    g=dm.e[dm.g[i+1][j]].flow;
                    ar[u][i]+=g;
                    if(ar[u][i]>val[u])
                        h=1;
                 }

                // pf("\n");
             }
             h=0;
             for(i=0;i<c;i++)
             {
                 f=0;
                 for(j=0;j<n;j++)
                 {
                     f=f+ar[i][j];
                 }
                 if(f>val[i]*a*b)
                    h=1;
             }
             for(i=0;i<c;i++)
             {
                 for(v=0;v<val[i];v++)
                 {
                     priority_queue<T>Q;
                     T tem;f=0;
                     for(j=0;j<n;j++)
                     {
                         tem.a=j;tem.b=ar[i][j];
                         if(ar[i][j]>0)
                            Q.push(tem),f++;
                     }
                     for(j=0,e=min(a*b,f);j<e;j++)
                     {
                          tem=Q.top();Q.pop();
                          ar[i][tem.a]--;
                          arr[node[i]+v][tem.a]=1;
                     }
                 }
             }
             for(i=1;i<m;i++)
             {
                 for(j=0;j<a*b;j++)
                    st[j]='.';
                 st[j]=0;
                 u=0;
                 for(j=0;j<n;j++)
                 {
                     if(arr[i][j]==1)
                     {
                         st[u++]=id[j+1];
                         //ar[i+1][j]+=(ar[i][j]-1);
                        // Z[j]--;
                     }
                    // else ar[i+1][j]+=(ar[i][j]);
                 }
                 for(j=0;j<a;j++)
                 {
                     if(j!=0)
                        pf("|");
                     for(k=0;k<b;k++)
                     {
                         pf("%c",st[j*b+k]);
                     }
                 }
                 pf("\n");
             }
             for(i=0;i<n;i++)
                if(Z[i]!=0)
                  h=2;
             while(h==1)
             {

             }
         }
         else
            pf("Case %d: No\n",cs++);

     }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/


