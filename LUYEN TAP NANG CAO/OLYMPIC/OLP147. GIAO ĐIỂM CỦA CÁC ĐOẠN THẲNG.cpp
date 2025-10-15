#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXY = 2000005, OFFSET = 1000001;

ll bit[MAXY];
int n;

void upd(int idx, int val) {
    for (; idx < MAXY; idx += idx & -idx) bit[idx] += val;
}

ll get(int idx) {
    ll sum = 0;
    for (; idx > 0; idx -= idx & -idx) sum += bit[idx];
    return sum;
}

struct Evt {
    int x, y1, y2, type;
};

bool operator<(const Evt& a, const Evt& b) {
    if (a.x != b.x) return a.x < b.x;   
    return a.type < b.type;
}

int main() {
    cin >> n;
    vector<Evt> evts;
    for (int i = 0; i < n; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        y1 += OFFSET; y2 += OFFSET;
        if (y1 == y2) {
            if (x1 > x2) swap(x1, x2);
            evts.push_back({x1, y1, 0, 3}); 
            evts.push_back({x2, y1, 0, 1}); 
        } else {
            if (y1 > y2) swap(y1, y2);
            evts.push_back({x1, y1, y2, 2}); 
        }
    }
    sort(evts.begin(), evts.end());
    ll ans = 0;
    for (const auto& ev : evts) {
        if (ev.type == 3) upd(ev.y1, 1);
        else if (ev.type == 1) upd(ev.y1, -1);
        else {
            if (ev.y1 + 1 <= ev.y2 - 1) ans += get(ev.y2 - 1) - get(ev.y1);
        }
    }
    cout << ans;
}
