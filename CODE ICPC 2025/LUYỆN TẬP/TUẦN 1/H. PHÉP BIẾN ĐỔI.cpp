#include <bits/stdc++.h>
using namespace std;
int sol(long long A, long long B) {
    long long D = abs(A - B);
    if (D == 0) return 0;
    // Giải phương trình k(k+1)/2 >= D --> k^2 + k - 2D >= 0
    // delta = 1 + 8D. Hiển nhiên nghiệm bé âm
    /*D = |A - B|. Giả sử chúng ta cần k bước, cộng vào A hay B tính sau. Như vậy, lượng cần cộng là S = 1 + 2 + ... + k = k * (k + 1)/2
    1. Như vậy S < D thì không đủ lượng mà cộng. Bắt buộc phải đi từ k min mà S >= D
    2. Giả sử ta cộng sum1 vào A, sum2 vào B, sum1 + sum2 = S. Mà sum1 + A = sum2 + B --> sum1 - sum2 = B - A = D
    Giải hệ sum1, sum2 ra
    */
    long long k = ceil((-1 + sqrt(1 + 8.0 * D)) / 2);
    while (true) {
        long long S = k * (k + 1) / 2;
        if (S >= D && (S - D) % 2 == 0)
            return k;
        ++k;
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        long long A, B;
        cin >> A >> B;
        cout << sol(A, B) << endl;
    }
}
