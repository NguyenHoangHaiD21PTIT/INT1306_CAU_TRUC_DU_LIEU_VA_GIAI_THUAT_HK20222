#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O2")
#pragma GCC target("avx,avx2,fma")
#define faster() {ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
#define ll long long
#define pii pair<int, int>
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sqr(x) x*x
#define fi first
#define sc second
#define pb push_back
#define eb emplace_back
#define ins insert
#define sz size()
#define len length
#define mp make_pair
#define al(v) (v).begin(), (v).end()
#define sp << ' ' <<
#define endl '\n'
#define precision(x) setprecision(x) << fixed
#define nekonooke {cout << "Ame nara ashita wa hareru darou~"}
const int oo = 1e9+7;

//end of template
//?
ll count(ll x, ll digit) {
    ll power = 1, ans = 0;
    ll left = x, right = 0;
    while (left > 0) {
        ll current = left % 10;
        left /= 10;
        ans += left * power;
        if (current == digit) {
            ans += right + 1;
        } else if (current > digit) {
            ans += power;
        }
        power *= 10;
        right = x % power;
    }
    if (digit == 0) {
        ans -= (power - 1) / 9;
    }
    return ans;
}


void solve(){
	/*hav fun with coding*/
	ll a, b;
	cin >> a >> b;

    if (a == 0 and b == 0) return;
    if (a > b) swap(a, b);
    ll ans[10];

    for (int d = 0; d <= 9; ++d) {
        ans[d] = count(b, d);
        if (a - 1 > 0) ans[d] -= count(a - 1, d);
    }
    ll t = 0;
    for (int i=0; i<=9; i++) t+= ans[i]*i;
    cout << t;
}
main(){
	faster();
	int T = 1;
	cin >> T;
	while (T--){
		solve();
		cout << endl;
	}
	cerr << "Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s.\n";
	return 0;
}
