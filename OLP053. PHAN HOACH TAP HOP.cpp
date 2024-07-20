#include <bits/stdc++.h>
using namespace std;

vector<int> a;
vector<bool> un;//un[i] = false: phần tử vị trí thứ i đã được sử dụng
int r;

void Try(int pre, int sum, int ind, int p, int n) {
    // pre: chỉ số phần tử tiếp theo mà hàm xét đến
    // sum: tổng các phần tử đã được chọn 
    // ind: chỉ số của tập con
    // p: tổng mà tập con cần đạt được, n: só phần tử của dãy
    if (sum > p) return;
    if (ind == 2) { // Khi đã phân hoạch thành 2 tập con, thì phần còn lại sẽ là tập con thứ ba
        r++;
        return;
    }
    if (sum == p) return Try(0, 0, ind + 1, p, n);
    for (int i = pre; i < n; i++) {
        if (un[i]) { // Nếu phần tử chưa được sử dụng
            un[i] = false; // Đánh dấu phần tử đã được sử dụng
            Try(i + 1, sum + a[i], ind, p, n);
            un[i] = true; 
        }
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        a.resize(n);
        un.resize(n, true);
        r = 0;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
        }
        if (sum % 3 != 0) {
            cout << 0 << endl;
            continue;
        }
        sort(a.begin(), a.end());
        Try(0, 0, 0, sum / 3, n);
        cout << r << endl;
    }
    return 0;
}
