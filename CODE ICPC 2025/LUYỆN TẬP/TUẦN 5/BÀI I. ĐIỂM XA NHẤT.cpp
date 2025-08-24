#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    vector<long long> X(n+1), Y(n+1);
    for (int i = 1; i <= n; i++) cin >> X[i] >> Y[i];
    for (int i = 1; i <= n; i++) {
        long long best = -1;
        int ans = -1;
        for (int j = 1; j <= n; j++) if (j != i) {
            long long dx = X[i] - X[j], dy = Y[i] - Y[j];
            long long d = dx * dx + dy * dy;
            if (d > best || (d == best && j < ans)) {
                best = d;
                ans = j;
            }
        }
        cout << ans << "\n";
    }
}
