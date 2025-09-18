#include <bits/stdc++.h>
using namespace std;

struct St { 
    int x, y; 
};

int rmd[205][205];   // rmd[x][y] = dư số S(x,y) mod n

// In số S(x,y) = 88...866...6
void pr(int x, int y) {
    for (int i = 0; i < x; i++) cout << '8';
    for (int i = 0; i < y; i++) cout << '6';
    cout << "\n";
}

// (10^k) mod n
int pw(int k, int n) {
    int res = 1;
    for (int i = 0; i < k; i++) res = res * 10 % n;
    return res;
}

void solve(int n) {
    for (int i = 0; i <= 200; i++) {
        for (int j = 0; j <= 200; j++) rmd[i][j] = -1;
    }
    queue<St> q;
    q.push({0, 0});
    rmd[0][0] = 0;
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        int x = cur.x, y = cur.y;
        if (x + y > 0 && rmd[x][y] == 0) {
            pr(x, y);
            return;
        }
        //Thêm 6 vào cuối: Nhân thêm 10 để lấy chỗ cho chữ số cuối cùng, cộng tương ứng chữ số ấy vào
        if (y + 1 <= 200 && rmd[x][y + 1] == -1) {
            rmd[x][y + 1] = (rmd[x][y] * 10 + 6) % n;
            q.push({x, y + 1});
        }
        //Thêm 8 vào đầu. Ví dụ: Số 12345 có 5 chữ số, thêm 8 vào đầu: 812345 = 8 * 10^(5 = Số chữ số số gốc) + 12345(Số gốc)
        if (x + 1 <= 200 && rmd[x + 1][y] == -1) {
            rmd[x + 1][y] = ((8 * pw(x + y, n)) + rmd[x][y]) % n;
            q.push({x + 1, y});
        }
    }
    cout << "-1\n";
}

int main() {
    int T, n; cin >> T;
    while (T--) {
        cin >> n; solve(n);
    }
}
//Link submit: https://oj.vnoi.info/problem/luckynum
