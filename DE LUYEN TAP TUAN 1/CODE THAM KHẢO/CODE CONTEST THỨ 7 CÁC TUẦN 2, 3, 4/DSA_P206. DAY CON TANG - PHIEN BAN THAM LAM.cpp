#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    vector<vector<int>> seq(1); // seq[0] không dùng, bắt đầu từ 1
    int m = 0; // số dãy đã tạo
    for (int i = 1; i <= n; ++i) {
        int x; cin >> x;
        int pos = 0; // vị trí dãy mà x sẽ nối vào
        int left = 1, right = m;
        // Chặt nhị phân trên dãy STT các dãy con hiện có. Mục đích là tìm dãy con có STT nhỏ nhất mà phần tử cuối cùng của nó nhỏ hơn x.
        while (left <= right) {
            int mid = (left + right) / 2;
            if (seq[mid].back() < x) {
                pos = mid;
                right = mid - 1; //Xem có dãy nào có STT nhỏ hơn pos mà phần tử cuối cùng của nó cũng nhỏ hơn x không
            } else {
                left = mid + 1;
            }
        }
        if (pos == 0) {
            // Không nối vào đâu được → tạo dãy mới
            seq.push_back({x});
            m++;
        } else {
            // Nối vào dãy pos
            seq[pos].push_back(x);
        }
    }
    cout << m << "\n";
    for (int i = 1; i <= m; ++i) {
        for (int v : seq[i]) cout << v << " ";
        cout << "\n";
    }
}
