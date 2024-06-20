#include <bits/stdc++.h>
using namespace std;

int n, sx, sy, ex, ey;
char vs[500][500];

void BFS() {
    int f[505][505] = {};
    queue<pair<int, int>> q;
    q.push({sx, sy});

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while (!q.empty()) {
        pair<int, int> u = q.front();
        q.pop();
        if (u.first == ex && u.second == ey) {
            cout << f[ex][ey] << endl;
            return;
        }

        for (int k = 0; k < 4; ++k) {
            int ni = u.first + dx[k];
            int nj = u.second + dy[k];
            while (ni >= 0 && ni < n && nj >= 0 && nj < n && vs[ni][nj] != 'X') {
                if (!f[ni][nj]) { 
                    f[ni][nj] = f[u.first][u.second] + 1; 
                    q.push({ni, nj}); 
                }
                ni += dx[k];
                nj += dy[k];
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) cin >> vs[i][j];
        }
        cin >> sx >> sy >> ex >> ey;
        BFS();
    }
    return 0;
}
