#include <bits/stdc++.h>
using namespace std;
int n, st, en, u, d;
vector<bool> visited; // Khởi tạo vector bool
int BFS() {
    if (st == en) return 0;
    queue<pair<int, int>> q;
    q.push({st, 0});
    visited[st] = true;
    while (!q.empty()) {
        int curFl = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if (curFl == en) return cnt;
        int nextFl = curFl + u;
        if (nextFl <= n && !visited[nextFl]) {
            q.push({nextFl, cnt + 1});
            visited[nextFl] = true; 
        }
        nextFl = curFl - d;
        if (nextFl >= 1 && !visited[nextFl]) { 
            q.push({nextFl, cnt + 1});
            visited[nextFl] = true; 
        }
    }
    return -1;
}
int main() {
    cin >> n >> st >> en >> u >> d;
    visited.resize(n + 1, false); // Khởi tạo vector với kích thước n+1 và tất cả giá trị là false
    cout << BFS();
    return 0;
}
