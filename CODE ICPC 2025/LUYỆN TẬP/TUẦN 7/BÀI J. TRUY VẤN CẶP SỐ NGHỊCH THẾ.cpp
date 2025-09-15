#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MAXN = 300005;
int n, a[MAXN];
ll bit[MAXN];

void upd(int x, ll v) {
    while (x <= n + 1) {
        bit[x] += v;
        x += x & -x;
    }
}

ll sum(int x) {
    ll res = 0;
    while (x > 0) {
        res += bit[x];
        x -= x & -x;
    }
    return res;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    ll inv = 0;
    for (int i = 0; i < n; i++) {
        ll le = sum(a[i] + 1);   // số phần tử <= a[i] đã thấy, tức là số lần xuất hiện của 0, 1, ..., a[i] - 1 trước đó = X
        inv += i - le;           // Từ 0 đến trước a[i] là: 0, 1, ..., i - 1 nên có i số → số phần tử > a[i] = i - X → nghịch thế
        upd(a[i] + 1, 1);
    }
    ll cur = inv;
    cout << cur << "\n";
    for (int k = 0; k < n - 1; k++) {
        cur += n - 1 - 2LL * a[k];
        cout << cur << "\n";
    }
}
/*Giả sử hoán vị x (Các số còn lại từ 0 đến N - 1 và khác x, gọi là tập Q)
Các số khác x thì có đúng x số nhỏ hơn x: Từ 0 đến x - 1
Các còn lại của tập Q là các số > x và khác x: Từ x + 1 đến N - 1: (N - 1) - (x + 1) + 1 = N - x - 1
Trước khi bị đảo, x đứng đầu, x tạo ra đúng x nghịch thế với x số bé hơn nó
Sau khi x bị đẩy về cuối: Dãy có dạng: Tập Q ... x, x lại tạo nghịch thế với đúng N - x - 1 số lớn hơn nó
Như vậy, số cặp sau hơn trước là: N - x - 1 - x = N - 1 - 2x
*/