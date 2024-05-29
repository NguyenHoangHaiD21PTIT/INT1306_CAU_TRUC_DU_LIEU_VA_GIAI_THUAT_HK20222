#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        queue<int> q;

        // Xử lý cửa sổ đầu tiên
        for(int i = 0; i < k; i++) {
            if(a[i] < 0) q.push(i);
        }

        if(!q.empty()) cout << a[q.front()] << " ";
        else cout << "0 ";

        // Xử lý các cửa sổ kết thúc tại vị trí i
        for(int i = k; i < n; i++) {
            // Loại bỏ phần tử âm đầu tiên nếu nó không thuộc cửa sổ hiện tại
            if(!q.empty() && q.front() <= i - k) q.pop();
            if(a[i] < 0) q.push(i);
            if(!q.empty()) cout << a[q.front()] << " ";
            else cout << "0 ";
        }
        cout << endl;
    }
    return 0;
}
