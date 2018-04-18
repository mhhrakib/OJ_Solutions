//
// Created by @mhhrakib on 4/18/18.
//

#include<bits/stdc++.h>

using namespace std;
const int N = 201;
const int inf = 1 << 28;

struct edge {
    int u, v, w;

    edge() {}

    edge(int _u, int _v, int _w) {
        u = _u;
        v = _v;
        w = _w;
    }
};


int dist[N], busy[N];

void Bellman_Ford(int s, int nodes, vector<edge> E) {
    int i, tmp, cnt;

    for (i = 1; i <= nodes; i++)
        dist[i] = inf;
    dist[s] = 0;

    int sz = E.size();

    for (i = 1; i < nodes; i++) {
        cnt = 0;
        for (int j = 0; j < sz; j++) {
            edge e = E[j];
            tmp = dist[e.u] + e.w;
            if (dist[e.v] > tmp) {
                dist[e.v] = tmp;
                cnt++;
            }
        }
        if (!cnt)
            return;
    }
}

int cube(int n) {
    return n * n * n;
}

int main() {
    int t;
    scanf("%d", &t);
    int n, m, u, v, w, cn = 1, q;

    while (t--) {

        vector<edge> E;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &busy[i + 1]);
        }

        scanf("%d", &m);

        for (int i = 0; i < m; i++) {
            scanf("%d %d", &u, &v);
            w = cube(busy[v] - busy[u]);
            E.push_back(edge(u, v, w));
        }

        scanf("%d", &q);
        Bellman_Ford(1, n, E);
        printf("Case %d:\n", cn++);
        for (int i = 0; i < q; i++) {
            int x;
            scanf("%d", &x);
            int res = dist[x];
            if (res < 3 || res >= 268400000) {
                printf("?\n");
            } else
                printf("%d\n", res);
        }
    }

    return 0;
}