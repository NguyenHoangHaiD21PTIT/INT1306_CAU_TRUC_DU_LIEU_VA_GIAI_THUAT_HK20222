#include <bits/stdc++.h>
using namespace std;
 
int par[200005], sze[200005];
vector<int> ke[200005];
bool present[200005];
string result[200005];
 
int find(int x) {
    if (x == par[x]) return x;
    return par[x] = find(par[x]);
}
 
bool Union(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return false;
    if (sze[x] < sze[y]) swap(x, y);
    par[y] = x;
    sze[x] += sze[y];
    return true;
}
 
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        par[i] = i;
        sze[i] = 1;
    }
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        ke[u].push_back(v);
        ke[v].push_back(u);
    }
    vector<int> P(n);
    for (int i = 0; i < n; ++i) cin >> P[i];
    int components = 0;//số thành phần liên thông
    vector<bool> is_present(n + 1, false);
    //Chúng ta sẽ làm ngược lại: Thêm dần từng đỉnh từ cuối về
    for (int i = n - 1; i >= 0; --i) {
        int u = P[i];
        is_present[u] = true;//đã thêm vào
        components++;
        for (int v : ke[u]) {
            if (is_present[v]) {
                if (find(u) != find(v)) {
                    Union(u, v); 
                    components--;
                }
            }
        }
        if(component==1) result[i]=="YES";
        else result[i]=="NO";
    }
    for (int i = 0; i < n; ++i) cout << result[i] << "\n";
}
