#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y, step;
};

// Mảng dx và dy mô tả 8 hướng di chuyển
int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

// Chuyển Point thành string để dùng làm key
string pointToString(int x, int y) {
    return to_string(x) + "," + to_string(y);
}

int BFS(int sx, int sy, int ex, int ey, unordered_set<string> &marked_point) {
    queue<Point> q;
    q.push({sx, sy, 0});
    unordered_set<string> visited;
    visited.insert(pointToString(sx, sy));

    while (!q.empty()) {
        Point current = q.front();
        q.pop();
        if (current.x == ex && current.y == ey) return current.step;

        for (int i = 0; i < 8; i++) {
            int ox = current.x + dx[i];
            int oy = current.y + dy[i];
            string new_point = pointToString(ox, oy);
            if (marked_point.find(new_point) != marked_point.end() && visited.find(new_point) == visited.end()) {
                visited.insert(new_point);
                q.push({ox, oy, current.step + 1});
            }
        }
    }
    return -1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;
        int n;
        cin >> n;
        unordered_set<string> marked_point;
        for (int i = 0; i < n; i++) {
            int x, y1, y2;
            cin >> x >> y1 >> y2;
            for (int y = y1; y <= y2; y++) marked_point.insert(pointToString(x, y));
        }

        if (marked_point.find(pointToString(sx, sy)) == marked_point.end() || marked_point.find(pointToString(ex, ey)) == marked_point.end()) {
            cout << -1 << endl;
        } else {
            int result = BFS(sx, sy, ex, ey, marked_point);
            cout << result << endl;
        }
    }
    return 0;
}
