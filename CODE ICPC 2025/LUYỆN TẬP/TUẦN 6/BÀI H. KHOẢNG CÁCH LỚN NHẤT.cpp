#include <bits/stdc++.h>
using namespace std;

struct P { long long x, y; };

bool cmp(const P &a, const P &b) {
    if (a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}

vector<long long> X, Y, pMin, pMax, sMin, sMax;

//Hàm kiểm tra xem có cặp điểm cách nhau >= t không
bool ok(long long t) {
    int n = X.size();
    for (int i = 0; i < n; ++i) { 
        // Xét các điểm bên trái i: tìm j sao cho X[i] - X[j] >= t
        // upper_bound trả về index đầu tiên > X[i] - t, lùi 1 để ra index cuối cùng <=
        int L = upper_bound(X.begin(), X.end(), X[i] - t) - X.begin() - 1;
        // Nếu tồn tại điểm bên trái (L >= 0). Các điểm từ 0 1 ... L đều thoả mãn về khoảng cách theo trục X
        // Khoảng cách thực tế là min(|Δx|, |Δy|), nên cần kiểm tra |Δy| nữa, xem có >= t hay không. Xét các j tong [0; L] trái i
        // Trường hợp Y[j] > Y[i]: cần Y[j] - Y[i] >= t, tức Y[j] >= Y[i] + t. Điểm khả dĩ nhất là giá trị prefixMax Y từ 0..L.
        // Trường hợp Y[j] < Y[i]: cần Y[i] - Y[j] >= t, tức Y[j] <= Y[i] - t. Điểm khả dĩ nhất là giá trị prefixMin Y từ 0..L.
        if (L >= 0 && (pMin[L] <= Y[i] - t || pMax[L] >= Y[i] + t)) return true;
        // Xét các điểm bên phải i: tìm j sao cho X[j] >= X[i] + t
        int R = lower_bound(X.begin(), X.end(), X[i] + t) - X.begin();
        // Kiểm tra Y tương tự: 
        if (R < n && (sMin[R] <= Y[i] - t || sMax[R] >= Y[i] + t)) return true;
    }
    return false;
}


int main() {
    int n; cin >> n;
    vector<P> a(n);
    X.resize(n); Y.resize(n);
    pMin.resize(n); pMax.resize(n); sMin.resize(n); sMax.resize(n);
    for (int i = 0; i < n; ++i) cin >> a[i].x >> a[i].y;
    sort(a.begin(), a.end(), cmp); 
    // Tách riêng hoành độ và tung độ ra
    for (int i = 0; i < n; ++i) { 
        X[i] = a[i].x; 
        Y[i] = a[i].y; 
    }
    pMin[0] = pMax[0] = Y[0];//p: prefix, pMin[i]: Tung độ nhỏ nhất trong số các điểm từ điểm thứ 0 đến điểm thứ i
    for (int i = 1; i < n; ++i) {
        pMin[i] = min(pMin[i - 1], Y[i]);
        pMax[i] = max(pMax[i - 1], Y[i]);
    }
    //s: suffix: Tung độ nhỏ nhất trong số các điểm từ điểm thứ n - 1 về điểm thứ i
    sMin[n - 1] = sMax[n - 1] = Y[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        sMin[i] = min(sMin[i + 1], Y[i]);
        sMax[i] = max(sMax[i + 1], Y[i]);
    }
    long long lo = 0, hi = 1e9, ans = 0;
    while (lo <= hi) {
        long long mid = (lo + hi) / 2;
        if (ok(mid)) { 
            ans = mid; 
            lo = mid + 1; 
        } else hi = mid - 1;
    }
    cout << ans << "\n";
}
