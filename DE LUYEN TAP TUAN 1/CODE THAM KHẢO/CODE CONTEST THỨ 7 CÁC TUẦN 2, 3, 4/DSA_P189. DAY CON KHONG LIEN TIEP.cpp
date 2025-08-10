#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
using ll = long long;
int main() {
    ll N, M;
    cin >> N >> M;
    ll A[N + 1], B[M + 1];
    for (int i = 1; i <= N; ++i) cin >> A[i];
    for (int j = 1; j <= M; ++j) cin >> B[j];
    // F[i][j] = Số cặp tập con bằng nhau được lấy từ i phần tử đầu của a và j phần tử đầu của b
    // Nếu vô điều kiện thì sẽ có 2^i * 2^j cặp tập con
    long long F[N + 1][M + 1];
    // Khởi tạo: F[i][0] = 0 và F[0][j] = 0 (không có dãy con với chuỗi rỗng)
    for (int i = 0; i <= N; ++i) F[i][0] = 0;
    for (int j = 0; j <= M; ++j) F[0][j] = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            if (A[i] == B[j])  F[i][j] = (F[i - 1][j] + F[i][j - 1] + 1) % MOD;
            // F[i-1][j]: số cặp con bằng nhau khi không dùng phần tử A[i] (bỏ phần tử cuối của A).
            // F[i][j-1]: số cặp con bằng nhau khi không dùng phần tử B[j] (bỏ phần tử cuối của B).
            // +1: tạo ra một cặp dãy con mới là (A[i], B[j]) với chỉ một phần tử, vì A[i] == B[j].
            else F[i][j] = (F[i - 1][j] + F[i][j - 1] - F[i - 1][j - 1] + MOD) % MOD;
        }
    }
    cout << (F[N][M] + 1) % MOD << "\n";
}
//Bản chất bài toán là: Lấy ra 1 tập con (có thể không liên tiếp, rỗng) của A, cũng làm như vậy với B
//Hỏi có bao nhiêu cặp tập con bằng nhau về giá trị, nhưng khác nhau về chỉ số lựa chọn các phần tử
//Ví dụ: a0 a1 a2 a3   b0 b1 b2 b3
//Dãy a0 a2 a3 = b0 b1 b2, a0, a1 a2 = b0 b1 b2 tính 2 cặp
