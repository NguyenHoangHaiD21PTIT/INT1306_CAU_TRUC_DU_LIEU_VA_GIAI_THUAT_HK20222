#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000001;
int minPrime[MAX];
map<int, int>mp; //mp[x]: Số mũ của x trong tổ hợp C(k, n)

void sieve() {//Sàng tìm ước SNT nhỏ nhất
    for (int i = 2; i * i < MAX; ++i) {
        if (minPrime[i] == 0) {
            for (int j = i * i; j < MAX; j += i) {
                //Nếu i là SNT thì với những bội của i chưa ghi nhận ước SNT nhỏ nhất trước đó --> Gán. Tránh ghi đè
                //Ví dụ: i = 2 --> Ước SNT min của 4, 6, 8, ... là 2
                //Khi i = 3. 6 cũng là bội của 3. Nhưng 6 đã có ước SNT min trước đó --> Không ghi nữa
                if (minPrime[j] == 0) minPrime[j] = i;
            }
        }
    }
    for (int i = 2; i < MAX; ++i) {
        if (minPrime[i] == 0) minPrime[i] = i;
    }
}

void pt(int n, int sign) {//Phân tích số n ra TSNT, sign: 1 là ++, -1:--
    while (n > 1) {
        int tmp = minPrime[n];
        mp[tmp] += sign;
        n /= tmp;
    }
    //Vi dụ: Số 12 nằm dưới mẫu, minPr[12] = 2, ta chia cho 2 thì cần giảm số mũ của 2 đi 1
}

long long cnt(int n, int k) {
    //n!/[k! * (n - k)!]: Tử số là tích từ k + 1 đến n (Rút gọn n!/k!), mẫu số là (n - k)!
    mp.clear();
    for (int i = k + 1; i <= n; ++i) pt(i, 1);
    for (int i = 2; i <= n - k; ++i) pt(i,-1);
    long long res = 1;
    //Như vậy, trong map lúc này đã có đầy đủ các thừa số nguyên tố và số mũ của nó
    //Giả sử: X = a^x1 * b^x2 * c^x3. Tìm số ước của a
    //Tất cả các ước của a phải có dạng: a^y1 * b^y2 * c^y3. Với 0 <= y1 <= x1, 0 <= y2 <= x2, ...
    //Chọn y1: Có x1 - 0 + 1 = x1 + 1 cách, tương tự ... rồi áp dụng quy tắc nhân
    for (auto p : mp) res *= (p.second + 1);
    return res;
}

int main() {
    sieve();
    int n, k;
    while (cin >> n >> k) cout << cnt(n, k) << endl;
    return 0;
}
