#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, K; cin >> N >> K;
    //Nhập N xâu ký tự độ dài K
    vector<string> S(N);
    for (int i = 0; i < N; ++i) cin >> S[i];
    //Mảng P lưu hoán vị các chỉ số từ 0 đến K - 1, quy định thứ tự lấy các ký tự trong mỗi xaau
    vector<int> P(K);
    for (int i = 0; i < K; ++i) P[i] = i;
    int ans = INT_MAX; 
    do {
        vector<int> V; // V: Vector các số nguyên mới
        for (string s: S) {
            string t = ""; // t: Chuỗi tạm thời
            for (int i: P) t += s[i];
            V.push_back(stoi(t));
        }
        int max_v = *max_element(V.begin(), V.end());
        int min_v = *min_element(V.begin(), V.end());
        ans = min(ans, max_v - min_v);
    }while (next_permutation(P.begin(), P.end()));
    cout << ans << endl;
}
