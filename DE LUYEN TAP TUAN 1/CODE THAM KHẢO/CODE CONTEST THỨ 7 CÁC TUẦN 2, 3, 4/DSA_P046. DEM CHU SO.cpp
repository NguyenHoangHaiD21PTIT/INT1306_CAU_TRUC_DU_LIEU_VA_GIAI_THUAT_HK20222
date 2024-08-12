#include <bits/stdc++.h>
using namespace std;

long long f(int x, long long n) {
    long long ret = 0;
    for (int i = 0; ; ++i) {
        long long m = pow(10, i);
        if (m > n) break;
        long long a = n / m;
        long long b = n % m;
        int z = a % 10;
        if (z > x) ret += ((a / 10) + 1) * m;
        else if (z == x) ret += (a / 10) * m + (b + 1);
        else ret += (a / 10) * m;
        if (x == 0) ret -= m;
    }
    return ret;
}

long long digitsCount(int d, long long low, long long high) {
    return f(d, high) - f(d, low - 1);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long a, b;
        cin >> a >> b;
        for (int i = 0; i < 10; ++i) cout << digitsCount(i, a, b) << " ";
        cout << endl;
    }
}
