#include <bits/stdc++.h>
using namespace std;
const int MAX_SIZE = 6005;
const int MOD = 1e9 + 7;

int main() {
    int n, m, k, edge, e; //n: chiều ngang, m: chiều dọc, k: c ô vuông đã tô màu, edge: Cạnh hình vuông phải chia hết cho edge, e: số ô được tô màu tối đa
    cin >> n >> m >> k >> edge >> e;
    int a[6005][6005], t[6005][6005];
    for (int i = 1; i <= k; ++i) {
        int x, y; cin >> x >> y;
        a[x][y] = 1;
    }
    //Prefix sum 2D
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j)  t[i][j] = t[i - 1][j] + t[i][j - 1] - t[i - 1][j - 1] + a[i][j];
    }
    int res = 0; // Kết quả tối ưu
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            //Với mỗi ô (i, j). Ta sẽ xét các ma trận con có góc phải dưới là ô này. Chặt nhị phân theo kích thước của ma trận vuông
            //Trong bài làm này ta sẽ lấy chiều dài cạnh + 1
            //Cạnh to nhất cũng chỉ được phép là min(i, j). VD (i, j) = (4, 3) thì 3 - x + 1>=1-->x<=3
            //Đương nhiên để chia hết cho edge, thì tối thiểu phải là edge. 
            int k = 0;
            int d = max(res, edge - 1);
            int c = min(i, j) - 1;
            // Tìm kích thước ma trận vuông tối đa có thể với tổng <= e
            while (d <= c) {
                int mid = (d + c) / 2;
                int x = i - mid;
                int y = j - mid;
                int sum = t[i][j] - t[i][y - 1] - t[x - 1][j] + t[x - 1][y - 1];
                if (sum <= e) {
                    k = mid + 1;
                    d = mid + 1;
                } else {
                    c = mid - 1;
                }
            }
            if (k) res = max(res, (k / edge) * edge);
        }
    }
    cout<<res;
}
