#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll dist2(ll x1, ll y1, ll x2, ll y2) {
    ll dx = x2 - x1;
    ll dy = y2 - y1;
    return dx*dx + dy*dy;
}

int main() {
    ll xA, yA, xB, yB, xC, yC;
    cin >> xA >> yA >> xB >> yB >> xC >> yC;
    ll AB2 = dist2(xA, yA, xB, yB), BC2 = dist2(xB, yB, xC, yC), AC2 = dist2(xA, yA, xC, yC);
    if (AB2 + BC2 == AC2 || AB2 + AC2 == BC2 || AC2 + BC2 == AB2) cout << "Yes\n";
    else cout << "No\n";
}
