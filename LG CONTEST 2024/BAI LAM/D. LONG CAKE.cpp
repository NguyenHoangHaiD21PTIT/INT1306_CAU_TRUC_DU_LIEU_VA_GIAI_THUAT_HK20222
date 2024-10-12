#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7, MAX = 1000005;  
long long fac[MAX], ivFac[MAX];  

long long powMod(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b % 2 == 1) res = res * a % MOD;
        a = a * a % MOD;
        b /= 2;
    }
    return res;
}

void pre() {
    fac[0] = 1;
    for (long long i = 1; i < MAX; ++i) fac[i] = fac[i - 1] * i % MOD;
    ivFac[MAX - 1] = powMod(fac[MAX - 1], MOD - 2);  
    for (long long i = MAX - 2; i >= 0; --i) ivFac[i] = ivFac[i + 1] * (i + 1) % MOD;
}

long long C(long long n, long long k) {
    if (k < 0 || k > n) return 0;
    return fac[n] * ivFac[k] % MOD * ivFac[n - k] % MOD;
}

int sol(int n, int k, string A) {
    int cnt = 0;//số số 1
    for (char c : A) {
        if (c == '1') cnt++;
    }
    if (cnt % k != 0) return 0; 
    if (cnt == 0) return C(n - 1, k - 1);
    int step = cnt / k;//Số số 1 mỗi nhóm
    vector<int> pos; //Vị trí các số 1
    for (int i = 0; i < n; i++) {
        if (A[i] == '1') pos.push_back(i);
    }
    long long ways = 1;
    for (int i = 1; i <= k - 1; i++) {
        int gap = pos[i * step] - pos[(i * step) - 1];
        ways = (ways * gap) % MOD;
    }
    return ways;
}

int main() {
    pre();
    int t;
    cin >> t; 
    while (t--) {
        int n, k;
        cin >> n >> k;
        string A;
        cin >> A;
        cout << sol(n, k, A) << endl;
    }
}