
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
      fill(pi.begin(), pi.end(),0);
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
ll ar[10000],con[1500][3], arr[25];
int main()
{
   ll i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;
     arr[1]=1;arr[2]=2;arr[0]=0;
    for(i=3;i<=21;i++)
    {
        arr[i]=arr[i-1]+(i-2)*6;
        //pf("%lld\n",arr[i]);
    }
    sn("%lld",&t);
    while(t--)
    {
        sn("%lld %lld",&n,&m);
        u=3*n*n-3*n+1;
        for(i=0;i<u;i++)
        {
            sn("%lld",&ar[i+1]);
        }
        pf("Case %lld:\n",cs++);
        for(i=n;i>0;i--)
        {
            a=n-i;
            b=2*i-1;
            c=arr[i];
            for(k=0;k<b;k++)
            {
                con[c++][0]=++a;
            }
            for(k=0;k<i-1;k++)
            {
                con[c++][0]=a;
            }
            for(k=0;k<b-1;k++)
            {
                con[c++][0]=--a;
            }
            for(k=0;k<i-2;k++)
            {
                con[c++][0]=a;
            }
        }
        for(i=n;i>0;i--)
        {
            a=n-i+1;
            b=2*i-1;
            c=arr[i];
             for(k=0;k<i;k++)
            {
                con[c++][1]=a;
            }
            for(k=0;k<b-1;k++)
            {
                con[c++][1]=++a;
            }
            for(k=0;k<i-1;k++)
            {
                con[c++][1]=a;
            }
            for(k=0;k<b-2;k++)
            {
                con[c++][1]=--a;
            }
        }
//        pf("\n");
//        for(i=1;i<arr[n+1];i++)
//        {
//            pf("%lld=%lld ",i,con[i][0]);
//        }
//        pf("\n");
//        for(i=1;i<arr[n+1];i++)
//        {
//            pf("%lld=%lld ",i,con[i][1]);
//        }
        h=2*n-1;
        MinCostMaxFlow mx=MinCostMaxFlow(2*h+3);
        for(i=1;i<=u;i++)
        {
           mx.AddEdge(con[i][0],h+con[i][1],1,ar[i]);
        }
        for(f=1;f<=m;f++)
        {
            sn("%lld",&v);
            for(i=1;i<=h;i++)
                {
                    mx.flow[0][i]=0;
                    mx.flow[h+i][2*h+2]=0;
                    mx.AddEdge(0,i,2,0);
                    mx.AddEdge(h+i,2*h+2,3,0);
                }
              mx.flow[2*h+1][0]=0;
              mx.AddEdge(2*h+1,0,v,f-1);
            pair<ll,ll>ans=mx.GetMaxFlow(2*h+1,2*h+2);
            pf("Month %lld: %lld unit of money\n",f,ans.second);
        }
        pf("\n");
    }
    return 0;
}

