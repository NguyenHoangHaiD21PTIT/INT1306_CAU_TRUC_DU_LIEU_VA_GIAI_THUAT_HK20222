#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MX = 2e5 + 7;
int n, m, k;
ll BIT[MX];

// Cập nhật BIT
void upd(int x, ll v){
    while(x <= m){
        BIT[x] += v;
        x += x & -x;
    }
}

// Lấy tổng prefix 1..x
ll get(int x){
    ll s = 0;
    while(x > 0){
        s += BIT[x];
        x -= x & -x;
    }
    return s;
}

// Tổng trên đoạn l..r
ll get(int l, int r){ 
    return r < l ? 0 : get(r) - get(l - 1); 
}

int main() {
    cin >> n >> m >> k;
    // fRow[c]: hàng đầu tiên có chướng ngại trên cột c. Ví dụ: Cột 3 có vật cản ở hàng 2 và 5, thì fRow[3] = 2
    // fCol[r]: cột đầu tiên có chướng ngại trên hàng r
    vector<int> fRow(m + 2, n + 1);
    vector<int> fCol(n + 2, m + 1);
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        fRow[y] = min(fRow[y], x);
        fCol[x] = min(fCol[x], y);
    }
    int lc = fCol[1], lr = fRow[1]; //lc: Vị trí đầu tiên bị chặn xét từ trái qua ở hàng 1
    // Nếu (1,1) bị chặn thì không đi đâu được
    if (lc == 1 || lr == 1) {
        cout << 0;
        return 0;
    }
    ll A = 0, B = 0;
    for (int c = 1; c < lc; c++) A += fRow[c] - 1; //Số path đi phải trước, xuống sau
    for (int r = 1; r < lr; r++) B += fCol[r] - 1; //Số path đi xuống trước, phải sau
    // I = |A ∩ B| là số ô đi được theo cả 2 kiểu A và B
    vector<vector<int>> f(n + 2); //f[r]: Danh sách các cột mà hàng đầu tiên bị chặn là r
    for (int c = 1; c < lc; c++) {
        int fr = fRow[c];
        if (fr <= n) f[fr].push_back(c);
    }
    // Ban đầu tất cả cột sống
    for (int c = 1; c < lc; c++) upd(c, 1);
    ll I = 0;
    for (int r = 1; r < lr; r++) { //Hàng hiện tại đang xét
        // Loại các cột bị chặn đúng tại hàng r
        for (int c : f[r]) upd(c, -1);
        int lim = min(lc - 1, fCol[r] - 1);
        I += get(lim);
    }
    cout << A + B - I;
}

