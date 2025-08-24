#include <bits/stdc++.h>
using namespace std;

const int N = 600000 + 7;
const int MX = (1 << 19) + 1;
int a[N], freq[N];
int trie[N * 20][2], nodes;

int bit(int x, int i) {
    return (x >> i) & 1;
}

void insert_val(int x) {
    int u = 0;
    for (int i = 19; i >= 0; i--) {
        int b = bit(x, i);
        if (!trie[u][b]) trie[u][b] = ++nodes;
        u = trie[u][b];
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        freq[a[i]]++;
    }
    for (int i = 0; i < MX; i++) {
        if (!freq[i]) insert_val(i);
    }
    int mask = 0;
    while (q--) {
        int x; cin >> x;
        mask ^= x;
        int u = 0, ans = 0;
        for (int i = 19; i >= 0; i--) {
            int b = bit(mask, i);
            if (trie[u][b]) u = trie[u][b];
            else {
                ans += (1 << i);
                u = trie[u][b ^ 1];
            }
        }
        cout << ans << '\n';
    }
}
