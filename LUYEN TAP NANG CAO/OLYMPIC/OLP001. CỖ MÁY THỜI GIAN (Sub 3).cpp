#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 1005;

int n, Q, a[N], q[N], L, R;
ll f[N];

void run() {
    int u, v, k;
    cin >> u >> v >> k;
    u--; v--; 
    if (u == v) { 
        cout << a[u] << "\n"; 
        return; 
    }
    if (u > v) swap(u, v);
    L = 1; R = 0;
    f[u] = a[u];
    q[++R] = u; //Push back (Mở thêm 1 vị trí ở cuối, rồi cho nó vào)
    for (int i = u + 1; i <= v; ++i) {
        while (L <= R && q[L] < i - k) L++;     // Pop front
        f[i] = f[q[L]] + a[i];                  // q[L] = dq.front()
        while (L <= R && f[q[R]] >= f[i]) R--;  // Pop back
        q[++R] = i;                             // Push back
    }
    cout << f[v] << "\n";
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    string s;
    cin >> n >> Q >> s;
    for (int i = 0; i < n; ++i) a[i] = s[i] - '0';
    while (Q--) run();
}
