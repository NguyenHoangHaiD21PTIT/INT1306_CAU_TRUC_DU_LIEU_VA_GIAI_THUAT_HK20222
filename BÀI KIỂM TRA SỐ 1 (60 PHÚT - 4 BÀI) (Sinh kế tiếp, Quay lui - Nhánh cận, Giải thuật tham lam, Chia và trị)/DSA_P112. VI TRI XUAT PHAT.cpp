#include<bits/stdc++.h>
using namespace std;

int n, m, a[100007];
bool check(int x) {//Kiểm tra xem có thể xếp m tay đua sao cho kcach min giữa các tay đua >=x
    int cnt = 1, last = 1;//cnt: số xe đã xếp vị trí, last: vị trí của xe cuối cùng được xếp
    for (int i = 2; i <= n; i++) {
        if (a[i] - a[last] >= x) {
            ++cnt;
            if (cnt == m) return true;
            last = i;
        }
    }
    return false;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    int l = 0, r = 1e9, res = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            res = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << res;
}

