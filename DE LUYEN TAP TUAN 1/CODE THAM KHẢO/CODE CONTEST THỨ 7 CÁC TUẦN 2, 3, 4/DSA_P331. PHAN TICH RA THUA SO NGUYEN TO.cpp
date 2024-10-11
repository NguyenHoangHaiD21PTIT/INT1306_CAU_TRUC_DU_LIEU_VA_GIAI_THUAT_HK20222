#include <bits/stdc++.h>
using namespace std;

#define ll long long
vector<ll> primes;

void sieve() {
    const int MAX = 1e7;
    vector<bool> isPrime(MAX + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (ll i = 2; i * i <= MAX; i++) {
        if (isPrime[i]) {
            for (ll j = i * i; j <= MAX; j += i) isPrime[j] = false;
        }
    }
    for (ll i = 2; i <= MAX; i++) {
        if (isPrime[i]) primes.push_back(i);
    }
}

int main() {
    sieve();
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        for (ll p : primes) {
            if (p * p > n) break;
            if (n % p == 0) {
                int count = 0;
                while (n % p == 0) {
                    count++;
                    n /= p;
                }
                cout << p << " " << count << endl;
            }
        }
        if (n > 1) cout << n << " " << 1 << endl; 
        cout<<endl;
    }
}
