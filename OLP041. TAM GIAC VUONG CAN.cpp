#include <bits/stdc++.h>
using namespace std;

long long solve(int i, int j, int x, int y) {
    long long s = i - j;
    long long p = i + j;
    long long a = max(min(s + y, (long long)x) - max(s, (long long)0) + 1, (long long)0);
    long long b = max(min(p, (long long)y) - max(p - x, (long long)0) + 1, (long long)0);
    return a * b - 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int X, Y;
        cin >> X >> Y;
        long long ans = 0;
        int X_div2 = (X + 2) / 2;
        int Y_div2 = (Y + 1) / 2;
        for (int i = 0; i < X_div2; ++i) {
            for (int j = 0; j < Y_div2; ++j) ans += solve(i, j, X, Y) * 2;
            if (Y % 2 == 0) ans += solve(i, Y / 2, X, Y);
            if (i == (X - 1) / 2) ans *= 2;
        }
        cout << ans << endl;
    }
}
