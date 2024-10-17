#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;
int bit[MAXN]; 
int cnt = 0; 

void update(int idx, int val) {
    while (idx < MAXN) {
        bit[idx] += val;
        idx += idx & -idx;
    }
}

int get(int idx) {
    int sum = 0;
    while (idx > 0) {
        sum += bit[idx];
        idx -= idx & -idx;
    }
    return sum;
}

int find_kth(int k) {
    int l = 1, r = MAXN - 1, ans = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (get(mid) >= k) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return ans;
}

int main() {
    int Q;
    cin >> Q;
    while (Q--) {
        string q;
        cin >> q;
        if (q == "add") {
            int x;
            cin >> x;
            update(x, 1);
            cnt++;
        } else if (q == "del") {
            int x;
            cin >> x;
            update(x, -1);
            cnt--;
        } else if (q == "print") {
            int k = (cnt + 1) / 2; 
            cout << find_kth(k) << '\n';
        }
    }
} 
