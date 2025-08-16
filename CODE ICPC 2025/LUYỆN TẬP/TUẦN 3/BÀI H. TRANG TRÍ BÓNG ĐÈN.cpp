#include <bits/stdc++.h>
using namespace std;

struct Dinic {
    struct Edge { int to, rev; long long cap; };
    int n, s, t;
    vector<vector<Edge>> g;
    vector<int> level, iter;
    Dinic(int n = 0) : n(n), g(n), level(n), iter(n) {}
    void add_edge(int u, int v, long long c) {
        g[u].push_back({v, (int)g[v].size(), c});
        g[v].push_back({u, (int)g[u].size() - 1, 0});
    }
    bool bfs(int S, int T) {
        fill(level.begin(), level.end(), -1);
        queue<int> q; q.push(S);
        level[S] = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (auto &e : g[u]) {
                if (e.cap > 0 && level[e.to] < 0) {
                    level[e.to] = level[u] + 1;
                    q.push(e.to);
                }
            }
        }
        return level[T] >= 0;
    }
    long long dfs(int u, int T, long long f) {
        if (u == T) return f;
        for (int &i = iter[u]; i < (int)g[u].size(); ++i) {
            Edge &e = g[u][i];
            if (e.cap > 0 && level[u] < level[e.to]) {
                long long d = dfs(e.to, T, min(f, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    g[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }
    long long maxflow(int S, int T) {
        long long flow = 0;
        while (bfs(S, T)) {
            fill(iter.begin(), iter.end(), 0);
            while (long long f = dfs(S, T, LLONG_MAX)) flow += f;
        }
        return flow;
    }
};

int main() {
    int N, M; cin >> N >> M;
    struct EdgeIn { int u, v; long long w; };
    vector<EdgeIn> edges(M);
    vector<long long> degsum(N + 1, 0);
    long long totalW = 0;
    for (int i = 0; i < M; ++i) {
        int u, v; long long w;
        cin >> u >> v >> w;
        edges[i] = {u, v, w};
        degsum[u] += w; degsum[v] += w;
        totalW += w;
    }
    long long hi = totalW / max(1, N);
    for (int u = 1; u <= N; ++u) hi = min(hi, degsum[u]);
    auto feasible = [&](long long X) {
        int S = 0, T = M + N + 1, V = T + 1;
        Dinic din(V);
        const long long INF = LLONG_MAX / 2;
        for (int i = 0; i < M; ++i) {
            din.add_edge(S, 1 + i, edges[i].w);
            int u = edges[i].u, v = edges[i].v;
            din.add_edge(1 + i, 1 + M + (u - 1), INF);
            din.add_edge(1 + i, 1 + M + (v - 1), INF);
        }
        for (int u = 1; u <= N; ++u) din.add_edge(1 + M + (u - 1), T, X);
        long long flow = din.maxflow(S, T);
        return flow == X * (long long)N;
    };
    long long lo = 0, best = 0;
    while (lo <= hi) {
        long long mid = (lo + hi) / 2;
        if (feasible(mid)) {
            best = mid;
            lo = mid + 1;
        } else hi = mid - 1;
    }
    cout << totalW - best * (long long)N << '\n';
}
