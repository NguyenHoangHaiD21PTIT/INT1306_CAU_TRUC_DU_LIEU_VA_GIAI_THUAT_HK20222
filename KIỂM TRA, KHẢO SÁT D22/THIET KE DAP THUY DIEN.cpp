#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 100005;
ll pos[MAXN], sum[MAXN], left_bound[MAXN], water[MAXN], h[MAXN];
int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n; cin >> n;
        for (ll i = 1; i <= n; i++) cin >> pos[i];
        for (ll i = 1; i <= n; i++) {
            cin >> h[i];
            sum[i] = sum[i - 1] + h[i];
        }
        stack<ll> st;
        st.push(0); 
	//Tìm vị trí bức tường cao hơn bên trái tường đang xét
        for (ll i = 1; i <= n; i++) {
            while (!st.empty() && h[st.top()] <= h[i]) st.pop();
            if (st.empty()) left_bound[i] = 0;
            else left_bound[i] = st.top();
            st.push(i);
        }
        h[0] = 1000111000;
        pos[0] = -1;
	//Tổng lượng nước đến bức tường đang xét = Tổng lượng nước từ đầu đến bức tường cao hơn nó + tổng lượng nước từ tường đang xét đến bức tường cuối cùng <= tường đang xét (đã trừ đi tổng chiều cao các cột từ u+1 -->i 
	//						              water[u]                     +        (u + 1 ->i) * h[i]                                                             sum[i] - sum[u]
        for (ll i = 1; i <= n; i++) {
            ll u = left_bound[i];
            water[i] = water[u] + (pos[i] - pos[u]) * h[i] - (sum[i] - sum[u]);
        }
        ll q;
        cin >> q;
        while (q--) {
            ll k;
            cin >> k;
            ll l = 0, r = n, res = 0;
            while (l <= r) {
                ll mid = (l + r) / 2;
                if (water[mid] < k) {
                    res = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            cout << res << endl;
        }
    }
}
//https://luyencode.net/problem/ltc_2d
//Nguồn đề: Kỳ thi ICPC Khu vực năm 2016
