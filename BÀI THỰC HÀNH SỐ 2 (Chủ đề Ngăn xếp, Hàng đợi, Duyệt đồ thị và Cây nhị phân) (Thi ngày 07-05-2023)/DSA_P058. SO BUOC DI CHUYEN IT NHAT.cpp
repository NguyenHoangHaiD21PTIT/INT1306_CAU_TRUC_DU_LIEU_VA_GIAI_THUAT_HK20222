#include <bits/stdc++.h>
using namespace std;
int a[1005][1005], d[1005][1005], visited[1005][1005];//d[x][y] là số bước di chuyển ít nhất từ ô (0, 0) đễn (x, y)
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) cin >> a[i][j];
        }
        memset(d, 0, sizeof(d));
        memset(visited, 0, sizeof(visited));
        queue<pair<int, int>> q;
        q.push({0, 0});
        visited[0][0] = 1;
        d[0][0] = 0;
        int check = 0;
        while (!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            int i = p.first, j = p.second;
            if (i == n - 1 && j == m - 1) {
            	check = 1;
                cout << d[i][j] << endl;
                break;
            }
            int i1, j1, step;
            for (int k = 0; k < 3; k++) {
                if (k == 0 && j + 1 < m) {
                    step = abs(a[i][j] - a[i][j + 1]);
                    i1 = i;
                    j1 = j + step;
                } else if (k == 1 && i + 1 < n) {
                    step = abs(a[i][j] - a[i + 1][j]);
                    i1 = i + step;
                    j1 = j;
                } else if (k == 2 && i + 1 < n && j + 1 < m) {
                    step = abs(a[i][j] - a[i + 1][j + 1]);
                    i1 = i + step;
                    j1 = j + step;
                }
                if (i1 >= 0 && i1 < n && j1 >= 0 && j1 < m && visited[i1][j1] == 0) {
                    q.push({i1, j1});
                    d[i1][j1] = d[i][j] + 1;
                    visited[i1][j1] = 1;
                }
            }
        }
        if(!check) cout << -1 << endl;
    }
}
