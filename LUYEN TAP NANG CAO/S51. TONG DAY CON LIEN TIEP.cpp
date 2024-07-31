#include <bits/stdc++.h>
using namespace std;

int canDiv(const vector<int>& a, int k) {
    int s = 0;
    for (int x : a) {
        s += x;
        if (s > k) return 0;
        if (s == k) s = 0;
    }
    return s == 0;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        int S = 0;
        for (int x : a) S += x;  
        int res = INT_MAX;  
        for (int i = 1; i <= sqrt(S); ++i) {
            if (S % i == 0) {
                if (canDiv(a, i)) res = min(res, i);
                if (canDiv(a, S / i)) res = min(res, S / i);
            }
        }
        cout << res << endl;
    }
}

