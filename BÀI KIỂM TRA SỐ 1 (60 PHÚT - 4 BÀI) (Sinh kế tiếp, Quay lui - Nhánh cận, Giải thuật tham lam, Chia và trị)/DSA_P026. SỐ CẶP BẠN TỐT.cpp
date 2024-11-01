#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, k, ans = 0;
    cin >> n >> k;
    vector<string> s(n + 1);
    int f[n + 1][30] = {};  //f[i][j]: Số lượng xâu con dài j tính từ đầu cho đến chỉ số i
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        for (int j = 0; j < 30; j++) f[i][j] = f[i - 1][j];  
        f[i][s[i].size()]++;  
    }
    for (int i = 1; i <= n; i++) {
        int length = s[i].size();
        ans += f[i - 1][length] - f[max(i - k - 1, 0)][length];
    }
    cout << ans;
}
