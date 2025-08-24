#include <bits/stdc++.h>
using namespace std;

struct St {
    int u, v, t, d; 
}; 
// u: robot A tại đỉnh u
// v: robot B tại đỉnh v
// t: bước hiện tại mod 3
// d: số bước đã đi

// Hàm tính màu ban đầu của cạnh để sau t bước khớp màu đích
int need(int goal, int t) {
    int x = goal - t;
    x %= 3;
    if (x <= 0) x += 3;
    return x;
}

int main() {
    int T; cin >> T;
    while (T--) {
        int n, m; 
        cin >> n >> m;
        vector<int> col(n + 1);
        for (int i = 1; i <= n; i++) cin >> col[i];
        // adj[x][c] = {y1, y2, ...}: Cạnh x --> y1, x --> y2 ... có màu ban đầu là c
        vector<int> adj[205][4];
        for (int i = 0; i < m; i++) {
            int a, b, c; 
            cin >> a >> b >> c;
            adj[a][c].push_back(b);
        }
        // vis[t][u][v] = t: Số bước mod 3, u, v: Vị trí Robot 1, 2 tại thời điểm t
        char vis[3][205][205] = {};
        queue<St> q;
        vis[0][1][2] = 1;
        q.push({1, 2, 0, 0}); // (A = 1, B = 2, t = 0, dist = 0)
        int ans = -1;
        while (!q.empty()) {
            auto cur = q.front(); q.pop();
            int a = cur.u, b = cur.v, t = cur.t, d = cur.d;
            if (a == b) { 
                ans = d;
                break; 
            }
            // Lúc này, robot A ở a, robot B ở b.
            // Robot A muốn đi cạnh mà màu cạnh lúc t = màu đỉnh B.
            // Vì đồ thị chỉ lưu màu cạnh ban đầu (t = 0), ta phải tính ra màu ban đầu tương ứng.
            // Tức là: "Cạnh lúc đầu có màu gì để sau t bước màu cạnh = màu đỉnh B".
            int c1 = need(col[b], t), c2 = need(col[a], t); 
            int nt = (t + 1) % 3;
            for (int x : adj[a][c1]) {
                for (int y : adj[b][c2]) {
                    if (!vis[nt][x][y]) {
                        vis[nt][x][y] = 1;
                        q.push({x, y, nt, d + 1});
                    }
                }
            }
        }
        cout << ans << "\n";
    }
}
