#include <bits/stdc++.h>
using namespace std;

bool checkCP(long long n) {
    long long r = sqrtl(n);
    return r * r == n;
}

int main() {
    long long a; cin >> a;
    long long S = 2 * a * a;
    for (long long b = 1; b * b <= S; ++b) {
        long long c2 = S - b * b;
        if (!checkCP(c2)) continue;
        long long c = sqrtl(c2);
        if (a != b && a != c && b != c && b <= 1e5 && c <=1e5) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
}
//Bài này rất nhiều bài nộp quên không check b và c có trong giới hạn 1e5 hay không nên bị sai
