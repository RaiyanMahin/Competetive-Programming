/* in the name of ALLAH, most gracious, most merciful */
#include <stdio.h>
#include <string.h>

const int MAX_N = int (3e4) + 7;
const int MAX_E = MAX_N << 1;

int n, m, g [MAX_N];
int from [MAX_E], to [MAX_E], last [MAX_E];

int cnt, tr [MAX_N];
void add (int i, int v) {
    for (; i <= cnt; i += i & -i) tr [i] += v;
}

int get (int i) {
    int s = 0;
    for (; i; i -= i & -i) s += tr [i];
    return s;
}

int get (int i, int j) {
    return get (j) - get (i - 1);
}

// parent, depth, size, successor in chain
int p [MAX_N], d [MAX_N], sz [MAX_N], suc [MAX_N];
void dfs (int u, int par = -1) {
    p [u] = par, sz [u] = 1, suc [u] = -1;
    d [u] = ~par ? d [par] + 1 : 0;

    int v, mx = 0;
    for (int e = last [u]; ~e; e = from [e]) {
        if (par == (v = to [e])) continue;
        dfs (v, u);
        if (sz [v] > mx)
            suc [u] = v, mx = sz [v];
        sz [u] += sz [v];
    }
}

// chain head (head is head of himself), id in BIT
int head [MAX_N], id [MAX_N];
void make_chain (int u, bool in_chain = false) {
    head [u] = in_chain ? head [p [u]] : u;
    id [u] = ++cnt;

    if (~suc [u]) make_chain (suc [u], true);
    for (int e = last [u]; ~e; e = from [e]) {
        if (suc [u] == to [e] || p [u] == to [e]) continue;
        make_chain (to [e]);
    }
}

int lca (int u, int v) {
    int ret = 0;
    while (head [u] != head [v]) {
        if (d [head [u]] > d [head [v]]) {
            ret += get (id [head [u]], id [u]);
            u = p [head [u]];
        } else {
            ret += get (id [head [v]], id [v]);
            v = p [head [v]];
        }
    }

    if (d [u] < d [v])
        ret += get (id [u], id [v]);
    else
        ret += get (id [v], id [u]);
    return ret;
}

void init () {
    cnt = 0;
    memset (last, -1, sizeof last);
    memset (tr, 0, sizeof tr);
}

bool read (int &x) {
    int c = getchar (); int sign = 1;
    while (~c && c < '0' || c > '9') { if (c == '-') sign = -1; c = getchar (); }
    for (x = 0; ~c && '0' <= c && c <= '9'; c = getchar ()) x = x * 10 + c - '0';
    x *= sign;
    return ~c;
}

int main () {
#ifdef Local
	freopen ("input.txt", "r", stdin);
	// freopen ("output.txt", "w", stdout);
#endif
    int t;
    read (t);

    for (int cs = 1; cs <= t; ++cs) {
        read (n);
        init ();

        for (int i = 0; i < n; ++i)
            read (g [i]);

        int nE = 0;
        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            read (u); read (v);
            to [nE] = v, from [nE] = last [u], last [u] = nE++;
            to [nE] = u, from [nE] = last [v], last [v] = nE++;
        }

        dfs (0);
        make_chain (0);
        p [0] = 0;

        for (int i = 0; i < n; ++i)
            add (id [i], g [i]);

        read (m);
        printf ("Case %d:\n", cs);

        for (int i = 0; i < m; ++i) {
            int type, u, v;
            read (type); read (u); read (v);

            if (type) add (id [u], v - get (id [u], id [u]));
            else printf ("%d\n", lca (u, v));
        }
    }
	return 0;
}
