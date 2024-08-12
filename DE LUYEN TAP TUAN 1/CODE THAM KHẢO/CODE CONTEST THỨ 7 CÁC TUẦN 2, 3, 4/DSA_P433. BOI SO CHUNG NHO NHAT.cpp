#include <bits/stdc++.h>
using namespace std;

const long long MAX = 1000000, MOD = 1000000007;
long long prime[MAX + 1]; 
vector<long long> primes;

void sieve() { // Sàng thông thường
    for(long long i = 0;i<=MAX;i++) prime[i] = 1;//Ban đầu tất cả là SNT
    prime[0] = prime[1] = 0; // 0 và 1 không phải là số nguyên tố
    for (long long i = 2; i * i <= MAX; ++i) {
        if (prime[i] == 1) {
            for (long long j = i * i; j <= MAX; j += i) prime[j] = 0; // Đánh dấu các bội số của i không phải là số nguyên tố
        }
    }
    for (long long i = 2; i <= MAX; ++i) {
        if (prime[i] == 1) primes.push_back(i); // Lưu các số nguyên tố vào vector
    }
}

// Hàm tính số lần xuất hiện của số nguyên tố p trong N! (Legendre)
long long dem(long long n, long long p) {
    long long dem = 0;
    while (n >= p) {
        dem += n / p;
        n /= p;
    }
    return dem;
}

int main() {
    sieve();
    int t;
    cin >> t;
    while (t--) {
        long long a, b;
        cin >> a >> b;
        long long ans = 1;
        //Phân tích b! ra thừa số nguyên tố: Tức là, xem mỗi số nguyên tố xuất hiện trong b! bao nhiêu lần
        //Dùng Legendre
        //Phân tích (a - 1)! ra thừa số nguyên tố: Tức là, xem mỗi số nguyên tố xuất hiện trong (a - 1)! bao nhiêu lần
        //Lấy b! chia cho (a - 1)! là xong phân tích TSNT, lúc này, ta đã có thừa số và số mũ tương ứng
        for (long long x : primes) {
            if (x > b) break;
            long long d1 = dem(b, x);
            long long d2 = dem(a - 1, x);
            ans = ans * (2 * (d1 - d2) + 1) % MOD;
            //Số mũ của x chính là d1 - d2 trong tích từ a đến b
            //Giả sử tích ấy bằng = a^x * b^y * c^z;
            //A = a^x1 * b^y1 * c^z1; B = a^x2 * b^y2 * c^z2
            //LCM(A, B) = a^x * b^y * c^z; --> max(x1, x2) = x, max(y1, y2) = y, max(z1, z2) = z
            //Vậy, 1 trong 2 thằng x1, x2 phải là max, thằng còn lại là max - 1 về 0 
            //Ví dụ như: x = 3 --> (3-2, 3-1, 3-0 VÀ HOÁN ĐỔI 0-3, 1-3, 2-3, và 3-3) --> có 2n + 1 cặp
        }
        cout << ans << endl;
    }
    return 0;
}
