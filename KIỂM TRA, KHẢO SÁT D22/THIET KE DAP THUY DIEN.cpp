#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 100005;
ll pos[MAXN], sum[MAXN], left_bound[MAXN], water[MAXN], h[MAXN];
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        ll n; scanf("%lld", &n);
        for (ll i = 1; i <= n; i++) scanf("%lld", &pos[i]);
        for (ll i = 1; i <= n; i++) {
            scanf("%lld", &h[i]); 
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
        scanf("%lld", &q);
        while (q--) {
            ll k;
            scanf("%lld", &k); 
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
            printf("%lld\n", res);
        }
    }
}
//https://luyencode.net/problem/ltc_2d
//Nguồn đề: Kỳ thi ICPC Khu vực năm 2016
