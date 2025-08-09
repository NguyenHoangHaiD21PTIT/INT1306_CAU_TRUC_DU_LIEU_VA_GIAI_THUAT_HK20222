#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;
const ll INF = 1e18 + 7;
const int MAXN = 101;

int main() {
    int n, t;
    cin >> n >> t;
    int a[MAXN][MAXN];
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++) cin >> a[i][j];
    }
    ll dp[MAXN][MAXN][3];
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            for (int k = 0; k < 3; k++) dp[i][j][k] = INF;
        }
    }
    dp[1][1][0] = 0;
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, -1, 0, 1};
    priority_queue < pair <pair<ll, int>, pair<int, int>>, // {{Chi phí, Số bước mod 3}, {x, y}}
            vector < pair <pair<ll, int>, pair<int, int>> >,
                 greater<>> q;
    q.push({{0, 0}, {1, 1}});
    while (!q.empty()) {
        // Lấy trạng thái có chi phí nhỏ nhất
        auto cur = q.top(); q.pop();
        ll cost = cur.first.first;
        int mod = cur.first.second;
        int x = cur.second.first;
        int y = cur.second.second;
        if (cost > dp[x][y][mod]) continue;
        // Duyệt các đỉnh kề của trạng thái đó
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= n) {
                int nmod = (mod + 1) % 3;
                ll ncost = cost + t + (nmod == 0 ? a[nx][ny] : 0);
                if (ncost < dp[nx][ny][nmod]) {
                    dp[nx][ny][nmod] = ncost;
                    q.push({{ncost, nmod}, {nx, ny}});
                }
            }
        }
    }
    ll res = INF;
    for (int k = 0; k < 3; k++) res = min(res, dp[n][n][k]);
    cout << res << '\n';
}
