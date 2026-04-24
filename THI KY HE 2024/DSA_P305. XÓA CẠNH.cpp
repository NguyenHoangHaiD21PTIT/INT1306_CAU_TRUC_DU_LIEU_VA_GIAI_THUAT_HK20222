#include <bits/stdc++.h>
using namespace std;

int p[200005], s[200005], c[200005];//s[i]: Kích thước thành phần liên thông mà i là gốc

int root (int x){
    if (x == p[x]) return x;
    return p[x] = root(p[x]);
}

bool join (int x, int y){
    x = root (x); y = root(y);
    if (x == y) return false;
    if (s[x] < s[y]) swap(x, y);
    p[y] = x;
    s[x] += s[y];
    return true;
}

int main(){
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++){
        p[i] = i;
        s[i] = 1;
    }
    // Nhập danh sách cạnh
    vector <pair <int, int>> e(m + 1);
    for (int i = 1; i <= m; i++) cin >> e[i].first >> e[i].second;
    vector <bool> del (m + 1, false);//del[i] = T tức cạnh thứ i bị xoá
    vector <pair <int, int>> qr(q); //{Cạnh bị xoá, đỉnh cần check}
    for (int i = 0; i < q; i++){
        cin >> qr[i].first >> qr[i].second;
        del[qr[i].first] = true;
        c[qr[i].first]++;//Đếm số lần cạnh bị lặp
    }
    //Dựng đồ thị với các cạnh không ảnh hưởng
    for (int i = 1; i <= m; i++){
        if (!del[i]) join (e[i].first, e[i].second);
    }
    vector <int> ans(q);
    //Thêm ngược
    for (int i = q - 1; i >= 0; i--){
        int stt = qr[i].first, x = qr[i].second;
        ans[i] = s[root(x)];
        if (c[stt] == 1) join (e[stt].first, e[stt].second);
        c[stt]--;
    }
    for (int x: ans) cout << x << endl;
}
