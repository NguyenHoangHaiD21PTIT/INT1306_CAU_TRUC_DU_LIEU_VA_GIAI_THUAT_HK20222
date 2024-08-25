#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ii pair<int, int>

const int N = 2e7 + 300; // Kích thước tối đa cho mảng
const int M = 1e2 + 5;   // Kích thước tối đa cho mảng c
const int MOD = 1e9 + 7; // Modulo thường dùng trong các bài toán

int n;
int a[N], nt[N], kt[N], c[M];
long long t[N];
int k = 0, cnt = 0;
bool x = false;

// Hàm phân tích số n thành các yếu tố nguyên tố
void factorize(int n) {
    while (n > 1) {
        ++t[nt[n]];
        n /= nt[n];
    }
}

// Hàm thực hiện Sieve of Eratosthenes để tìm số nguyên tố
void sieve() {
    for (int i = 2; i * i <= k; ++i) {
        if (nt[i] == 0) { // Nếu i là số nguyên tố
            for (int j = i; j <= k; j += i) {
                if (nt[j] == 0) {
                    nt[j] = i; // Đặt yếu tố nguyên tố cho j
                    if (j > i) {
                        kt[j] = 1; // Đánh dấu j không phải là số nguyên tố nguyên thủy
                    }
                }
            }
        }
    }
    // Đặt giá trị cho các số nguyên tố
    for (int i = 2; i <= k; ++i) {
        if (nt[i] == 0) {
            nt[i] = i; // Đặt số nguyên tố nguyên thủy cho i
        }
        if (kt[i] == 0) {
            c[++cnt] = i; // Thêm số nguyên tố vào danh sách c
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n; // Đọc số lượng phần tử

    // Đọc mảng a và xác định giá trị lớn nhất trong mảng
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        k = max(k, a[i]);
    }

    k += 200; // Tăng giá trị k để đảm bảo bao phủ tất cả các giá trị cần thiết

    sieve(); // Thực hiện sàng lọc số nguyên tố

    // Kiểm tra điều kiện để xác định nếu không thể tạo dãy số đẹp
    for (int i = 1; i <= n; ++i) {
        if (a[i] == 1) {
            x = true;
            break;
        }
        if (i > 1 && a[i] == 0 && a[i - 1] == 0) {
            x = true;
            break;
        }
        if (i > 1 && a[i] != 0 && a[i - 1] != 0 && __gcd(a[i], a[i - 1]) != 1) {
            x = true;
            break;
        }
        if (a[i] > 1 && ((i > 1 && a[i - 1] == 0) || (i < n && a[i + 1] == 0))) {
            factorize(a[i]);
        }
    }

    if (x) {
        cout << -1; // Không thể tạo dãy số đẹp
    } else {
        for (int i = 1; i <= cnt; ++i) {
            if (t[c[i]] == 0) {
                cout << c[i];
                break;
            }
        }
    }

    return 0;
}
