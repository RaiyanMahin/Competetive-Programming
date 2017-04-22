
// Running time, O(|V|^2) cost per augmentation
//     max flow:           O(|V|^3) augmentations
//     min cost max flow:  O(|V|^4 * MAX_EDGE_COST) augmentations
//
// INPUT:
//     - graph, constructed using AddEdge()
//     - source
//     - sink
// Uva 10594
// OUTPUT:
//     - (maximum flow value, minimum cost value)
//     - To obtain the actual flow, look at positive values only.
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
#define sn scanf
#define pf printf
#define pb push_back

typedef long long int ll;

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long L;
typedef vector<L> VL;
typedef vector<VL> VVL;
typedef pair<int, int> PII;
typedef vector<PII> VPII;

const L INF = 1LL<<62LL;

struct MinCostMaxFlow {
  int N;
  VVL cap, flow, cost;
  VI found;
  VL dist, pi, width;
  VPII dad;

  MinCostMaxFlow(int N) :
    N(N), cap(N, VL(N)), flow(N, VL(N)), cost(N, VL(N)),
    found(N), dist(N), pi(N), width(N), dad(N) {}

  void AddEdge(int from, int to, L cap, L cost) {
    this->cap[from][to] = cap;
    this->cost[from][to] = cost;
  }

  void Relax(int s, int k, L cap, L cost, int dir) {
    L val = dist[s] + pi[s] - pi[k] + cost;
    if (cap && val < dist[k]) {
      dist[k] = val;
      dad[k] = make_pair(s, dir);
      width[k] = min(cap, width[s]);
    }
  }

  L Dijkstra(int s, int t) {
    fill(found.begin(), found.end(), false);
    fill(dist.begin(), dist.end(), INF);
    fill(width.begin(), width.end(), 0);
    dist[s] = 0;
    width[s] = INF;

    while (s != -1) {
      int best = -1;
      found[s] = true;
      for (int k = 0; k < N; k++) {
        if (found[k]) continue;
        Relax(s, k, cap[s][k] - flow[s][k], cost[s][k], 1);
        Relax(s, k, flow[k][s], -cost[k][s], -1);
        if (best == -1 || dist[k] < dist[best]) best = k;
      }
      s = best;
    }

    for (int k = 0; k < N; k++)
      pi[k] = min(pi[k] + dist[k], INF);
    return width[t];
  }

  pair<L, L> GetMaxFlow(int s, int t) {
    L totflow = 0, totcost = 0;
    while (L amt = Dijkstra(s, t)) {
      totflow += amt;
      for (int x = t; x != s; x = dad[x].first) {
        if (dad[x].second == 1) {
          flow[dad[x].first][x] += amt;
          totcost += amt * cost[dad[x].first][x];
        } else {
          flow[x][dad[x].first] -= amt;
          totcost -= amt * cost[x][dad[x].first];
        }
      }
    }
    return make_pair(totflow, totcost);
  }
};
ll ar[3][100];
int main()
{
    ll i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;
    const int hival=100000;
    sn("%lld",&t);
    while(t--)
    {
        sn("%lld %lld %lld",&n,&k,&g);
        MinCostMaxFlow mx=MinCostMaxFlow(n+n+5);
        MinCostMaxFlow mn=MinCostMaxFlow(n+n+5);
        for(i=0;i<n;i++)
            {
                sn("%lld",&ar[0][i]);
                mx.AddEdge(0,i+1,1,0);
                mn.AddEdge(0,i+1,1,0);
            }
        for(i=0;i<n;i++)
            {
                sn("%lld",&ar[1][i]);
                mx.AddEdge(n+i+1,n+n+2,1,0);
                mn.AddEdge(n+i+1,n+n+2,1,0);
            }
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(ar[0][i]<ar[1][j])
                {
                    c=((ar[1][j]-ar[0][i])-k)*((ar[1][j]-ar[0][i])-k);
                    c=min(c,g);
                    mx.AddEdge(i+1,n+1+j,1,hival-c);
                    mn.AddEdge(i+1,n+j+1,1,c);
                }
            }
        }
        pair<ll,ll>ans1,ans2;
        ans1=mx.GetMaxFlow(0,n+n+2);
       ans2=mn.GetMaxFlow(0,n+n+2);
       pf("Case %lld: ",cs++);
        if(ans1.first!=n)
            pf("impossible\n");
        else
            pf("%lld %lld\n",ans2.second,n*hival-ans1.second);
    }
    return 0;
}
