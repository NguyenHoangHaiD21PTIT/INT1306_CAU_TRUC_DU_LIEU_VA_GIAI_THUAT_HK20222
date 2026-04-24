#include <bits/stdc++.h>
using namespace std;
const int N = 305;
int f[N][N]; //f[][j]: Số bước tối ưu để xoá đoạn [i, j]
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
                // Trường hợp 1 (Tự chủ): Coi s[i] là 1 xâu đối xứng độ dài 1 --> Xoá trong 1 bước, còn lại [i + 1 ... j]
                f[i][j] = 1 + f[i + 1][j];
                // Trường hợp 2 (Ghép với cái bên cạnh):
                // 2 người kề nhau mà bằng nhau --> Xâu đối xứng độ dài 2
                if (s[i] == s[i + 1]) {
                    int tmp = 1; //1 này là 1 bước xoá xâu đối xứng s[i]s[i + 1]
                    if (i + 2 <= j) tmp += f[i + 2][j];
                    f[i][j] = min(f[i][j], tmp);
                }
                // Trường hợp 3 (Ghép s[i] với s[k] (k >= i+2))
                //i [i + 1 i + 2 ... k - 1] k [k + 1 k + 2 ... j]
                //s[i] + Phần ruột + s[k] + Phần đuôi
                for (int k = i + 2; k <= j; k++) {
                    if (s[i] == s[k]) {
                        int left = 0;
                        if (i + 1 <= k - 1) left = f[i + 1][k - 1];
                        int right = 0;
                        if (k + 1 <= j) right = f[k + 1][j];
                        int tmp = left + right; //Xoá đuôi,
                        f[i][j] = min(f[i][j], tmp);
                    }
                }
            }
        }
        cout << f[0][n-1] << "\n";
    }
}
/* Các bạn có thể submit bài này tại: https://codeforces.com/problemset/problem/607/B 
Lời giải: 
#include <bits/stdc++.h>
using namespace std;

const int N = 505; 
int f[N][N]; 
int s[N]; 

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) f[i][j] = 0;
    }
    for (int i = 0; i < n; i++) f[i][i] = 1;
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i + len - 1 < n; i++) {
            int j = i + len - 1;
            // Trường hợp 1 (Tự chủ): Xóa riêng s[i] mất 1 bước
            f[i][j] = 1 + f[i + 1][j];
            // Trường hợp 2 (Ghép với cái bên cạnh): 
            if (s[i] == s[i + 1]) {
                int tmp = 1; 
                if (i + 2 <= j) tmp += f[i + 2][j];
                f[i][j] = min(f[i][j], tmp);
            } 
            // Trường hợp 3 (Ghép s[i] với s[k] (k >= i+2))
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
    cout << f[0][n - 1];
} */
