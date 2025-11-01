#include <bits/stdc++.h> // Gộp tất cả thư viện
using namespace std;

void solve() {
    string a; cin >> a;
    int n = a.length();
    string b = a, c = a; 
    char mx = *max_element(a.begin(), a.end());
    int idf = -1; // idx_front
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] == mx) {
            idf = i;
            break;
        }
    }
    if (idf != -1) b = a[idf] + a.substr(0, idf) + a.substr(idf + 1);
    int idb = -1; 
    for (int i = 0; i < n - 1; i++) {
        if (a[i] < a[i + 1]) {
            idb = i;
            break;
        }
    }
    if (idb != -1) c = a.substr(0, idb) + a.substr(idb + 1) + a[idb];
    cout << max({a, b, c});
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
        cout << '\n';
    }
    return 0;
}
