#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    long long tong = accumulate(a.begin(), a.end(), 0LL); 
    vector<int> uoc;
    for (int i = 1; i * i <= tong; i++) {
        if (tong % i == 0) {
            uoc.push_back(i);
            if (i * i != tong) uoc.push_back(tong / i);
        }
    }
    sort(uoc.rbegin(), uoc.rend()); // Sắp xếp các ước số theo thứ tự giảm dần
    for (int x : uoc) {
        long long cnt = 0;
        for (int y : a) cnt += min(y % x, x - y % x);
        if (cnt <= k) {
            cout << x << endl; 
            return 0; 
        }
    }
    return 0;
}
