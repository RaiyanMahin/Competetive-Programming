//All pair max flow
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <bitset>
#include <vector>
#include <cstdio>
#include <string>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define PB push_back
#define MP make_pair
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

typedef int F;
#define inf (1 << 29)
#define maxV 205
#define maxE 160005
struct Dinic {
	int V, E;
	F cap[maxE], flow[maxE];
	int to[maxE], prev[maxE];
	int level[maxV], used[maxV], last[maxV];
	bool mkS[maxV];

	void init(int n) {
		V = n; E = 0;
		for (int i = 0; i < V; i++) last[i] = -1;
	}

	void reset() {
		memset(mkS, 0, sizeof(mkS));
		memset(flow, 0, sizeof(flow));
	}

	void addCap(int x, int y, F f) {
		//cout << x << " " << y << " " << f << endl;
		cap[E] = f; flow[E] = 0; to[E] = y; prev[E] = last[x]; last[x] = E; E++;
		cap[E] = 0; flow[E] = 0; to[E] = x; prev[E] = last[y]; last[y] = E; E++;
	}

	bool bfs(int s, int t) {
		for (int i = 0; i < V; i++)
			level[i] = -1;
		queue<int> q;
		q.push(s); level[s] = 0;
		while (!q.empty()) {
			int x = q.front(); q.pop();
			for (int i = last[x]; i != -1; i = prev[i])
				if (level[to[i]] == -1 && cap[i] > flow[i]) {
					q.push(to[i]);
					level[to[i]] = level[x] + 1;
				}
		}
		return (level[t] != -1);
	}

	F dfs(int v, int t, F f) {
		if (v == t) return f;
		for (int i = used[v]; i != -1; used[v] = i = prev[i])
			if (level[to[i]] > level[v] && cap[i] > flow[i]) {
				F tmp = dfs(to[i], t, min(f, cap[i] - flow[i]));
				if (tmp > 0) {
					flow[i] += tmp;
					flow[i ^ 1] -= tmp;
					return tmp;
				}
			}
		return 0;
	}

	F solve(int s, int t) {
		while (bfs(s, t)) {
			for (int i = 0; i < V; i++) used[i] = last[i];
			while (dfs(s, t, inf) != 0);
		}
		F ans = 0;
		for (int i = last[s]; i != -1; i = prev[i])
			ans += flow[i];
		return ans;
	}

	void traS(int u) {
		mkS[u] = true;
		for (int i = last[u], v; i != -1; i = prev[i]) {
			if (cap[i] - flow[i] > 0 && !mkS[v = to[i]]) {
				traS(v);
			}
		}
	}
};
struct Gomory_Hu_Tree {
	int n;
	int mincut[maxV][maxV];
	Dinic mf;

	void init(int n) {
		this->n = n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				mincut[i][j] = i == j ? 0 : inf;
			}
		}
		mf.init(n);
	}

	void addEdge(int a, int b, int c) {
		mf.addCap(a, b, c);
	}

	void output() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				printf("%d%c", mincut[i][j], j == n - 1 ? '\n' : ' ');
			}
		}
	}

	void solve() {
		vector<int> cur;
		for (int i = 0; i < n; i++)
			cur.PB(i);
		Rec(cur);
		output();
	}

	void Rec(vector<int> cur) {
		if (cur.size() <= 1) return;
		int s = cur[0], t = cur[1];
		mf.reset();
		int cut = mf.solve(s, t);
		mf.traS(s);
		for (int i = 0; i < n; i++) {
			if (mf.mkS[i]) {
				for (int j = 0; j < n; j++) {
					if (!mf.mkS[j]) {
						mincut[i][j] = mincut[j][i] = min(mincut[i][j], cut);
					}
				}
			}
		}
		vector<int> ch[2];
		for (int i = 0; i < cur.size(); i++) {
			int now = cur[i];
			if (mf.mkS[now]) ch[0].PB(now);
			else ch[1].PB(now);
		}
		Rec(ch[0]);
		Rec(ch[1]);
	}

}gh;

//Uva11495
int main(int argc, char const *argv[])
{
	int Test;
	scanf("%d", &Test);
	for (int cas = 1; cas <= Test; cas++) {
		printf("Case #%d:\n", cas);
		int n;
		scanf("%d", &n);
		gh.init(n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int x;
				scanf("%d", &x);
				if (i == j) continue;
				gh.addEdge(i, j, x);
			}
		}
		gh.solve();
	}
	return 0;
}

/*
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 203;
const int inf = 1e9;
struct Edge {
	int v, c, next;
	Edge(){}
	Edge(int v, int c, int next) : v(v), c(c), next(next) {}
}edge[maxn*maxn<<1];

int n, m;
int head[maxn], E;

void init() {
	E = 0;
	memset(head, -1, sizeof(head));
}

void add(int s, int t, int c) {
	edge[E] = Edge(t, c, head[s]);
	head[s] = E++;
	edge[E] = Edge(s, 0, head[t]);
	head[t] = E++;
}
int gap[maxn], dis[maxn], pre[maxn], cur[maxn];
int sap(int s, int t, int n) // s 源点，t汇点，n顶点总数
        {
    int i;
    for(i = 0; i <= n; i++) {
        dis[i] = gap[i] = 0;
        cur[i] = head[i];
    }
    gap[0] = n;
    int u = pre[s] = s, maxf = 0, aug = inf, v;
    while(dis[s] < n) {
        loop: for(i = cur[u]; ~i; i = edge[i].next) {
            v = edge[i].v;
            if(edge[i].c  && dis[u] == dis[v] + 1) {
                aug = min(aug, edge[i].c);
                pre[v] = u;
                cur[u] = i;
                u = v;
                if(u == t) {
                    while(u != s) {
                        u = pre[u];
                        edge[cur[u]].c -= aug;
                        edge[cur[u] ^ 1].c += aug;
                    }
                    maxf += aug;
                    aug = inf;
                }
                goto loop;
            }
        }
        int d = n;
        for(i = head[u]; ~i; i = edge[i].next) {
            v = edge[i].v;
            if(edge[i].c && dis[v] < d) {
                d = dis[v];
                cur[u] = i;
            }
        }
        if(!(--gap[dis[u]]))
            break;
        ++gap[dis[u] = d + 1];
        u = pre[u];
    }
    return maxf;
}
//************************
int ans[maxn][maxn], p[maxn]; // p[i]: 点i的集合编号
bool mk[maxn];
void dfs(int u) {
	mk[u] = 1;
	int i;
	for(i = head[u]; ~i; i = edge[i].next) {
        int v = edge[i].v;
        if(!mk[v] && edge[i].c) dfs(v);
	}
}
void solve(int n) {
	int i, j;
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			ans[i][j] = inf;
		}
		p[i] = 0;
	}
	for(i = 1; i < n; i++) {
		for(j = 0; j < E; j += 2) { //把图还原成原图
			edge[j].c += edge[j^1].c;
			edge[j^1].c = 0;
		}
		for(j = 0; j < n; j++) mk[j] = 0;
		int cut = sap(i, p[i], n);	//算法中取集合里的任意两点：这里我们有规则地取。
		ans[i][p[i]] = ans[p[i]][i] = cut;
		dfs(i);		//找出被s-t割割掉后的一个集合，那么剩下的点就是另外一个集合
		for(j = i+1; j < n; j++) if(mk[j] && p[i] == p[j]) 	//找出的集合更新集合编号
			p[j] = i;
		for(j = 0; j < i; j++)	//用当前s-t割去更新被其割掉的         已经选过的所有点组成的点对
			ans[i][j] = ans[j][i] = min(cut, ans[p[i]][j]);
	}
	for(i = 0; i < n; i++)
        for(j = 0; j < n; j++) {
            if(i == j) printf("0");
            else printf("%d", ans[i][j]);
            if(j == n-1) puts("");
            else printf(" ");
        }
}
int tp;
int main() {
	int i, j, cas;
	scanf("%d", &cas);
	for(int ca = 1; ca <= cas; ca++) {
        scanf("%d", &n);
		printf("Case #%d:\n", ca);
		if(!n) continue;
		init();
		for(i = 0; i < n; i++)
			for(j = 0; j < n; j++) {
				scanf("%d", &tp);
				if(tp) add(i, j, tp);
			}
		solve(n);
	}
	return 0;
}
*/
