#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct P { ll x, y; };

ll cp(P a, P b, P c) { //Tích có hướng của ab và ac
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

// Để 1 điểm nằm trong đa giác lồi, ta đi qua tất cả các cạnh của đa giác và điểm đó phải cùng phía với tất cả các cạnh
bool in(const vector<P>& h, P p) { //P có nằm trong đa giác lồi h ko?
    bool pos = 0, neg = 0;
    int n = h.size();
    for(int i = 0; i < n; ++i) {
        ll v = cp(h[i], h[(i + 1) % n], p);
        if(v > 0) pos = 1;
        if(v < 0) neg = 1;
        if(pos && neg) return 0;
    }
    return 1;
}

int main() {
    // Nhập đa giác lồi
    int n; cin >> n; vector<P> poly(n);
    for(int i = 0; i < n; ++i) cin >> poly[i].x >> poly[i].y;
    // Nhập các vector tịnh tiến
    int m; cin >> m; vector<P> tr(m);
    for(int i = 0; i < m; ++i) cin >> tr[i].x >> tr[i].y;
    int q; cin >> q;
    while(q--) {
        P a; cin >> a.x >> a.y;
        bool ok = 1;
        for(int i = 0; i < m; ++i) {
            // Thay vì tịnh tiến đa giác, điêm đứng yên thì ta cho đa giác đứng yên, điểm tịnh tiến ngược lại
            P ap = {a.x - tr[i].x, a.y - tr[i].y};
            if(!in(poly, ap)) {
                ok = 0;
                break;
            }
        }
        cout << (ok ? "Yes" : "No") << "\n";
    }
}

