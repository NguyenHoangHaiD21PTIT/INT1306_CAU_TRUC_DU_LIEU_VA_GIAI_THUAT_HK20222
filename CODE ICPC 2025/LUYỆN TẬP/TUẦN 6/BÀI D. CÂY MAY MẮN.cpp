#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7, MAX = 1000005;

long long fac[MAX], invFac[MAX], powN[MAX], powM[MAX];
int n, m;

long long modPow(long long a, long long b) {
    long long r = 1;
    a %= MOD;
    while (b) {
        if (b & 1) r = r * a % MOD;
        a = a * a % MOD;
        b /= 2;
    }
    return r;
}

// Tính a! và 1/(a!) theo MOD
void prepFac() {
    fac[0] = 1;
    for (int i = 1; i < MAX; ++i) fac[i] = fac[i - 1] * i % MOD;
    invFac[MAX-1] = modPow(fac[MAX - 1], MOD - 2);
    for (int i = MAX-2; i >= 0; --i) invFac[i] = invFac[i + 1] * (i + 1) % MOD;
}

// Tổ hợp chập b của a MOD
long long comb(int a, int b) {
    if (b < 0 || b > a) return 0;
    return fac[a] * invFac[b] % MOD * invFac[a - b] % MOD;
}

// Lũy thừa n^i và m^i
void prepPow(int n, int m) {
    powN[0] = powM[0] = 1;
    for (int i = 1; i < MAX; ++i) {
        powN[i] = powN[i - 1] * n % MOD;
        powM[i] = powM[i - 1] * m % MOD;
    }
}

/* Bài toán chia kẹo của Ơ le:
Bài toán 1: Phương trình x1 + x2 + ... + xk = n có bao nhiêu nghiệm nguyên dương
Ta viết n thành n số 1 trên 1 hàng 1 1 1 ... 1
Ta cần chia n số 1 này thành k phần, mỗi phần có ít nhất 1 số 1
Giữa n số 1 có n - 1 khoảng trống. k phần thì ta cần k thanh chắn ==> C(n - 1, k - 1)
Bài toán 2: Phương trình x1 + x2 + ... + xk = n có bao nhiêu nghiệm nguyên không âm
Đổi biến: (x1 + 1) + (x2 + 1) + ... + (xk + 1) = n + k, Đặt các xi + 1 = yi >= 1 > 0 
Ta quay về bài toán đếm số nghiệm nguyên dương của y1 + y2 + ... + yk = n + k  ==> C(n + k - 1, k - 1)*/

int main() {
    cin >> n >> m;
    prepFac();
    prepPow(n, m);
    long long res = 0;
    for (int i = 1; i < n; ++i) { //i = Số cạnh nằm trên đường đi chính giữa A và B
        //1. Đếm số cách chọn độ dài cho i cạnh sao cho tổng độ dài đúng bằng m
        //w1 + w2 + ... + wi = M, Do w1, w2, ..., wi >= 1. Nên ta có x1 + x2 + ... + xi = M - i với các xi = wi - 1 >= 0
        //C(M - i + i - 1, i - 1) = C(M - 1, i - 1) chính là số cách chọn độ dài trên i cạnh sao cho tổng độ dài đúng bằng M
        //2. Cho trước 2 đầu mút là A và B, ta cần đường đi i cạnh, tức là đường đi có i + 1 đỉnh
        //Mà đã có 2 đỉnh trước rồi, vậy phải chọn (i + 1) - 2 = (i - 1) đỉnh còn lại trong số n - 2 đỉnh
        //--> C(n - 2, i - 1)
        //3. (i - 1)!: Hoán vị i - 1 đỉnh được chọn. Thực chất 2 và 3 chính là chỉnh hợp chập (i - 1) của (n - 2)
        long long path = comb(m - 1, i - 1) * comb(n - 2, i - 1) % MOD * fac[i - 1] % MOD;
        //Như vậy ta đã có path là số cách dựng đường đi từ A đên B với độ dài là i
        //Bây giờ ta cần tính số cách bố trí các đỉnh còn lại
        int rem = n - (i + 1);//Xây xong đường đi từ A đên B có i + 1 đỉnh rồi thì đây chính là số đỉnh còn dư ra
        // Chú ý rằng: Một cây có n đỉnh thì có n - 1 cạnh. Đã xây i cạnh rồi, thì còn (n - 1) - i = n - (i + 1) = rem
        // Nên rem cũng chính là số cạnh dư luôn
        // TH1: Toàn bộ đỉnh vào đường đi từ A đến B hết rồi thì thôi, k làm được gì cả --> 1 cách
        long long attach = rem == 0 ? 1 : powN[rem - 1] * (i + 1) % MOD * powM[rem] % MOD;
        // TH2: Vẫn còn dư ra đỉnh sau khi xây xong path từ A -> B
        // rem cạnh dư, mỗi cạnh được chọn trọng số tuỳ ý từ 1 đến m, có m cách --> m ^ rem
        // Công thức Cayley mở rộng: Số cây tạo ra từ n đỉnh với cây con k đỉnh cố định có sẵn là: k * n ^ (n - k - 1)
        // Áp dụng: Cây con có sẵn gồm (i + 1) đỉnh, như vậy k = i + 1 --> n - k - 1 = n - (i + 1) - 1 = rem - 1 --> (i + 1) * n ^ (rem - 1)
        res = (res + path * attach % MOD) % MOD;
    }
    cout << res;
}
