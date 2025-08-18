#include <bits/stdc++.h>
using namespace std;

bool ok(vector<string>& g, int i, int j, int di, int dj) {
    int cnt = 0;
    for (int k = 0; k < 6; ++k) {
        char c = g[i + k * di][j + k * dj];
        if (c == '.') {
            ++cnt;
            if (cnt > 2) return false;
        }
    }
    return true;
}
//Từ ô (i, j), ta đi 5 lần theo hướng đã chọn
//Ví dụ: (i, j) --> (i + 1, j + 1) --> (i)
// (di, dj): (0, 1) - sang phải, (1, 0) - xuống dưới, (1, 1): Chéo chính, (1, 0): Chéo phụ
bool solve(vector<string>& g) {
    int N = g.size();
    if (N < 6) return false;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            bool A = j + 5 < N && ok(g, i, j, 0, 1); //Đi sang phải
            bool B = i + 5 < N && ok(g, i, j, 1, 0); //Đi xuống
            bool C = i + 5 < N && j + 5 < N && ok(g, i, j, 1, 1); //Chéo chính
            bool D = i + 5 < N && j - 5 >= 0 && ok(g, i, j, 1, -1); //Chéo phụ
            if(A || B || C || D) return true;
        }
    }
    return false;
}
int main() {
    int N; cin >> N;
    vector<string> g(N);
    for (int i = 0; i < N; ++i) cin >> g[i];
    cout << (solve(g) ? "Yes\n" : "No\n");
}
