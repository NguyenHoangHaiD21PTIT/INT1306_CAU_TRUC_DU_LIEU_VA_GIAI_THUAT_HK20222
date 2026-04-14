#include<bits/stdc++.h>
using namespace std;   
using ll = long long;

int main(){
    int n; ll k;
    cin >> n >> k;
    vector<pair<ll, int>> p(n + 1); // p[i] = {prefix_sum[i], i}
    p[0] = {0, 0}; 
    ll s = 0; 
    for (int i = 1; i <= n; i++) {
        ll x; cin >> x;
        s += (x - k);
        p[i] = {s, i};
    }
    sort(p.begin(), p.end());
    int ans = 0, mi = p[0].second; //mi: Vị trí nhỏ nhất của prefix_sum đã duyệt qua
    for (int i = 1; i <= n; i++) {
        ans = max(ans, p[i].second - mi);
        mi = min(mi, p[i].second);
    }
    cout << ans;
}
/*Giả sử dãy con L đến R có TBC >= K. 
Ta có: (A[L] + A[L + 1] + ... + A[R]) / (R - L + 1) >= K. 
Nhân chéo ta có: A[L] + A[L + 1] + ... + A[R] >= K * (R - L + 1). 
Ta có thể viết lại như sau: (A[L] - K) + (A[L + 1] - K) + ... + (A[R] - K) >= 0. 
Như vậy, trừ mỗi phần tử cho K, bài toán trở thành tìm dãy con có tổng >= 0.
Gọi S[L] là tổng của dãy con từ 1 đến i sau khi đã trừ K.
Dãy con cần tìm từ L đến R cần thoả mãn 2 điều kiện:
- S[R] - S[L - 1] >= 0 <=> S[R] >= S[L - 1]
- R - L + 1 LỚN NHẤT
*/
/*
Tạo pair (S[i], i) và sắp xếp theo S[i] rồi sắp xếp theo i.
Điều này đảm bảo khi ta đang đứng tại 1 vị trí, thì mọi vị trí ta đã đi qua đều có giá trị S nhỏ hơn
mi chỉ ghi nhớ những index mà pre nhỏ hơn pre đang xét
*/
