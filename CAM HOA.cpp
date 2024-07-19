#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    int v[k + 4][n + 5];  // Độ thẩm mĩ
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n; ++j) cin >> v[i][j];
    }
    
    vector<vector<int>> b(k + 1, vector<int>(n + 1, 0));  // b[i][j] = 1 tức là hoa thứ i cắm ở lọ j
    int t[k + 1];

    if (k > n) {
        cout << -1 << endl;
    } else if (k == n) {
        int tong = 0;
        for (int i = 0; i < k; ++i) tong += v[i][i];
        cout << tong << endl;
        for (int i = 1; i <= k; ++i) cout << i << " " << i << endl;
    } else {
        for (int j = 1; j <= k; ++j) {  // j lọ hoa
            // Trường hợp j hoa, j lọ
            t[j] = t[j - 1] + v[j - 1][j - 1];
            b[j][j] = 1;
            // Số hoa i < số lọ j:
            for (int i = j - 1; i > 0; --i) {
                int tt = t[i - 1] + v[i - 1][j - 1];  // i - 1 bó đầu vào j lọ đầu, lọ cuối thì để cho thằng cuối cùng
                if (tt > t[i]) {
                    t[i] = tt;
                    b[i] = b[i - 1];
                    b[i][j] = 1;
                }
            }
        }

        for (int j = k + 1; j <= n; ++j) {
            // Duyệt cột với số bó hoa i từ trên xuống
            // Số hoa i < số lọ j
            for (int i = k; i > 0; --i) {
                int tt = t[i - 1] + v[i - 1][j - 1];
                if (tt > t[i]) {
                    t[i] = tt;
                    b[i] = b[i - 1];
                    b[i][j] = 1;
                }
            }
        }

        // In giá trị thẩm mỹ tối đa
        cout << t[k] << endl;
        vector<pair<int, int>> res;
        int cnt = 1;
        for (int i = 0; i <= n; ++i) {
            if (b[k][i]) {
                res.push_back({cnt, i});
                cnt++;
            }
        }
        for (auto x : res) cout << x.first << " " << x.second << endl;
    }
}
