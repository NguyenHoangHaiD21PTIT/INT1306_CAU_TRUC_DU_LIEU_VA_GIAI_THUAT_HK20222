#include <bits/stdc++.h>
using namespace std;

const int NMAX = 100000 + 5, LGMAX = 17; // floor(log2(1e5)) = 16
int n, K;
long long A[NMAX];
int B[NMAX], lg2tab[NMAX], st[LGMAX + 1][NMAX]; // st[j][i] = gcd đoạn [i, i + 2^j - 1]

int UCLN(int a, int b) {
    while (b) {
        int r = a % b;
        a = b; b = r;
    }
    return a >= 0 ? a : -a;
}

void build_logs(int n) { // Tìm k max sao cho 2^k <=i
    lg2tab[1] = 0;
    for (int i = 2; i <= n; ++i) lg2tab[i] = lg2tab[i >> 1] + 1;
}

// Xây bảng thưa GCD trên B[1..n]
void build_sparse(int n) {
    for (int i = 1; i <= n; ++i) st[0][i] = B[i];
    for (int j = 1; pow(2, j) <= n; ++j) {
        for (int i = 1; i + int(pow(2, j)) - 1 <= n; ++i) st[j][i] = UCLN(st[j - 1][i], st[j-1][i + (int) pow(2, j - 1)]);
    }
}
/*Giải thích: st[j][i] là GCD của đoạn [i, i + 2^j - 1].
st = i, len = 2 ^ j = en - i + 1 --> en = i + 2^j - 1
a2[i] = GCD(a[i], a[i + 1]) = min(st[0][i], st[0][i + 1]) = st[1][i].
a4[i] = GCD(a2[i], a2[i + 2]) = GCD(st[1][i], st[1][i + 2]) = st[2][i].
a8[i] = GCD(a4[i], a4[i + 4]) = GCD(st[2][i], st[2][i + 4]) = st[3][i].
...
st[j][i] = GCD(st[j - 1][i], st[j - 1][i + 2^(j - 1)]) */

// RMQ-GCD trên [l, r] (l <= r)
int gcd_range(int l, int r) {
    int k = lg2tab[r - l + 1]; //Tìm k lớn nhất sao cho 2^k <= r - l + 1
    int len = 1 << k;
    return UCLN(st[k][l], st[k][r - len + 1]);
}

int main() {
    int T; cin >> T;
    while (T--) {
        cin >> n >> K;
        for (int i = 1; i <= n; ++i) cin >> A[i];
        // Ta chuẩn hoá: Nếu A[i] % K != 0 thì B[i] = 0, còn nếu A[i] % K == 0 thì B[i] = A[i] / K
        // Bài toán trở thành: Tìm đoạn con ngắn nhất có gcd(B[l..r]) == 1 và không chứa số 0
        for (int i = 1; i <= n; ++i) {
            if (A[i] % K == 0) {
                long long v = A[i] / K;
                B[i] = (int)v;
            } else {
                B[i] = 0;
            }
        }
        build_logs(n);
        build_sparse(n);
        int ans = INT_MAX;
        int i = 1;
        while (i <= n) {
            //Nếu B[i] == 0, thì đoạn toàn số khác 0 đã bị gãy, bỏ qua
            if (B[i] == 0) { 
                ++i; 
                continue; 
            }
            // Tìm đoạn [i .. R] sao cho B[x] > 0 với mọi x trong đoạn, kéo dài nhất có thể
            int R = i;
            while (R + 1 <= n && B[R + 1] > 0) ++R;
            // Sau bước này, ta đã xác định được dãy B[i], B[i + 1], ..., B[R] là dãy toàn số khác 0
            // --> Có tiềm năng để UCLN là 1, mục tiêu là phải trích được đoạn con liên tiếp ngắn nhất trong dãy con này có UCLN là 1
            for (int l = i; l <= R; ++l) {
                // B[i] = 1 --> A[i] = k --> Dãy con ngắn nhất chính là số đó
                if (B[l] == 1) { 
                    ans = 1; 
                    break; 
                }
                int lo = l, hi = R, pos = -1;
                // GCD (B[l], ..., B[R]) khác 1 thì càng kéo ngắn lại auto càng tăng
                // Ví dụ: GCD(a, b, c) = f --> a = k1 * f, b = k2* f, c = k3 * f. Nên kéo ngắn về a và b thì chắc chắn rằng UCLN tối thiểu là f
                // Nên là, dãy càng ngắn thì GCD càng to và ngược lại --> Chặt nhị phân được
                if (gcd_range(l, R) != 1) continue;
                // Dãy dài đã UCLN không đạt 1 --> Càng kéo ngắn càng to --> Không làm nữa
                // Mỗi bước, ta cố định l, chặt nhị phân để tìm r min sao cho GCD(B[l] ... B[r]) = 1
                // Ban đầu, không biết r ở đâu --> Tìm cả đoạn từ l (lo) đến R (hi)
                while (lo <= hi) {
                    int mid = (lo + hi) / 2;
                    int g = gcd_range(l, mid);
                    // Có dãy con UCLN = 1 rồi, thử thu hẹp cận rxem được k
                    if (g == 1) {
                        pos = mid;
                        hi = mid - 1;
                    } else {
                        // Dãy ngắn quá (Cận r bé quá) --> Đẩy phạm vi tìm kiếm sang phải
                        lo = mid + 1;
                    }
                }
                if (pos != -1) {
                    ans = min(ans, pos - l + 1);
                    if (ans == 1) break; // tối ưu
                }
            }
            // Sau khi trích ra được dãy liên tiếp ngắn nhất GCD = 1 từ dãy con có tiềm năng --> Hết giá trị sử dụng đoạn này
            // Tìm đoạn tiếp theo
            i = R + 1;
        }
        if (ans == INT_MAX) cout << -1 << '\n';
        else cout << ans << '\n';
    }
}
// Đọc thêm về bài toán RMQ tại: https://wiki.vnoi.info/algo/data-structures/rmq
/*
Hướng giải: 
1. Chuẩn hoá: A[i] chia hết cho K thì biến A[i] thành A[i]/k, ngược lại biến A[i] thành 0. Cho hết vào mảng B
Bài toán trở thành tìm dãy con liên tiếp ngắn nhất, có GCD là 1, không chứa số 0
2. Tiền xử lý tính GCD trên đoạn [B[l], B[r]]. ĐPT của bảng thưa là: logN(for độ dài) * N (for index bắt đầu) --> N = 1e5 đủ tốt
Tính GCD trong đoạn: O(1)
3. Với mỗi index i, kéo dài tối đa để xác định dãy dài nhất toàn chứa số khác 0. Bởi lẽ chứa số 0 --> Chứa số A[i] k chia hết cho K thì khỏi xét
4. Sau khi xác định được dãy căng nhất B[i] ... B[R] thì ta tìm cách trích xuất từ dãy này dãy ngắn nhất, gọi là B[l] ... B[r], GCD là 1:
a'. Nếu B[l] = 1 thì coi như xong. Khỏi tìm
a. Hiển nhiên i <= l, r <= R. Ta xét lần lượt từng l chạy từ i đến R. Với mỗi l, ta cố định nó, chặt nhị phân trên [l, R] để tìm r min
b. Nếu dãy từ l đến R có GCD khác 1 rồi, càng kéo ngắn r thì GCD càng to --> Tăng l lên xét tiếp
c. Sau khi xác định xong dãy B[l] ... B[R] có GCD là 1 rồi, ta thử kéo ngắn r xem được không
Chú ý rằng: r càng bé, GCD càng to 
r = mid mà GCD vẫn là 1, ok, thử kéo r về nửa bên trái
r = mid mà GCD khác 1 --> r quá bé, dãy quá ngắn --> Phải kéo r về nửa phải để hope GCD bé đi
d. Sau khi xác định xong cận r cho dãy min rồi, cập nhật dãy nếu r tồn tại
5. Sau khi khai thác triệt để dãy B[i] ... B[R] rồi, ta xét vị trí bắt đầu mới từ R + 1
*/
