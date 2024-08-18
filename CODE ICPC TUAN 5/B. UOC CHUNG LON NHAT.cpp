#include <bits/stdc++.h>
using namespace std;
int main() {
    long long N, M;
    cin >> N >> M;
    long long res = 1;
    for (long long d = 1; d * d <= M; d++) {
        if (M % d == 0) {
            if (d * N <= M) res = max(res, d);
            if ((M / d) * N <= M) res = max(res, M / d);
        }
    }
    cout << res;
}
/*Gọi d là UCLN của dãy số --> a1+a2+ ...+ an = d*b1 + d*b2 + ... + d*bn = M ->d(b1 + b2+... + bn) = M
Như vậy, thì d là ước của M. Mặt khác, b1, b2, ..., bn tất cả đều >=1. Do đó nên tổng này tối thiểu phải >=N.
Khi chọn d là UCLN thì tổng này là M/d. Vậy, M/d>=n--> d*n<=m
*/
