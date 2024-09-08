#include <bits/stdc++.h>
#define int long long
#define FOR(i,a,b) for (int i=(a);i<=(b);i++)
#define FOD(i,a,b) for (int i=(a);i>=(b);i--)
#define bit(x,y) ((x)>>(y))&1
#define pb push_back
#define ll long long
#define ii pair < int,int >
#define f first
#define s second
#define M 1000000000000000
using namespace std;
int a[20];
int C(int k, int n) {
    if (k == 1) return n;
    if (k == n) return 1;
    int ans = 1;
    FOR(i, 1, k) a[i] = n - i + 1;
    FOR(i, 2, k) {
        int y = i;
        FOR(j , 1, k) {
            int x = __gcd(y, a[j]);
            a[j] /= x;
            y /= x;
        }
    }
    FOR(i, 1, k) ans *= a[i];
    return ans;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int Case;
    cin >> Case;
    while (Case--) {
        int m;
        cin >> m;
        vector < ii > p;
        p.pb({m, 1});
        p.pb({m, m - 1});
        int gt = 1;
        FOR(k, 2, 50) {
            gt *= k;
            int l = 2 * k, r = ((pow(m, 1.0 / (float) k) + 1) * k);
            //cout << l << " " << r << '\n';
            int n = -1;
            while (l <= r) {
                int mid = (l + r) / 2;
                int val = C(k, mid);
                //cout << mid << " " << val << '\n';
                if (val == m) {
                    n = mid;
                    break;
                } else
                if (val < m) l = mid + 1;
                else r = mid - 1;
            }
            if (n != -1) {
                p.pb({n, k});
                p.pb({n, n - k});
            }
        }
        sort(p.begin(), p.end());
        p.resize(unique(p.begin(), p.end()) - p.begin());
        cout << p.size() << '\n';
        for (auto x : p) cout << '(' << x.f << "," << x.s << ')' << ' ';
        cout << '\n';
    }
    return 0;
}