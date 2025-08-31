#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll mod(ll x, ll k) {
    return (x % k + k) % k;
}
int main() {
    int n; ll k;
    cin >> n >> k;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<ll> key(n + 1);       // key[i] = (prefix(i) - i) mod k
    unordered_map<ll, ll> cnt;   // Có bao nhiêu chỉ số trước đó cũng tạo ra key
    // Ta cần tìm số đoạn con (l..r) thỏa: (sum[l..r]) % K = (r - l + 1)
    // ⇔ (pre[r] - pre[l-1]) % K = (r - l + 1)
    // ⇔ (pre[r] - r) % K = (pre[l-1] - (l-1)) % K
    // Đặt key[i] = (pre[i] - i) mod K → 2 đoạn con có cùng key sẽ tạo thành 1 đáp án
    // Nói cách khác, với mỗi r ta đang xét, ta sẽ phải xem trước đó có bao nhiêu index l < r mà cùng key
    //
    // Một số mod K chỉ có thể ra 1 số nhỏ hơn K mà thôi --> r - l + 1 < K
    // → Do đó, chỉ xét các đoạn con có độ dài < K.
    ll pre = 0, ans = 0; //pre: Tổng đến chỉ số thứ i
    key[0] = 0;  //Trước a[1] thì làm gì có phần tử nào
    cnt[key[0]] = 1;
    for (int i = 1; i <= n; i++) {
        pre += a[i];
        // Giữ độ dài < k: len = i - j + 1 < k  ⇒  j > i - k + 1
        // Chỉ số nguyên → j_min = i - k + 2
        // → loại chỉ số cũ j = i - k + 1 (nếu tồn tại, tức i - k + 1 ≥ 1 hay i - k >= 0)
        if (i - (ll)k >= 0) {
            ll old = key[i - k];
            auto it = cnt.find(old);
            if (it != cnt.end()) {
                it->second--;
                if (!it->second) cnt.erase(it);
            }
        }
        //Tổng hiện tại là pre, index hiện tại là i, vậy thì key[i] (đang xét) = (pre - i) mod K = cur
        //Ta xem trước j có bao nhiêu index cùng key, lấy từ mảng cnt[cur]
        //Xong rồi thì lưu key tương ứng để tí nữa cần loại do out of idex thì ..
        ll cur = mod(pre - i, k);
        ans += cnt[cur];
        key[i] = cur;
        cnt[cur]++;
    }
    cout << ans;
}
