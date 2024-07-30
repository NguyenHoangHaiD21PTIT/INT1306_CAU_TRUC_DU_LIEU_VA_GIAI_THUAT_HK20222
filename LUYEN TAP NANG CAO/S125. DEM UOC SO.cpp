#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000001;
int minPrime[MAX];
map<int, int>mp;

void sieve() {//Sàng
    for (int i = 2; i * i < MAX; ++i) {
        if (minPrime[i] == 0) {
            for (int j = i * i; j < MAX; j += i) {
                if (minPrime[j] == 0) minPrime[j] = i;
            }
        }
    }
    for (int i = 2; i < MAX; ++i) {
        if (minPrime[i] == 0) minPrime[i] = i;
    }
}

void pt(int n, int sign) {//Phân tích số n ra TSNT, sign: 1 là ++, -1:--
    while (n > 1) {
        int tmp = minPrime[n];
        mp[tmp] += sign;
        n /= tmp;
    }
}

long long cnt(int n, int k) {
    //n!/[k! * (n - k)!]: Tử số là tích từ k + 1 đến n, mẫu số là (n - k)!
    mp.clear();
    for (int i = k + 1; i <= n; ++i) pt(i, 1);
    for (int i = 2; i <= n - k; ++i) pt(i,-1);
    long long res = 1;
    for (auto p : mp) res *= (p.second + 1);
    return res;
}

int main() {
    sieve();
    int n, k;
    while (cin >> n >> k) cout << cnt(n, k) << endl;
    return 0;
}
