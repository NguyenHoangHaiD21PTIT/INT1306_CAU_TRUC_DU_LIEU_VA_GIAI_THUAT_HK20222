#include <bits/stdc++.h>
using namespace std;

int bs(vector<int> a, int n, int x) {
    int l = 0, r = n - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (a[mid] == x) return mid;
        else if (a[mid] < x) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n, x; cin >> n >> x;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        int res = bs(a, n, x);
        if (res == -1) cout << "NO\n";
        else cout << res + 1 << "\n";
    }
}
