#include <bits/stdc++.h>
using namespace std;

int n, k, m;
vector<pair<pair<int, int>, pair<int, int>>> raoChan(m); // Rào chắn
int tplt[105][105] = {}; // tplt[i][j] = k tức là ô (i, j) thuộc thành phần liên thông thứ k
int soTplt = 0; // Số thành phần liên thông
vector<pair<int, int>> cuu(k); // Tọa độ của các chú cừu
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

// Kiểm tra xem ô (u, v) có thể duyệt sang được ô (x, y) hay không
bool diChuyenDuoc(int u, int v, int x, int y) {
    if (x < 1 || x > n || y < 1 || y > n || tplt[x][y]) return false;
    for (auto rao : raoChan) {
        pair<int, int> x1 = rao.first, x2 = rao.second, x3 = {u, v}, x4 = {x, y};
        if ((x1 == x3 && x2 == x4) || (x1 == x4 && x2 == x3)) return false;
    }
    return true;
}

// Hàm BFS để duyệt các ô liên thông
void BFS(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    tplt[x][y] = soTplt;

    while (!q.empty()) {
        //auto [cx, cy] = q.front(); q.pop();
        pair<int, int>p = q.front(); 
        q.pop();
        int cx = p.first, cy = p.second;
        for (int i = 0; i < 4; ++i) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (diChuyenDuoc(cx, cy, nx, ny)) {
                tplt[nx][ny] = soTplt;
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    cin >> n >> k >> m;
    raoChan.resize(m);
    cuu.resize(k);
    //Các cặp rào chắn
    for (int i = 0; i < m; ++i) {
        int u, v, x, y;
        cin >> u >> v >> x >> y;
        raoChan[i] = {{u, v}, {x, y}};
    }
    //Toạ độ các con cừu
    for (int i = 0; i < k; ++i) {
        int x, y;
        cin >> x >> y;
        cuu[i] = {x, y};
    }
    //Xem mỗi con cừu thuộc thành phần liên thông nào
    for (auto c : cuu) {
        int x = c.first, y = c.second;
        if (!tplt[x][y]) {
            soTplt++;
            BFS(x, y);
        }
    }
    // Đếm số lượng cừu trong mỗi thành phần liên thông
    int demCuu[soTplt + 5] = {};//demCuu[i] = x tức là thành phần liên thông thứ i có x con cừu
    for (auto c : cuu) {
        int STT_TPLT = tplt[c.first][c.second];//Lấy số thứ tự thành phần liên thông của con cừu đó
        demCuu[STT_TPLT]++;//Tăng số chú cừu ở thành phần liên thông ấy lên
    }
    // Tính số cặp cừu xa cách
    long long ketQua = 0;
    for (int i = 1; i <= soTplt; ++i) {
        for (int j = i + 1; j <= soTplt; ++j) ketQua += (long long)demCuu[i] * demCuu[j];
    }
    cout << ketQua;
}
