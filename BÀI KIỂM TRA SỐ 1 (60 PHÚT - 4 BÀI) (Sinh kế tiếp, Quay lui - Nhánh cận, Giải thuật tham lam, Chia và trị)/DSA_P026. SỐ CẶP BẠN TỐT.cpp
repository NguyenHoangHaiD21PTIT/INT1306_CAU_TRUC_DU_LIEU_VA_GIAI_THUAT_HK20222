#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ll n, k, ans = 0;
    cin >> n >> k;
    vector<string> s(n + 1);
    ll f[n + 1][30] = {};  //f[i][j]: Số lượng xâu con dài j tính từ đầu cho đến chỉ số i
    for (ll i = 1; i <= n; i++) {
        cin >> s[i];
        for (ll j = 0; j < 30; j++) f[i][j] = f[i - 1][j];  
        f[i][s[i].size()]++;  
    }
    for (int i = 1; i <= n; i++) {
        int length = s[i].size();
        ans += f[i - 1][length] - f[max(i - k - 1, 0LL)][length];
    }
    cout << ans;
}
