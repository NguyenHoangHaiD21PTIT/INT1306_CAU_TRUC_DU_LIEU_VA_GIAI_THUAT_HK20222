#include <bits/stdc++.h>
using namespace std;

const long long INF = LLONG_MAX; 
long long f[1003][1003][2]; 

long long dis(pair<int, int> a, pair<int, int> b) { // Bình phương khoảng cách 2 điểm A và B
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a(n + 1), b(m + 1); 
    for (int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;
    for (int i = 1; i <= m; i++) cin >> b[i].first >> b[i].second;
    memset(f, 0x3f, sizeof(f)); 
    f[1][0][0] = 0; // Bắt đầu từ địa điểm đầu tiên của khu A

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            /* Đi hết i cụm A, j cụm B và kết thúc ở A: Đi hết i - 1 cụm A, j cụm B 
               TH1: Đang kết thúc ở A: Đi từ cụm thứ i - 1 của A sang cụm thứ i của A
               TH2: Đang kết thúc ở B: Đi từ cụm thứ j của B sang cụm thứ i của A
            */
            if (i > 1) f[i][j][0] = min(f[i - 1][j][0] + dis(a[i], a[i - 1]), f[i - 1][j][1] + dis(a[i], b[j]));

            /* Đi hết i cụm A, j cụm B và kết thúc ở B: Đi hết i cụm A, j - 1 cụm B 
               TH1: Đang kết thúc ở A: Đi từ cụm thứ i của A sang cụm thứ j của B
               TH2: Đang kết thúc ở B: Đi từ cụm thứ j - 1 của B sang cụm thứ j của B
            */
            if (j > 0) f[i][j][1] = min(f[i][j - 1][0] + dis(a[i], b[j]), f[i][j - 1][1] + dis(b[j - 1], b[j]));
        }
    }
    cout << f[n][m][0];
}
