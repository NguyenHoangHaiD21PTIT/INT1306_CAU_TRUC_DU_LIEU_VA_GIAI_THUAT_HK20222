#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7; 
map<int, int> mp;

void pt(int n) {
    for (int i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            mp[i]++;
            n /= i;
        }
    }
    if (n > 1) mp[n]++;
}

int main() {
    int n; cin >> n;
    for (int i = 2; i <= n; ++i) pt(i);
    long long res = 1;
    for (auto p: mp) res = (res * (p.second + 1)) % MOD; 
    cout << res;
}