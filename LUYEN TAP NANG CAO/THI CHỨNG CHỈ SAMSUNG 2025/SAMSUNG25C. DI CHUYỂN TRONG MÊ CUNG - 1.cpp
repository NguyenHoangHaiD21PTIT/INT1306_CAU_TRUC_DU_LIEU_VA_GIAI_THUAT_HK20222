#include <bits/stdc++.h>
using namespace std;
 
const int MAXN = 1000;
char maze[MAXN][MAXN];
int dist[MAXN][MAXN];
int N, M, s, t, u, v;
 
// 4 hướng: lên, xuống, trái, phải
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
 
// Kiểm tra ô hợp lệ
bool valid(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < M && maze[x][y] == '.';
}
 
int BFS() {
    queue<pair<int, int>> q;
    memset(dist, -1, sizeof(dist)); // -1 = chưa đến
    dist[s][t] = 0;
    q.push({s, t});
    while(!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        if(x == u && y == v) return dist[x][y]; // Đến đích
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(valid(nx, ny) && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    return -1; 
}
 
int main() {
    cin >> N >> M >> s >> t >> u >> v;
    s--; t--; u--; v--; 
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++) cin >> maze[i][j];
    }
    cout << BFS();
}
