#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[200005], pre[200005];
int main(){
    ll n; cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];
    ll res = 0;
    for(int i = 1; i < n; i++) res += (pre[n] - pre[i]) - a[i] * (n - i);
    cout << res;
}
/*Đề yêu cầu tính: Tổng mọi cặp |A[i] - A[j]| với i < j
Ngây thơ: Duyệt 2 for, 1 for i từ 1 đến n - 1, for j từ i + 1 đến N rồi làm. ĐPT O(N^2) --> TLE
Suy nghĩ:
- Ta có thể vứt dấu trị tuyệt đối đi bằng cách lấy số to trừ số bé. Và thích chọn cặp (i, j) nào trước chẳng được. Miễn là chọn đủ
- Vì vậy, ta sắp xếp tăng mảng A, dùng hàm sort trong C++, ĐPT (log2(N))
- Nhận xét quy luật. Giả sử ta có dãy a1 a2 a3 a4 a5
+) a1: a2 - a1 + a3 - a1 + a4 - a1 + ... + a5 - a1 = (a2 + ... + a5) - a1 * 4
+) a2: a3 - a2 + a4 - a2 + a5 - a2 = (a3 + a4 + a5) - a1 * 3
Tổng quát: Với mỗi ai, tính: (a[i + 1] + a[i + 2] + ... + a[n]) - a[i] * Số số hạng từ (i + 1 đến n)
Từ n đến i + 1 có: n - (i + 1) + 1 = n - i số
Gọi pre[i] = a[1] + a[2] + ... + a[i]. Thì a[i + 1] + a[i + 2] + ... + a[n] = pre[n] - pre[i]
ĐPT: O(NlogN)
*/
