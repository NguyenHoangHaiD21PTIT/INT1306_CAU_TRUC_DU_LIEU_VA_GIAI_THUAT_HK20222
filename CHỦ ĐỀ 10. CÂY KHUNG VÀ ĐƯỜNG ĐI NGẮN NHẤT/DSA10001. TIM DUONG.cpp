#include <bits/stdc++.h>
using namespace std;

int n, m;
char vs[500][500];
bool check;

void BFS() {
    pair<int, int> s; // Vị trí bắt đầu
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (vs[i][j] == 'S') s = {i, j};
        }
    }

    // Khởi tạo mảng đếm số bước di chuyển ít nhất đến từng ô
    int f[505][505] = {};
    queue<pair<int, int>> q;
    q.push(s);

    // Các hướng di chuyển: lên, xuống, trái, phải
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while (!q.empty()) {
        pair<int, int> u = q.front();
        q.pop();
        if (f[u.first][u.second] > 2) continue;

        // Xử lý từng hướng di chuyển
        for (int k = 0; k < 4; ++k) {
            int ni = u.first + dx[k];
            int nj = u.second + dy[k];

            while (ni >= 0 && ni < n && nj >= 0 && nj < m && vs[ni][nj] != '*') {
                if (vs[ni][nj] == 'T') { // Nếu gặp đích 'T' thì in ra YES và kết thúc
                    check = true;
                    return;
                } else if (!f[ni][nj]) { // Nếu ô chưa được duyệt
                    f[ni][nj] = f[u.first][u.second] + 1; // Cập nhật số bước đi
                    q.push({ni, nj}); // Thêm ô vào hàng đợi
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
        cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) cin >> vs[i][j];
        }
        check = false;
        BFS();
        if (check) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
