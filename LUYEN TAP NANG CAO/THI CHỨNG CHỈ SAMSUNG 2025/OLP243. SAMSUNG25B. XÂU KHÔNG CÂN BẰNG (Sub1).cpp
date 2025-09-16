#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;

int n, k;
string s, st;//s: Xâu gốc, st: Xâu trạng thái (Gom các vị trí có dấu ?)
vector<int> q;
int ok;

//Check đối xứng 1 xâu bắt đầu từ chỉ số l, dài k → en - l + 1 = k → en = k + l - 1
bool pal(string t, int l, int k){
    int r = l + k - 1;
    while(l < r){
        if(t[l] != t[r]) return false;
        l++, r--;
    }
    return true;
}

//Check xâu không có xâu con liên tiếp độ dài K nào đối xứng
bool good(string t){
    for(int i = 0; i + k <= n; i++){
        if(pal(t, i, k)) return false;
    }
    return true;
}

void nxt(){
    int i = st.size() - 1;
    while(i >= 0 && st[i] == 'B'){
        st[i] = 'A';
        i--;
    }
    if(i == -1) ok = 0;
    else st[i] = 'B';
}

int main(){
    cin >> n >> k >> s;
    //Lấy các vị trí có dấu ?
    for(int i = 0; i < n; i++){
        if(s[i] == '?') q.push_back(i);
    }
    int m = q.size();
    long long ans = 0;
    st = string(m, 'A'); ok = 1;
    while(ok){
        string t = s;
        //Có m vị trí có dấu ?Xâu state sinh nhị phân trên 06 vị trí ứng với 6 index
        //State B A B A A B A
        //Index 0 1 2 3 4 5 6
        //Value 1 3 4 5 8 9 11. Chẳng hạn: state[2] = B → Index 2 thì ứng với value 4 trong q. Mà q lưu pos dấu ? trong xâu gốc 
        for(int i = 0; i < m; i++) t[q[i]] = st[i];
        if(good(t)) ans++;
        nxt();
    }
    cout << ans;
}
