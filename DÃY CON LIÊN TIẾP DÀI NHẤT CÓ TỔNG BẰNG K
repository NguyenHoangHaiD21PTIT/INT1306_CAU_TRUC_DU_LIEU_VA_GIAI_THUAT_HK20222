#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n + 5];
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int K;
    cin >> K;

    unordered_map<int, int> mp;
    mp[0] = 0; // Khởi tạo tổng bằng 0 với độ dài dãy con là 0
    int sum = 0;
    int maxLen = 0; // Độ dài của dãy con liên tiếp lớn nhất có tổng bằng K
    for(int i = 1; i <= n; i++) {
        sum += a[i];
        if(mp.find(sum - K) != mp.end()) {
            // Nếu tồn tại một tổng trước đó có giá trị là sum - K
            // thì cập nhật độ dài của dãy con liên tiếp lớn nhất
            maxLen = max(maxLen, i - mp[sum - K]);
        }
        if (mp.find(sum) == mp.end()) {
            // Chỉ cập nhật tổng mới vào mp nếu nó chưa tồn tại
            mp[sum] = i;
        }
    }
    cout << maxLen << endl;
    return 0;
}
