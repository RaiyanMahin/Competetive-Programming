
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

const L INF = 1LL<<42LL;
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
        if (best == -1 || dist[k] < dist[best])
        {
            best=k;
        }

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
ll ar[4][105],mnx[105];
int main()
{
   ll i,j,k,sup,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f=0,g,h,u,v;
    sn("%lld",&t);
    while(t--)
    {
        for(i=0;i<100;i++)mnx[i]=100000;
        sn("%lld %lld %lld",&n,&c,&r);
        MinCostMaxFlow mn=MinCostMaxFlow(c+n+n+4);
        s=0;d=c+n+n+3;f=0;
        for(i=0;i<n;i++)
        {
            sn("%lld",&ar[0][i]);
            f=f+ar[0][i];
            mn.AddEdge(s,i+1,ar[0][i],0);
            mn.AddEdge(n+i+1,d,ar[0][i],0);
            if(i<n-1)
            {
                mn.AddEdge(i+1,i+2,100000,0);
            }
        }
        for(i=j=0;i<2*c;i++)
        {
            sn("%lld",&ar[1][i]);
            if(i%2==1)
            {
                mn.AddEdge(s,n+n+j+1,ar[1][i-1],ar[1][i]);
                for(k=0;k<n;k++)
                {
                    mn.AddEdge(n+n+j+1,n+k+1,100000,0);
                }
                j++;
            }
        }
        for(i=j=0;i<2*r;i++)
        {
            sn("%lld",&ar[2][i]);
            if(i%2==1)
            {
                mnx[ar[2][i-1]]=min(mnx[ar[2][i-1]],ar[2][i]);
            }
        }
        for(i=0;i<n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(i+j+1<n&&mnx[j]<=400)
                {
                    mn.AddEdge(i+1,n+i+j+2,100000,mnx[j]);
                }
            }
        }
        ll ans=0;
        pair<ll,ll>tem;
       pf("Case %lld: ",cs++);
        tem=mn.GetMaxFlow(s,d);
        if(tem.first!=f)
            pf("impossible\n");
        else
        pf("%lld\n",tem.second);
    }
    return 0;
}
/*
9 1 2
1 2 3 4 1 2 3 4 1
10 1
3 5 4 1
ans:65
*/
