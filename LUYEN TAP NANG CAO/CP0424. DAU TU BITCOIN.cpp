#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int res = a[0];//res: Lưu phần tử to nhất từ đầu đến index i
    int ans = -1;//Kết quả
    for (int i = 1; i < n; ++i) {
        if (a[i] < res) ans = max(ans, res - a[i]);
        res = max(res, a[i]);
    }
    if(ans==-1) cout<<"Lo nang roi";
    else cout << ans << endl;
}
