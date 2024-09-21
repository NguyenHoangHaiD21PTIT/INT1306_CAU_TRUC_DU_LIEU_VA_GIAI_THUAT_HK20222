#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
long long n, m; 
vector<pair<long long, long long>> points(N); 
vector<int> graph[N];
bool visited[N];

void DFS(int u, long long& Xmin, long long& Xmax, long long& Ymin, long long& Ymax) {
    visited[u] = true;
    Xmin = min(Xmin, points[u].first);
    Xmax = max(Xmax, points[u].first);
    Ymin = min(Ymin, points[u].second);
    Ymax = max(Ymax, points[u].second);
    for (int v: graph[u]) {
        if (!visited[v]) DFS(v, Xmin, Xmax, Ymin, Ymax);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> points[i].first >> points[i].second;
    for (int i = 1; i <= m; ++i) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    long long res = LLONG_MAX;
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            long long Xmin = LLONG_MAX, Xmax = LLONG_MIN;
            long long Ymin = LLONG_MAX, Ymax = LLONG_MIN;
            DFS(i, Xmin, Xmax, Ymin, Ymax);
            res = min(res, 2 * ((Xmax - Xmin) + (Ymax - Ymin)));
        }
    }
    cout << res;
}
