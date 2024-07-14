/*Thầy Huy: Bài 5. QUY HOẠCH ĐỘNG

        BÀI TẬP 1
Đề bài: Có bao nhiêu cách chia (pt) phần thưởng cho (hs) học sinh được đánh số thứ tự từ 1 đến hs sao cho học sinh 
có stt xếp đầu luôn nhận không ít hơn bạn STT sau mình

Link nộp: https://nbkcs.ucode.vn/problems/nbkcsdp01-chia-phan-thuong-award-155585

Bài giải:
f[i][j]: Số cách chia i phần thưởng cho j học sinh:
1. Không có học sinh: Không có cách chia nào: f[i][0] = 0
2. Có học sinh nhưng không có phần thưởng: f[0][i] = 1; Mỗi em nhận 0 phần thưởng
3. Số phần thưởng (pt) ít hơn số học sinh (hs) thì ngay cả phương án chia cân bằng nhất mỗi em 1 pt thì từ em thứ
pt + 1 không được nhận thưởng: f[pt][hs] = f[pt][pt]
4. Tổng quát: pt >=hs
    a. Em cuối bảng không được nhận thưởng: f[pt][hs - 1]
    b. Em cuối bảng được nhận thưởng: Mọi em được nhận thưởng: f[pt - hs][hs]
*/
#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

int f[1005][1005] = {};

int solve(int n){
    for (int j = 0; j <= n; j++) f[0][j] = 1; 
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i < j) f[i][j] = f[i][i];
            else f[i][j] = (f[i][j-1] + f[i-j][j]) % MOD;
        }
    }
    return f[n][n];
}
int main() {
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    int n;
    cin >> n;
    cout<<solve(n);
}
