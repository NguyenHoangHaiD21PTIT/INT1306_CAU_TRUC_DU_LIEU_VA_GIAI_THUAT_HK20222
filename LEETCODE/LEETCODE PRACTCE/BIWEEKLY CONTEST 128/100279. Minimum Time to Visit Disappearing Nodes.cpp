class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        // Khởi tạo đồ thị
        vector<vector<pair<int, int>>> ke(n);
        for (auto& edge : edges) {
            int x = edge[0], y = edge[1], w = edge[2];
            ke[x].push_back({y, w});
            ke[y].push_back({x, w});
        }

        // Khởi tạo mảng khoảng cách và đánh dấu nút đã xử lý
        vector<int> d(n, INT_MAX);
        vector<bool> processed(n, false);

        // Bước 1: Khởi tạo hàng đợi ưu tiên ({d[v], v})
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        d[0] = 0;

        // Bước 2: Lặp
        while (!pq.empty()) {
        	//Lây ra đỉnh chưa xét có khoảng cách đến nút gốc là bé nhất
            int u1 = pq.top().second;
            pq.pop();
            if (processed[u1]) continue;
            processed[u1] = true;

			//Duyệt danh sách kề
            for (auto& [u2, w] : ke[u1]) {
                // Trước khi giảm thời gian thì phải đảm bảo đến trước khi nó biến mất
                if (d[u2] > d[u1] + w && (d[u1] + w < disappear[u2] || disappear[u2] == 0)) {
                    d[u2] = d[u1] + w;
                    pq.push({d[u2], u2});
                }
            }
        }

        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (d[i] == INT_MAX) result.push_back(-1);
            else result.push_back(d[i]);
        }
        return result;
    }
};