#include <bits/stdc++.h>
using namespace std;

struct Rect {
    long long w, h;
    int id; 
};
bool cmp(Rect A, Rect B){
    if(A.w != B.w) return A.w < B.w;
    return A.h < B.h;
}
int main() {
    int n; cin >> n;
    vector<Rect> a(n);
    for (int i = 0; i < n; ++i) {
        long long x, y;
        cin >> x >> y;
        long long w = min(x, y), h = max(x, y);
        a[i] = {w, h, i + 1};
    }
    sort(a.begin(), a.end(), cmp);
    //0 - based
    vector<long long> tail;        // tail[l] là phần tử nhỏ nhất ở cuối dãy dài l + 1, cố gằng càng nhỏ càng tốt để sau đó còn nối vào
    vector<int> tail_idx;          // chỉ số (theo mảng đã sắp) của phần tử kết thúc dãy dài l+1
    vector<int> prev_idx(n, -1);  //Ví dụ [a[2], a[5], a[8]], thì prev_idx[8] = 5
    for (int i = 0; i < n; ++i) {
        long long h = a[i].h;
        //Tìm l trong tail sao cho tail[l] > h
        int l = upper_bound(tail.begin(), tail.end(), h) - tail.begin(); 
        //Mọi số trong tail đều <= h thì nối h vào cuối
        if (l == (int)tail.size()) {
            tail.push_back(h);
            tail_idx.push_back(i);
        //Thay h vào vị trí l để tối ưu dãy
        } else {
            tail[l] = h;
            tail_idx[l] = i;
        }
        if (l > 0) prev_idx[i] = tail_idx[l - 1]; 
        else prev_idx[i] = -1; 
    }
    /*
    Dãy h = [2, 6, 3, 4]
    B1: 2 → tail = [2]
    B2: 6 → lớn hơn hết → tail = [2, 6]
    B3: 3 → tìm phần tử nhỏ nhất > 3 trong tail = 6, thay → tail = [2, 3]
    B4: 4 → lớn hơn hết → tail = [2, 3, 4]

    Vì sao dùng lower_bound bị sai
    [2, 2, 3]. 1. Upper_bound
    B1: 2 → tail = [2]
    B2: 2 → tìm phần tử nhỏ nhất > 2 trong tail không có → tail = [2, 2]
    B3: 3 → tìm phần tử nhỏ nhất > 3 trong tail không có → tail = [2, 2, 3]

    2. Lower_bound
    B2: 2 → tìm phần tử nhỏ nhất >= 2 trong tail = 2 → tail = [2] → SAI
    */
    cout << tail.size()<< "\n";
    vector<int> ans;
    int cur = tail_idx.back();
    while (cur != -1) {
        ans.push_back(a[cur].id); // id gốc
        cur = prev_idx[cur];
    }
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " ";
}
