#include <bits/stdc++.h>
using namespace std;

struct Node {
    int i, j, tmod, dist;
};
//Màu ban đầu là gì, để sau tmod bước, đạt màu target: Ban đầu + t bước = Target --> Lấy mod cả 2 vế
int need_c0(int target, int tmod) {
    int x = target - tmod;
    x %= 3;
    if (x <= 0) x += 3; 
    return x;
}
int main() {
    int T; cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        vector<int> color(N + 1);
        for (int i = 1; i <= N; ++i) cin >> color[i];
        // adj[u][c0] = Tập đỉnh kề v của đỉnh u với điều kiện cạnh u --> v chứa màu c0
        vector<int> adj[205][4];
        for (int e = 0; e < M; ++e) {
            int u, v, c0;
            cin >> u >> v >> c0;
            adj[u][c0].push_back(v);
        }
        // visited[Số bước di chuyển][Vị trí robot 1][Vị trí robot 2]
        char vis[3][205][205] = {};
        queue<Node> q;
        vis[0][1][2] = 1;
        q.push({1, 2, 0, 0}); //qe(tmod, pos1, pos2, dist)
        int ans = -1;
        while (!q.empty()) {
            Node cur = q.front(); q.pop();
            int i = cur.i, j = cur.j, tmod = cur.tmod, dist = cur.dist;
            if (i == j) { 
                ans = dist; 
                break; 
            }
            int need1 = need_c0(color[j], tmod); // màu ban đầu cần ở cạnh đi từ i
            int need2 = need_c0(color[i], tmod); // màu ban đầu cần ở cạnh đi từ j
            int next_t = (tmod + 1) % 3;
            const vector<int> U = adj[i][need1], V = adj[j][need2];
            if (U.empty() || V.empty()) continue;
            for (int ui = 0; ui < (int)U.size(); ++ui) {
                int u = U[ui];
                for (int vi = 0; vi < (int)V.size(); ++vi) {
                    int v = V[vi];
                    if (!vis[next_t][u][v]) {
                        vis[next_t][u][v] = 1;
                        q.push({u, v, next_t, dist + 1});
                    }
                }
            }
        }
        cout << ans << '\n';
    }
}
