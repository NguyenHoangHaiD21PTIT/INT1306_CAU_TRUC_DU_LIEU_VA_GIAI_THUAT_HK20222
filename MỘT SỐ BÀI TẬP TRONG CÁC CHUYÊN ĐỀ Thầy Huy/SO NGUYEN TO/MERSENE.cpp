#include <bits/stdc++.h>
using namespace std;

vector<bool> ByteSieve(int n) {
    vector<bool> b(n, true);
    b[0] = b[1] = false;
    for (int i = 4; i < n; i += 2) b[i] = false;
    for (int i = 3; i * i < n; i += 2) {
        if (b[i]) {
            for (int j = i * i; j < n; j += i) b[j] = false;
        }
    }
    return b;
}

// Tìm số lượng số nguyên tố Mersenne trong đoạn [a, b]
int Count(int a, int b) {
    vector<bool> primes = ByteSieve(b + 1);  // Sàng Eratosthenes cho đến b
    int count = 0;
    for (int n = 2; n <= b; ++n) {
        if (primes[n]) {
            long long p = (1LL << n) - 1;
            if (p > b) break;
            if (p >= a && primes[p]) count += 1;
        }
    }
    return count;
}

int main() {
    int a, b;
    cin >> a >> b;
    int result = Count(a, b);
    cout << result << endl;
    return 0;
}
