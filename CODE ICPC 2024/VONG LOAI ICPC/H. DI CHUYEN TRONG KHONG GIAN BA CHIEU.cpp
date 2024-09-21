#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct Point{
    ll x, y, z;
};

ll cal(Point a, Point b) {
	ll dis = b.z - a.z;
	ll res = abs(b.x -a.x) + abs(b.y - a.y) + max(0LL, b.z - a.z);
	return res;
}

ll n, dp[1 << 18][18]; //dp[mask][i]: mask: Một số hệ 10, viết qua hệ 2 sẽ thấy đâu là phần tử được chọn
//mask = 5. 5 sang hệ 2 là 0101, từ phải qua trái tăng dần tức là phần tử thứ 0 và thứ 2 được chọn
//chiều thứ 2 của mảng dp: kết thúc tại điểm thứ
Point C[18];

int main() {
	cin >> n;
	for (ll i = 0; i < n; i++) cin >> C[i].x >> C[i].y >> C[i].z;
	for (ll mask = 0; mask < (1 << n); mask++) {
		for (ll i = 0; i < n; i++) dp[mask][i] = 1e9;
	}
	dp[1][0] = 0;//Những điểm đã đi: 000...1. Kết thúc tại điểm thứ 0
	for (ll mask = 1; mask < (1 << n); mask++) { //Duyệt mọi tập con
		if (__builtin_popcount(mask) == 1 || !(mask & 1)) continue;  //loai bo cac hanh trinh chi co 1 diem va khong xuat phat tu 1
		for (ll i = 0; i < n; i++) {//Duyệt qua những điểm sẽ là điểm kết thúc của hành trình
			if (i == 0) continue; //bat buoc phai di tu diem 1
			if (mask & (1 << i)) { //Nếu đã thăm điểm thứ i
				ll pre_mask = mask ^ (1 << i); //Loại bỏ điểm i đi
				for (ll j = 0; j < n; j++) {
					if (pre_mask & (1 << j)) dp[mask][i] = min(dp[mask][i], dp[pre_mask][j] + cal(C[j], C[i]));
				}
			}
		}
	}
	ll ans = 1e9;
	for (ll i = 1; i < n; i++) ans = min(ans, dp[(1 << n) - 1][i] + cal(C[i], C[0]));
	cout << ans << endl;
} 