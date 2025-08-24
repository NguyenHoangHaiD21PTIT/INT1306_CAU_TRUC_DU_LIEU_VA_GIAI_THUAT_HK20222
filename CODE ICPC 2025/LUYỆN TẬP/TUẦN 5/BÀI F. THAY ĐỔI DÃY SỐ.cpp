#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    // Dijkstra kiểu số thao tác để tăng từ 1 lên giá trị v theo luật: x --> x + [x / y]
    const int MAXB = 1000;
    vector<int> dist(MAXB + 1, 1e9);
    queue<int> q;
    dist[1] = 0;
    q.push(1);
    while(!q.empty()) {
        int v = q.front(); q.pop();
        for(int x = 1; x <= v; ++x) {
            int inc = v / x;
            if(inc == 0) break;// [v / x] = 0 tức là v < x, tăng thêm thì thương càng bé --> Vô nghĩa
            int nv = v + inc;
            if(nv > MAXB) continue; //Số phát sinh > 1000 thì bỏ, vì B đề cho chỉ đến 1e3 thôi
            if(dist[nv] > dist[v] + 1) {
                dist[nv] = dist[v] + 1;
                q.push(nv);
            }
        }
    }
    int T; cin >> T;
    while(T--) {
        int n; ll K;
        cin >> n >> K;
        vector<int> B(n), C(n);
        for(int i = 0; i < n; ++i) cin >> B[i];
        for(int i = 0; i < n; ++i) cin >> C[i];
        ll bsum = 0;           // Tổng thưởng chắc chắn, không cần thao tác
        vector<pair<int,int>> items; // {chi phí, thưởng}
        ll ssum = 0;           // Tổng chi phí các item hợp lệ
        for(int i = 0; i < n; ++i) {
            int b = B[i], c = C[i];
            if(b == 1) bsum += c;
            else {
                int d = dist[b]; //Số thao tác tối thiểu
                if(d <= K) {
                    items.push_back({d, c});
                    ssum += d;
                }
            }
        }
        // Xét những phần tử khả dụng thôi, nếu số thao tác > K thì tự động bỏ
        // Những phần tử có số thao tác <= K thì tạm thời đưa vào danh sách items
        // Tổng số thao tác cộng lại có thể > K, nhưng không sao vì knapsack sau này sẽ chọn tập con phù hợp
        // Đề bài cũng không bắt biển đổi hết tại mọi chỉ số, chọn tập con phù hợp là được
        int cap = min <ll> (K, ssum); // giới hạn tổng thao tác
        vector<ll> dp(cap + 1, 0);//dp[j]: GTLN đạt được khi không làm quá j thao tác
        for(auto &it : items) {
            int w = it.first, val = it.second;
            for(int j = cap; j >= w; --j) dp[j] = max(dp[j], dp[j - w] + val);
            //Chọn vật này, thì còn lại tối đa j - w thao tác. Nhưng thưởng lại tăng thêm
        }
        ll best = 0;
        for(int j = 0; j <= cap; ++j) best = max(best, dp[j]);
        cout << (bsum + best) << '\n';
    }
}
