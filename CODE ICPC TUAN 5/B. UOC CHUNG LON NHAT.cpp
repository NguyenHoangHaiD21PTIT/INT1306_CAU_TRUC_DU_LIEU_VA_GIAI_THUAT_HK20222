#include <bits/stdc++.h>
using namespace std;
int main() {
    long long N, M;
    cin >> N >> M;
    long long res = 1;
    for (long long d = 1; d * d <= M; d++) {
        if (M % d == 0) {
            if (d * N <= M) res = max(res, d);
            if ((M / d) * N <= M) res = max(res, M / d);
        }
    }
    cout << res;
}
