#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 1e5;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n; cin >> n;
		ll l[N], h[N];
		l[0] = 0; h[0] = 0;
		for (int i = 1; i <= n; i++) cin >> l[i];
		ll sumArray[N] = {0};//prefix sum
		vector<ll> sum; sum.push_back(0);//sum[i]: Lượng nước tối đa có thể lưu trữ đến bức tường thứ i
		cin >> h[1]; sum.push_back(h[1]); sumArray[1] = h[1];
		stack<pair<ll, ll>> st;//Lưu trữ chiều cao và vị trí bức tường
		st.push({h[1], 1});
		for (int i = 2; i <= n; i++) {
			cin >> h[i];
			sumArray[i] = sumArray[i - 1] + h[i];
			while (!st.empty() && st.top().first < h[i]) st.pop(); //Tìm bức tường gần nhất cao hơn or bằng bức tường hiện tại (Tìm chỗ tại đó nước bị chặn)
			if (st.empty()) {
				sum.push_back(h[i] * l[i] - sumArray[i - 1]);
				//Thể tích nước nếu chỉ có bức tường thứ i là: h[i] * [(l[i] - 1) - 0 + 1], nhưng ta phải trừ đi tổng chiều cao các bức tường trước đó "ăn" vào thể tích nước
			} else {
				ll idx = st.top().second;
				sum.push_back(sum.back() + h[i] * (l[i] - l[idx] - 1) - (sumArray[i - 1] - sumArray[idx]));
				//sum.back(): Tổng thể tích nước lưu trữ đến bức tường thứ i - 1
				//l[i] - l[idx] - 1: Nếu giữa bức thứ i và bức thứ idx không có bức tường nào thì toàn bộ nước sẽ trữ được từ vị trí thứ idx + 1 đến i - 1 -->(l[i] - 1) - (l[idx] + 1) + 1
				//sumArray[i - 1] - sumArray[idx]: Trừ đi tổng chiều cao các bức tường đã ăn vào thể tích nước trong vùng từ idx + 1 đến i - 1, nghĩa là tổng các bước tường từ idx+1 đến i - 1
			}
			st.push({ h[i] , i });
		}
		int q;
		cin >> q;
		while (q--) {
			ll k; cin >> k;
			auto x = lower_bound(sum.begin(), sum.end(), k);
			if (x == sum.end()) cout << sum.size() << endl;
			else cout << x - sum.begin() - 1 << endl;
		}
	}
}
