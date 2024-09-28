#include <bits/stdc++.h>
using namespace std;
const int N = 2e7 + 5, MOD = 1e9 + 7, BASE = 31;  

int n, m, res, hs, h[N]; 
string s1; 
long long Pow[N]; 

signed main() {
    cin >> n >> m >> s1;
    int y = (int)s1.size();
    res = 0;
    for (char x : s1) hs = (hs * BASE + (x - '0')) % MOD;//Tìm hash xâu cần tìm vị trí
    Pow[0] = 1; 
    for (int i = 1; i <= y; ++i) Pow[i] = (Pow[i - 1] * BASE) % MOD;
    int ans = n / m;
    int du = n % m;
    //Ta tìm vị trí xâu con trong phần nguyên trước
    vector<int> a;
    if (ans == 0) a.push_back(0);
    while (ans > 0) {
        a.push_back(ans % 10);
        ans /= 10;
    }
    reverse(a.begin(), a.end());
    h[0] = a[0];
    for (int i = 1; i < a.size(); i++){
        h[i] = (h[i - 1] * BASE + a[i]) % MOD;
        if (i >= y - 1) { 
            int hash_sub = h[i]; // i: cuối, dài y, i - đầu + 1 = y --> đầu = i + 1 - y
            if (i >= y) hash_sub = (hash_sub - (h[i - y] * Pow[y]) + MOD) % MOD; 
            if (hash_sub == hs) {
                res = i - y + 1;
                break;
            }
        }
    }
    //Bây giờ thì tìm trong: Phần dư
    int x = a.size() - 1;
    while (!res && x < N) {
        a.push_back(du * 10 / m);  
        du = du * 10 % m;  
        x++;
        h[x] = (h[x - 1] * BASE + a[x]) % MOD;  
        if (x >= y - 1) {
            int hash_sub = h[x];
            if (x >= y) hash_sub = (hash_sub - (h[x - y] * Pow[y]) + MOD) % MOD; 
            if (hash_sub == hs) {
                res = x - y + 1;
                break;
            }
        }
    }
    cout << res + 1 << endl;
}
