#include <bits/stdc++.h>
using namespace std;
int n, st, en, u, d;
int visited[1000006];

int BFS() {
    if (st == en) return 0;
    queue<pair<int, int>>q;
    q.push({st, 0});
    visited[st] = true;
    while (!q.empty()) {
        int curFl = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if(curFl==en) return cnt;
        int nextFl = curFl + u;
        if (nextFl <= n && !visited[nextFl]) {
            q.push({nextFl, cnt + 1});
            visited[nextFl];
        }
        nextFl = curFl - d;
        if (nextFl >= 1 && !visited[nextFl]) {
            q.push({nextFl, cnt + 1});
            visited[nextFl];
        }
    }
    return -1;
}

int main() {
    cin>>n>>st>>en>>u>>d;
    cout<<BFS();
}
