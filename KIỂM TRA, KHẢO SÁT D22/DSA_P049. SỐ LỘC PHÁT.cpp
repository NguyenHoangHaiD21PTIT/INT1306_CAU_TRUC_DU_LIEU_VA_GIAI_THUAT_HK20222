#include <bits/stdc++.h>
using namespace std;
long long dem(long long n, int d) {
    long long res = 0;
    for (long long i = 1; i <= n; i *= 10) {
        long long l = n / (i * 10);
        long long m = (n / i) % 10;
        long long r = n % i;
        if (m < d) res += l * i;
        else if (m == d) res += l * i + r + 1;
        else res += (l + 1) * i;
    }
    return res;
}
int main() {
    vector<int> v;
    for (int i = 0; i < 1000; i += 8) v.push_back(i);
    int T; cin >> T;
    while (T--) {
        long long n; cin >> n;
        long long m = 1000, res = 0, du = n % m;
        long long ng = n / m;
        long long s = dem(ng - 1, 6) + dem(ng - 1, 8);
        for (int x : v) {
            int cnt = 0, t = x;
            while (t) {
                cnt += (t % 10 == 6 || t % 10 == 8);
                t /= 10;
            }
            res += cnt * ng + s;
        }
        int tmp = 0;
        long long t = ng;
        while (t) {
            tmp += (t % 10 == 6 || t % 10 == 8);
            t /= 10;
        }
        for (int i = 0; i <= du; i++) if (i % 8 == 0) {
            int cnt = 0, t = i;
            while (t) {
                cnt += (t % 10 == 6 || t % 10 == 8);
                t /= 10;
            }
            res += cnt + tmp;
        }
        cout << res << '\n';
    }
}
