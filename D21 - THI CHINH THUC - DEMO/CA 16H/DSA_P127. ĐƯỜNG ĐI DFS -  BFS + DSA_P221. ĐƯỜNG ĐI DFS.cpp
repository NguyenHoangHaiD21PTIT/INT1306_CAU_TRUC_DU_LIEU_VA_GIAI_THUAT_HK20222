#include <bits/stdc++.h>
using namespace std;

vector<int> ke[1005];
int visited[1005], truoc[1005];

void DFS(int x) {
    visited[x] = 1;
    for(int i: ke[x]) {
        if(!visited[i]) {
            truoc[i] = x;
            DFS(i);
        }
    }
}

void BFS(int x) {
    queue<int> q;
    q.push(x);
    visited[x] = 1;
    while(!q.empty()) {
        int p = q.front(); q.pop();
        for(int i: ke[p]) {
            if(!visited[i]) {
                visited[i] = 1;
                truoc[i] = p;
                q.push(i);
            }
        }
    }
}

void in_path(int start, int end, bool useDFS) {
    memset(visited, 0, sizeof(visited));
    memset(truoc, 0, sizeof(truoc));
    if(useDFS) DFS(start);
    else BFS(start);
    if(!visited[end]) {
        cout << "-1\n";
        return;
    }
    vector<int> path;
    int y = end;
    while(y != start) {
        path.push_back(y);
        y = truoc[y];
    }
    path.push_back(start);
    reverse(path.begin(), path.end());
    for(int v: path) cout << v << " ";
    cout << endl;
}

int main() {
    int dinh, canh;
    cin >> dinh >> canh;
    while(canh--) {
        int u, v;
        cin >> u >> v;
        ke[u].push_back(v);
        ke[v].push_back(u);
    }
    for(int i = 2; i <= dinh; i++) {
        in_path(1, i, true);  // DFS
        in_path(i, 1, false); // BFS
    }
}
