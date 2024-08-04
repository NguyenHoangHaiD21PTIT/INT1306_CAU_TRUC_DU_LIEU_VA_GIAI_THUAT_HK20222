#include <bits/stdc++.h>
using namespace std;
int main() {
    long long n, k;
    cin >> n >> k;
    long long a[n];
    unordered_map<long long, long long> mp;
    for (int i = 0; i < n; i++) cin >> a[i];
    long long tong = 0, cnt = 0;
    mp[0] = 1;
    for (int i = 0; i < n; i++) {
        tong += a[i];
        int mod = tong % k;
        if (mod < 0) mod += k;
        cnt += mp[mod];
        mp[mod]++;
    }
    cout << cnt << endl;
}