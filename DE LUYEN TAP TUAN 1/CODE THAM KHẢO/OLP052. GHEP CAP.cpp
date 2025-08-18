#include <bits/stdc++.h>
using namespace std;

const int MAX = 2000000;
int lp[MAX + 1] = {};

void sieve() {
    for (int i = 2; i <= sqrt(MAX); i++) {
        if (!lp[i]) {
            for (int j = i * i; j <= MAX; j += i) {
                if (!lp[j]) lp[j] = i;
            }
        }
    }
    for (int i = 2; i <= MAX; i++) {
        if (!lp[i]) lp[i] = i;
    }
}

int divs(int n) {
    int res = 1;
    while (lp[n]) {
        int p = lp[n], c = 0;
        while (n % p == 0) {
            c++;
            n /= p;
        }
        res *= (c + 1);
    }
    if (n > 1) res *= 2;
    return res;
}

int main() {
    sieve();
    int t; cin >> t;
    while (t--) {
        int x; cin >> x;
        if (!x) {
            cout << 0 << "\n";
            continue;
        }
        cout << divs(x) << "\n";
    }
}
/*
*) Giả sử mỗi cặp có cùng hiệu k. Khi đó, các cặp đều phải có dạng (x, x + k)
Chia các số 1, 2, ..., 2n theo mod k. Các số cùng phần dư r sẽ tạo thành CSC: Nhóm 1: r, r + k, r + 2k, .... Nhóm 2: a, a + k, a + 2k, ...
Để các số có hiệu là k, bắt buộc ta phải ghép các số kề nhau trong từng nhóm. (r, r + k); (r + 2k), ... nên bắt buộc mỗi nhóm cùng số dư phải có số phần tử là số chẵn
*) n = 7, k = 5, 2n = 14 = 5 * 2 + 4. Xét từ 1 đến 14, số dư khi chia cho 5 quay vòng là:
1, 2, 3, 4, 0, 1, 2, 3, 4, 0, 1, 2, 3, 4. Để ý thấy rằng: Các lớp dư 1, 2, 3, 4 mỗi lớp dư có 4 phân tử
Lớp dư 0 có 2 phần tử. Tổng quát: 2n = qk + t. Có t lớp dư có q + 1 phần tử, k - t lớp dư có q phần tử.
--> Chứng minh: Chia cho k thì tối đa có k lớp dư. qk là phần nguyên, t là phần dư. 
Sau qk số đầu, mỗi lớp dư có đúng q phần tử: [1, 2, ..., k, 0] [1, 2, ..., k, 0] ... [1, 2, ..., k, 0] [1, 2, ..., t]
                                                  Chu kì 1           Chu kì 2             Chu kì q       Chu kì phụ
t số cuối cùng này là t lớp dư đầu tiên, mỗi lớp dư đã có sẵn q phần tử. Vậy ta có t lớp dư có q + 1 phần tử
1 chu kì hoàn chỉnh thì có k số, t số đầu dôi ra chu kì phụ, vậy còn k - t số không dôi ra chu kì phụ, tức chỉ nằm trong q chu kì -->
2n chia cho k, k chẵn hay lẻ thì q ra vẫn là số chẵn --> q + 1 là số lẻ.
Vì vậy, t phải bằng 0, 2n chia hết cho qk --> q = 2n / k là số chẵn --> n là ước của k
*) Hiển nhiên, trong mỗi một lớp dư, chỉ có một cách sắp xếp duy nhất
*/
