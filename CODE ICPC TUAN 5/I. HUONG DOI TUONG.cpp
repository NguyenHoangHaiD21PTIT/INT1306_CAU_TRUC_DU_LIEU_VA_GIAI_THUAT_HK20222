#include <bits/stdc++.h>
using namespace std;

unordered_map<string, vector<string>> isa, has;
unordered_map<string, unordered_map<string, bool>> mem_isa, mem_has;

bool isa_check(const string& a, const string& b) {
    if (a == b) return true;
    if (mem_isa[a].count(b)) return mem_isa[a][b];

    unordered_set<string> vis;
    stack<string> st;
    st.push(a);

    while (!st.empty()) {
        string u = st.top(); st.pop();
        if (!vis.insert(u).second) continue;
        for (const auto& v : isa[u]) {
            if (v == b) return mem_isa[a][b] = true;
            st.push(v);
        }
    }

    return mem_isa[a][b] = false;
}

bool has_check(const string& a, const string& b) {
    if (mem_has[a].count(b)) return mem_has[a][b];

    unordered_set<string> vis;
    stack<string> st;
    st.push(a);

    while (!st.empty()) {
        string u = st.top(); st.pop();
        if (!vis.insert(u).second) continue;

        for (const auto& v : has[u]) {
            if (v == b || isa_check(v, b)) return mem_has[a][b] = true;
            st.push(v);
        }

        for (const auto& v : isa[u]) {
            st.push(v);
        }
    }

    return mem_has[a][b] = false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    while (n--) {
        string x, r, y;
        cin >> x >> r >> y;
        if (r == "is-a") isa[x].push_back(y);
        else has[x].push_back(y);
    }

    for (int i = 1; i <= m; ++i) {
        string x, r, y;
        cin >> x >> r >> y;
        bool res = (r == "is-a") ? isa_check(x, y) : has_check(x, y);
        cout << "Query " << i << ": " << (res ? "true" : "false") << endl;
    }

    return 0;
}
