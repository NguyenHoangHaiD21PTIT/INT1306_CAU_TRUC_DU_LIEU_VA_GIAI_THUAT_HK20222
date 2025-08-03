#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 998244353;

int main() {
    int t; cin >> t;
    while (t--) {
        int n, k;  cin >> n >> k;
        vector<int> a(n);
        map<int, int> freq;
        for (int& x : a) {
            cin >> x;
            freq[x]++;
        }
        // Tiền xử lý lũy thừa 2
        int max_count = 0;
        for (auto& [x, cnt] : freq) max_count = max(max_count, cnt);
        vector<ll> pow2(max_count + 1, 1);
        for (int i = 1; i <= max_count; i++) pow2[i] = (pow2[i - 1] * 2) % MOD;
        // Gom các số theo phần dư modulo k
        map<int, vector<int>> gr;
        for (auto& [x, _] : freq) gr[x % k].push_back(x);
        // Xét từng nhóm đồng dư với k. Bởi vì đã không cùng số dư thì đương nhiên hiệu không thể bằng k
        ll res = 1;
        for (auto& [_, group] : gr) {
            sort(group.begin(), group.end());
            vector<vector<int>> seg;
            vector<int> cur;
            //Chia mỗi đoạn con thành các đoạn liên tiếp, sao cho mỗi đoạn con lập thành CSC công sai k
            for (int x : group) {
                if (cur.empty() || x - cur.back() == k) cur.push_back(x);
                else {
                    seg.push_back(cur);
                    cur = {x};
                }
            }
            if (!cur.empty()) seg.push_back(cur);
            ll total = 1; //Số đoạn con theo yêu cầu trong mỗi nhóm ĐỒNG DƯ
            // Tính số cách chọn phần tử từ từng dãy CSC công sai k sao cho không chọn 2 phần tử liên tiếp trong đó
            for (auto& seg : seg) {
                ll dp0, dp1; //dp0: Chọn từ đầu đến phần tử hiện tại mà không chọn phần tử hiện tại
                for (int i = 0; i < seg.size(); ++i) {
                    //Xét từng phần tử trong đoạn con, giả sử phần tử thứ i xuất hiện freq[x_i] = S lần
                    //Mỗi dãy con khác rỗng trích xuất từ S số này luôn thoả mãn vì chênh lệch giữa mọi cặp phần tử là 0
                    //Số cách chọn dãy: 2^S - 1
                    int x = seg[i];
                    ll ways = (pow2[freq[x]] - 1 + MOD) % MOD;
                    if (i == 0) {
                        //Với phần tử đầu tiên: 1 cách không chọn gì, hoặc trích dãy con từ S số seg[i]
                        dp0 = 1;
                        dp1 = ways;
                    } else {
                        //dp0: Chọn từ đầu đến i - 1 mà không chọn seg_(i - 1), dp1: có chọn seg_(i - 1)
                        ll new_dp0 = (dp0 + dp1) % MOD; //Không chọn thg hiện tại --> Kế thừa mọi cái cũ đã có
                        ll new_dp1 = (dp0 * ways) % MOD; //Chọn thg hiện tại --> Không được chọn thg kề trước đó
                        dp0 = new_dp0;
                        dp1 = new_dp1;
                    }
                }
                total = (total * ((dp0 + dp1) % MOD)) % MOD;
            }
            res = (res * total) % MOD;
        }
        cout << (res - 1 + MOD) % MOD << '\n';
    }
}
/*Cách giải: 
1. Đếm số lần xuất hiện của mỗi phần tử
2. Chia các phần tử phân biệt (Chưa kể số lần xuất hiện), những cái nào đồng dư với k thì cùng một nhóm (gr)
Bởi vì không cùng số dư thì CHẮC CHẮN hiệu không thể bằng k
3. Với mỗi nhóm đồng dư gr, ta sắp xếp lại, tiếp tục chia thành các đoạn con liên tiếp seg, sao cho mỗi seg lập thành 1 CSC công sai k
4. Với mỗi seg, ta tính số cách tạo ra dãy con sao cho hiệu giữa 2 cặp bất kì khác k (Dùng dp)
*/
