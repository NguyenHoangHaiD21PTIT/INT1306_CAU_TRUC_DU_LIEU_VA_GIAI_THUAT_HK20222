#include <bits/stdc++.h>
using namespace std;

// Tìm vị trí đầu tiên >= x trong mảng đã sắp xếp xét trong đoạn chỉ số[L..R]
int lower_bound(vector<int>& arr, int L, int x) {
    int R = arr.size() - 1;
    while (L < R) {
        int mid = (L + R) / 2;
        if (arr[mid] < x) L = mid + 1;
        else R = mid;
    }
    return L;
}

// Đếm số phần tử trong mảng đã sắp xếp không vượt quá giá trị x cho trước với chỉ số trong đoạn [L; R]
int cnt(vector<int>& arr, int l, int x) {
    if (l >= arr.size() || arr[l] > x) return 0;
    int pos = lower_bound(arr, l, x);
    if (arr[pos] > x) pos -= 1;
    return pos - l + 1;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    stack<int> st, st1;
    int l[n], r[n];
    // Phần tử bên trái đầu tiên lớn hơn
    for (int i = 0; i < n; i++) {
        while (!st.empty() && a[st.top()] <= a[i]) st.pop();
        if (st.empty()) l[i] = -1;
        else l[i] = st.top();
        st.push(i);
    }
    // Phần tử bên phải đầu tiên lớn hơn
    for (int i = n - 1; i >= 0; i--) {
        while (!st1.empty() && a[st1.top()] <= a[i]) st1.pop();
        if (st1.empty()) r[i] = n;
        else r[i] = st1.top();
        st1.push(i);
    }

    set<int>s;
    for(int x: a) s.insert(x);
    vector<int>z;//z lưu những phần tử tăng dần phân biệt trong a
    for(int x: s) z.push_back(x);

    //m[a[i]] lưu các index p mà a[p] = a[i] gốc lúc đầu
    //first[a[i]]: Chỉ số đầu tiên bắt đầu xét trong mảng m[a[i]]
    int first[z.size() + 1] = {};
    vector<vector<int>> m(z.size());
    for (int i = 0; i < n; i++) {
        int pos = lower_bound(z, 0, a[i]);//Tìm vị trí phần tử a[i] trong mảng z
        a[i] = pos;
        m[a[i]].push_back(i);
    }
    long long res = 0;
    for (int i = 0; i < n; i++) {
        if (l[i] != -1) res+= 1;
        if (r[i] != n) res+= 1;
        int x = cnt(m[a[i]], first[a[i]], r[i] - 1);
        res += (x - 1) * x / 2;
        first[a[i]] += x;
    }
    cout << res;
}
