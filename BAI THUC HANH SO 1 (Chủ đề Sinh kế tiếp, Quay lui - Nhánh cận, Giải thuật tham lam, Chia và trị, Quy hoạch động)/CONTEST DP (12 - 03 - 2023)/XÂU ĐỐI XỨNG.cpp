#include <bits/stdc++.h>
using namespace std;
const int N = 305;
int f[N][N];
int main() {
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) f[i][j] = 0;
        }
        //Cơ sở: Xâu đối xứng độ dài 1 --> Xoá trong 1 bước
        for (int i = 0; i < n; i++) f[i][i] = 1;
        //Duyệt theo độ dài đoạn
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                // Xóa riêng s[i] thì mất 1 bước. Phần còn lại là từ i + 1 đến j: Đã tính số bước tối ưu rồi, chính là f[i + 1][j]
                // Vì ta duyệt theo chiều dài mà. Đoạn dài phải phụ thuộc đoạn ngắn
                f[i][j] = 1 + f[i + 1][j];
                // Cặp liền kề bằng nhau --> Tạo thành xâu đối xứng độ dài 2 --> Mất đi 1 bước để xoá
                // Đoạn [i, i + 1, ..., j]: Xoá 2 ký tự đầu tiên thì còn [i + 2 ... j]
                if (s[i] == s[i + 1]) {
                    int tmp = 1;
                    // Phía sau vẫn còn thì cộng thêm, không thì 1 bước thôi
                    if (i + 2 <= j) tmp += f[i + 2][j];
                    f[i][j] = min(f[i][j], tmp);
                }
                //Ghép s[i] với s[k] (k >= i+2)
                //i [i + 1 i + 2 ... k - 1] k [k + 1 k + 2 ... j]
                for (int k = i + 2; k <= j; k++) {
                    if (s[i] == s[k]) {
                        int left = 0;
                        if (i + 1 <= k - 1) left = f[i + 1][k - 1];
                        int right = 0;
                        if (k + 1 <= j) right = f[k + 1][j];
                        int tmp = left + right;
                        f[i][j] = min(f[i][j], tmp);
                    }
                }
            }
        }
        cout << f[0][n-1] << "\n";
    }
}
