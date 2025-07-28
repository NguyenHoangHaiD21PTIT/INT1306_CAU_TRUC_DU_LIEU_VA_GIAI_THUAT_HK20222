#include <bits/stdc++.h>
using namespace std;
/*Tóm tắt bài toán: Cho dãy A có N phần tử và số M. 
Tìm giá trị nhỏ nhất của t sao cho có thể gán mỗi a[i] một số lần x[i] ≤ t sao cho (a[i] + x[i]) % m tạo thành một dãy không giảm.
*/
int n, m, a[300005];
bool check(int t) {
    int cur = 0; //Mục tiêu mà phần tử hiện tại cần đạt được để dãy biến thành không giảm
    for (int i = 0; i < n; ++i) {
        int tmp = a[i] + t;
		if(tmp < m) { //Số dư = Chính nó
			if(cur > tmp) return false;
			cur = max(cur, a[i]);
		} else {
			int b = tmp % m;
			if(cur > b) cur = max(cur, a[i]);
		}
    }
    return true;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> a[i];
    int l = 0, r = m;
    while (l < r) {
        int mid = (l + r) / 2;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l;
}
//Sưu tầm
