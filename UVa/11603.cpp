#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int inf = 1e9+7;
int n;
int cap[204][204];
struct node {
	int u, v, c;
};
vector <node> ans;
bool dfs(vector <int> v) {
    int Min = inf, i, j, sz = v.size();
    if(sz <= 1) return 1;
    for(i = 0; i < sz; i++)
        for(j = i+1; j < sz; j++)
            if(cap[v[i]][v[j]] < Min)
                Min = cap[v[i]][v[j]];
    vector <int> l, r;
    l.push_back(v[0]);
    for(i = 1; i < sz; i++)
        if(cap[v[0]][v[i]] > Min) l.push_back(v[i]);
        else r.push_back(v[i]);
    if(l.empty() || r.empty()) return 0;
    for(i = 0; i < l.size(); i++)
        for(j = 0; j < r.size(); j++)
            if(cap[l[i]][r[j]] != Min) return 0;
    if(Min > 0)ans.push_back(node{l[0], r[0], Min});
    return dfs(l) && dfs(r);
}
int main() {
    int i, j, cas, ca = 1;
    scanf("%d", &cas);
    while(cas--) {
    	scanf("%d", &n);
        vector <int> v;
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++)
                scanf("%d", &cap[i][j]);
        }
        printf("Case #%d: ", ca++);
        ans.clear();
        for(i = 0; i < n; i++) v.push_back(i);
        if(dfs(v)) {
            printf("%d\n", ans.size());
            for(i = 0; i < ans.size(); i++)
            	printf("%d %d %d\n", ans[i].u, ans[i].v, ans[i].c);
        }
        else puts("Impossible");
    }
    return 0;
}
