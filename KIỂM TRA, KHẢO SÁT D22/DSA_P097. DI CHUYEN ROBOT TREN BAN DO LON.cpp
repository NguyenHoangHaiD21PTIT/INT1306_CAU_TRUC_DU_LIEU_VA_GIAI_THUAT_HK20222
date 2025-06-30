#include <bits/stdc++.h>
using namespace std;
struct Point {
    int x, y, step;
};
int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int BFS(int sx, int sy, int ex, int ey, set<pair<int, int>> marked_point) {
    queue<Point> q;
    q.push({sx, sy, 0});
    set<pair<int, int>> visited;
    visited.insert({sx, sy});
    while (!q.empty()) {
        Point current = q.front();
        q.pop();
        if (current.x == ex && current.y == ey) return current.step;
        for (int i = 0; i < 8; i++) {
            int ox = current.x + dx[i];
            int oy = current.y + dy[i];
            if (marked_point.find({ox, oy}) != marked_point.end() && visited.find({ox, oy}) == visited.end()) {
                visited.insert({ox, oy});
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
        set<pair<int, int>> marked_point;
        for (int i = 0; i < n; i++) {
            int x, y1, y2;
            cin >> x >> y1 >> y2;
            for (int y = y1; y <= y2; y++) marked_point.insert({x,y});
        }
		cout<<BFS(sx, sy, ex, ey, marked_point)<<endl;
    }
}
