#include <bits/stdc++.h>
using namespace std;

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

int main() {
    int N, M, Q;
    cin >> N >> M >> Q;
    vector<string> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    int cost[N][M];
    for(int i = 0;i<N;i++){
        for(int j = 0;j<M;j++) cost[i][j] = INT_MAX;
    }
    queue<pair<int, int>> q;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (a[i][j] == '*') {
                q.push({i, j});
                cost[i][j] = 0;
            }
        }
    }
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
                int newCost = cost[cur.first][cur.second] + (a[nx][ny] == a[cur.first][cur.second] ? 0 : 1);
                if (newCost < cost[nx][ny]) {
                    cost[nx][ny] = newCost;
                    q.push({nx, ny});
                }
            }
        }
    }
    while (Q--) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        cout << cost[x][y] << '\n';
    }
}
