#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000;

char a[MAXN][MAXN];
int d[MAXN][MAXN];
int N, M, sx, sy, tx, ty;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool ok(int x, int y) {
    return (0 <= x && x < N && 0 <= y && y < M && a[x][y] == '.');
}

int go() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) d[i][j] = INT_MAX;
    }
    using P = pair<int, pair<int,int>>;
    priority_queue<P, vector<P>, greater<>> pq;
    d[sx][sy] = 0;
    pq.push({0, {sx, sy}});
    while (!pq.empty()) {
        auto [w, pos] = pq.top(); 
        pq.pop();
        int x = pos.first, y = pos.second;
        if (w > d[x][y]) continue;
        if (x == tx && y == ty) return w;
        // đi 4 hướng
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (ok(nx, ny) && d[nx][ny] > w + 1) {
                d[nx][ny] = w + 1;
                pq.push({d[nx][ny], {nx, ny}});
            }
        }
        // nhảy trong ô 5x5
        for (int xx = -2; xx <= 2; xx++) {
            for (int yy = -2; yy <= 2; yy++) {
                int nx = x + xx, ny = y + yy;
                if (!ok(nx, ny)) continue;
                if (abs(xx) + abs(yy) <= 1) continue;
                if (d[nx][ny] > w + 2) {
                    d[nx][ny] = w + 2;
                    pq.push({d[nx][ny], {nx, ny}});
                }
            }
        }
    }
    return -1; 
}

int main() {
    cin >> N >> M;
    cin >> sx >> sy >> tx >> ty;
    sx--, sy--, tx--, ty--; 
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) cin >> a[i][j];
    }
    cout << go();
}
