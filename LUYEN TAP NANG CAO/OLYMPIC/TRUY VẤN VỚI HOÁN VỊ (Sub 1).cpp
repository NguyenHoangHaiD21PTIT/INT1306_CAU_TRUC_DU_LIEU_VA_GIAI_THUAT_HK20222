#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, q, x; cin >> n >> q >> x;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    while (q--) {
        int type, l, r;
        cin >> type >> l >> r;
        l--; r--; 
        if (type == 1) sort(a.begin() + l, a.begin() + r + 1);
        else sort(a.begin() + l, a.begin() + r + 1, greater<int>());
    }
    for (int i = 0; i < n; ++i) {
        if (a[i] == x) {
            cout << i + 1 << endl;
            return 0;
        }
    }
}
