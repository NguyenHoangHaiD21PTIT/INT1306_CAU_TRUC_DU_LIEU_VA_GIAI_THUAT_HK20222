#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;
int bit[MAXN]; 
int cnt = 0; 

//BIT[x] lúc này lưu số phần tử của giá trị x
void update(int idx, int val) { //BIT[x] += val
    while (idx < MAXN) {
        bit[idx] += val;
        idx += idx & -idx;
    }
}

int get(int idx) { //Tổng tần suất các phần tử từ đầu đến idx
    int sum = 0;
    while (idx > 0) {
        sum += bit[idx];
        idx -= idx & -idx;
    }
    return sum;
}

int find_kth(int k) { //Tìm phần tử thứ k trong dãy số
    int l = 1, r = MAXN - 1, ans = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        //Chú ý là phải lùi đến khi nào không lùi được nữa mới dừng, vì pos tìm được có thể là pos "rác" (Thực tế trong mảng không có)
        //Bởi vì phần tử thứ k là vị trí mà ngay sau vị trí pos, với pos là vị trí cuối cùng tổng tần số < k
        if (get(mid) >= k) {
            //get (mid): freq[0] + freq[1] + ... + freq[mid]
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return ans;
}

int main() {
    int Q; cin >> Q;
    while (Q--) {
        string q; cin >> q;
        if (q == "add") {
            int x; cin >> x;
            update(x, 1); cnt++;
        } else if (q == "del") {
            int x; cin >> x;
            update(x, -1);
            cnt--;
        } else if (q == "print") {
            int k = (cnt + 1) / 2; 
            cout << find_kth(k) << '\n';
        }
    }
} 
