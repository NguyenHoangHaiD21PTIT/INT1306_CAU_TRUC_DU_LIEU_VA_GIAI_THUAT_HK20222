#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000001, MOD = 1000000007;
int minPrime[MAX]; 
map<int, int> mp; 

void sieve() {
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

void pt(int n) {
    while (n > 1) {
        int tmp = minPrime[n];
        int soMu = 0;
        while (n % tmp == 0) {
            soMu++;
            n /= tmp;
        }
        mp[tmp] = max(mp[tmp], soMu);
    }
}

int main() {
    sieve(); 
    int t;
    cin >> t; 
    while (t--) {
        int n;
        cin >> n; 
        mp.clear(); 
        for (int i = 1; i <= n; ++i) pt(i);
        long long res = 1;
        for(auto it: mp) res = (res * (it.second + 1)) % MOD;
        cout << res << endl;
    }
}
