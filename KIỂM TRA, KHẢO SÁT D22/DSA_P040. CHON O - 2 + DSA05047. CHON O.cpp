#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll oo = 1e18 + 7;
int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        ll a[5][10005]; // 4 hàng, n cột
        for (int i = 0; i < 4; i++) {
            for (int j = 1; j <= n; j++) cin >> a[i][j];
        }
        ll f[10005][16] = {}; //max khi xét đến cột i và trạng thái mask
        bool d[16] = {}; //Trạng thái cột
        for (ll mask = 0; mask < 16; mask++) {
            d[mask] = true;
            for (ll j = 0; j < 3; j++){
                if ((mask >> j) & 1 && (mask >> (j + 1)) & 1) d[mask] = false;
                //Nó và ô dưới nó cùng có thì sai
            }
        }
        // Tính giá trị f[i][mask] cho mỗi cột
        for (ll i = 1; i <= n; i++) {
            for (ll mask = 0; mask < 16; mask++) {
                if (d[mask]) {//Trạng thái cột hợp lệ
                    ll sum = 0;
                    for (ll j = 0; j < 4; j++){
                        if ((mask >> j) & 1) sum += a[j][i];
                    }
                    for (ll pre_mask = 0; pre_mask < 16; pre_mask++) {
                        if (d[pre_mask] && ((pre_mask & mask) == 0)) {
                            f[i][mask] = max(f[i][mask], f[i - 1][pre_mask] + sum);
                        }
                    }
                }
            }
        }
        ll res = *max_element(f[n], f[n] + 16);
        if (!res) {
            res = -oo;
            for (ll i = 0; i < 4; i++){
                for (ll j = 1; j <= n; j++) res = max(res, a[i][j]);
            }
        }
        cout << res << '\n';
    }
}
