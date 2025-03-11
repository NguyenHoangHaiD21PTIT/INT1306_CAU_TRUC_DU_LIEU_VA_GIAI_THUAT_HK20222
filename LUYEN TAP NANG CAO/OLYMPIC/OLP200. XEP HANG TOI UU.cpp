#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MAX_N = 1e6 + 5;
const ll INF = 1e18;

ll n;
pair<ll, ll> pos[MAX_N], sortedX[MAX_N], sortedY[MAX_N];

bool cmp(pair<ll, ll> a, pair<ll, ll> b) {
    return a.second < b.second;
}

ll cal(ll medIdx) { //chi so cua trung vi
    ll medX = sortedX[medIdx].first;//toa do cua trung vi sau khi sap xep cac diem theo x
    ll medY = sortedY[medIdx].second;//toa do cua trung vi sau khi sap xep cac diem theo y
    ll eX = 0, eY = 0;//tong nang luong di chuyen theo 2 cach: ve trung vi cua x, cua y
    ll curX = medX, curY = medY;
    //Co dinh toa do cac diem ve X, di chuyen gan ve midY nhat co the
    //Nen phuong an 1: medX giu nguyen, curY ban dau la trung vi roi dich xa dan them 1
    for (ll i = medIdx; i <= n; i++) {
        eY += abs(sortedY[i].first - medX) + abs(sortedY[i].second - curY);
        curY++;
    }
    curY = medY - 1;
    for (ll i = medIdx - 1; i >= 1; i--) {
        eY += abs(sortedY[i].first - medX) + abs(sortedY[i].second - curY);
        curY--;
    }
    
    for (ll i = medIdx; i <= n; i++) {
        eX += abs(curX - sortedX[i].first) + abs(medY - sortedX[i].second);
        curX++;
    }
    curX = medX - 1;
    for (ll i = medIdx - 1; i >= 1; i--) {
        eX += abs(curX - sortedX[i].first) + abs(medY - sortedX[i].second);
        curX--;
    }
    
    return min(eX, eY);
}

int main() {
    cin >> n;
    for (ll i = 1; i <= n; i++) {
        cin >> pos[i].first >> pos[i].second;
        sortedX[i] = sortedY[i] = pos[i];
    }
    sort(sortedX + 1, sortedX + n + 1);
    sort(sortedY + 1, sortedY + n + 1, cmp);
    cout << cal((n + 1) / 2);
}

