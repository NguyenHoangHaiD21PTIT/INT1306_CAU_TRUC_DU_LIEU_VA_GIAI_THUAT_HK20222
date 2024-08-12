#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int MAXN = 100009;
int n, a[MAXN];
ll BIT[MAXN]; // BIT[i]: Tổng các số a[j], j thuộc cây con gốc i

//Tăng x và cha của x lên p đơn vị
void update(int x, int p) {
    while (x <= n) {
        BIT[x] += p;
        x += x & (-x); //x mới = cha x cũ
    }
}

//a[1] + a[2] + ... + a[x]
ll getSum(int x) {
    ll res = 0;
    while (x > 0) {
        res += BIT[x];
        x -= x & (-x); // x mới = số lớn nhất, không vượt quá x và không là con của x
    }
    return res;
}

int main() {
    int q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        update(i, a[i]);
    }

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r;
            cin >> l >> r; // a[p] += x
            cout << getSum(r) - getSum(l - 1) << endl;
        } else {
            int x, y;
            cin>>x>>y;//a[x] = y
            update(x, y - a[x]);
            a[x] = y;
        }
    }
}
