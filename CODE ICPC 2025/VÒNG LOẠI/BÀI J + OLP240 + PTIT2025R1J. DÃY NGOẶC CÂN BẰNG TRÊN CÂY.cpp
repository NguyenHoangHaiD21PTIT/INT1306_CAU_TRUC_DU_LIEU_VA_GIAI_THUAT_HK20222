#include <bits/stdc++.h>
using namespace std;

const int N = 5005;

string s;
vector<int> adj[N];//Danh sách kề
map<char, char> op, cl; 
stack<char> st;
long long ans = 0;

void dfs(int u, int p = 0) {
    if (op.count(s[u])) st.push(s[u]);
    else {
        if (st.empty() || st.top() != cl[s[u]]) return;
        st.pop();
        if (st.empty()) ++ans;
    }
    for (int v: adj[u]){
        if (v != p) dfs(v, u);
    }
    if (op.count(s[u])) st.pop();
    else st.push(cl[s[u]]);
}

int main() {
    int n;
    cin >> n >> s;
    s = " " + s;
    for (int i = 2; i <= n; ++i) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    op['('] = ')'; op['['] = ']'; op['{'] = '}';
    cl[')'] = '('; cl[']'] = '['; cl['}'] = '{';
    for (int i = 1; i <= n; ++i) dfs(i);
    cout << ans;
}
