#include <bits/stdc++.h>
using namespace std;

typedef tuple<int, int, int> State; // x, y, hướng (0: Ox, 1: Oy)

string makeKey(int x, int y, int dir) {
    return to_string(x) + "," + to_string(y) + "," + to_string(dir);
}

int main() {
    int n, xa, ya, xb, yb;
    cin >> n >> xa >> ya >> xb >> yb;
    //Lưu toạ độ các điểm
    unordered_map<int, vector<int>> row, col; // row[y]: chứa x, col[x]: chứa y
    set<pair<int, int>> mirrors;
    // Thêm điểm A và B vào danh sách gương để xử lý như các điểm bình thường
    mirrors.insert({xa, ya});
    mirrors.insert({xb, yb});
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        mirrors.insert({x, y});
    }
    for (auto [x, y] : mirrors) {
        row[y].push_back(x);
        col[x].push_back(y);
    }
    //Khởi tạo BFS
    queue<State> q;
    map<State, int> dist;
    // Bắt đầu BFS với cả 2 hướng
    q.push({xa, ya, 0});
    q.push({xa, ya, 1});
    dist[{xa, ya, 0}] = 0;
    dist[{xa, ya, 1}] = 0;
    //Lặp
    while (!q.empty()) {
        auto [x, y, dir] = q.front(); q.pop();
        int d = dist[{x, y, dir}];
        if (x == xb && y == yb) {
            cout << d << '\n';
            return 0;
        }
        if (dir == 0) { // Đi theo Ox (hoành độ thay đổi, tung độ giữ nguyên)
            for (int nx : row[y]) {
                if (nx == x) continue;
                State Straight = {nx, y, 0};//Muốn đi đến điểm khác giữ nguyên hướng thì cứ đi k cần gương
                if (!dist.count(Straight)) {
                    dist[Straight] = d;
                    q.push(Straight);
                }
                State turn = {nx, y, 1};
                if (!dist.count(turn)) {
                    dist[turn] = d + 1;
                    q.push(turn);
                }
            }
            row[y].clear();
        } else { // Đi theo Oy (tung độ thay đổi, hoành độ giữ nguyên)
            for (int ny : col[x]) {
                if (ny == y) continue;
                State goStraight = {x, ny, 1};
                if (!dist.count(goStraight)) {
                    dist[goStraight] = d;
                    q.push(goStraight);
                }
                State turn = {x, ny, 0};
                if (!dist.count(turn)) {
                    dist[turn] = d + 1;
                    q.push(turn);
                }
            }
            col[x].clear();
        }
    }
    cout << -1 << '\n';
    return 0;
}
