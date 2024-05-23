#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1001;
vector<int> graph[MAXN], reGraph[MAXN];
bool visited[MAXN];
stack<int> fStack;
vector<vector<int>> sccs;

void dfs1(int node) {
    visited[node] = true;
    for (int nei : graph[node]) {
        if (!visited[nei]) {
            dfs1(nei);
        }
    }
    fStack.push(node);
}

void dfs2(int node, vector<int>& currentScc) {
    visited[node] = true;
    currentScc.push_back(node);
    for (int nei : reGraph[node]) {
        if (!visited[nei]) {
            dfs2(nei, currentScc);  
        }
    }
}

int findSccs(int n) {
    
    memset(visited, false, sizeof(visited));
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            dfs1(i);
        }
    }

    
    memset(visited, false, sizeof(visited));
    while (!fStack.empty()) {
        int node = fStack.top();
        fStack.pop();
        if (!visited[node]) {
            vector<int> currentScc;
            dfs2(node, currentScc);  
            sccs.push_back(currentScc);
        }
    }

   
    int sccCount = sccs.size();
    vector<int> sccMap(n + 1, -1);
    for (int i = 0; i < sccCount; ++i) {
        for (int node : sccs[i]) {
            sccMap[node] = i;
        }
    }

    vector<int> inDegrees(sccCount, 0);
    for (int u = 1; u <= n; ++u) {
        for (int v : graph[u]) {
            if (sccMap[u] != sccMap[v]) {
                inDegrees[sccMap[v]]++;
            }
        }
    }

    int srCount = 0;
    for (int i = 0; i < sccCount; ++i) {
        if (inDegrees[i] == 0) {
            srCount++;
        }
    }

    return srCount;
}

int main() {
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        reGraph[v].push_back(u);
    }

    int result = findSccs(N);
    cout << result << endl;

    return 0;
}
