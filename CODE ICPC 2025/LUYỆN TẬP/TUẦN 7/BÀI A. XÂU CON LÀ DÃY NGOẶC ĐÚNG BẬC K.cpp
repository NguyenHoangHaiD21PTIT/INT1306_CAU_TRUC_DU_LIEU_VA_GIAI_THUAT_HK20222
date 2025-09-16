#include<bits/stdc++.h>
using namespace std; 
const int N = 1e3 + 7, p = 1e9 + 7;
int Pow[N], h[N]; 

void pre(){
    Pow[0] = 1;
    for(int i = 1; i < N; i++) Pow[i] = (Pow[i - 1] * 31) % p;
}

int get(int l, int r){
    return (h[r] - h[l - 1] * Pow[r - l + 1] % p + p) % p;
}

void solve(string s, int k){
    int n = s.size();
    s = " " + s; 
    h[0] = 0;
    for(int i = 1; i <= n; i++) h[i] = (h[i - 1] * 31 + (s[i] - '(' + 1)) % p;
    set<int> st;
    //Độ sâu là k thì ít nhất bên trái có k mở, bên phải có k đóng --> min = 2k, end = n, end - st + 1 = 2k --> st = n + 1 - 2k
    for(int i = 1; i <= n - 2 * k + 1; i++) { //Start
        stack<int> S;
        int mx = 0;
        for(int j = i; j <= n; j++) { //End
            if (s[j] == '(') S.push(S.size() + 1);
            // Gặp dấu mở ngoặc thì tăng độ sâu. Ví dụ: St rỗng, gặp (, push 1; Gặp tiếp (, push 2
            else {
                if (S.empty()) { //Đóng không có mở tương ứng thì đó là ngoặc sai
                    mx = -1; 
                    break; 
                }
                //Đóng có mở tương ứng thì cập nhật độ sâu tiềm năng (Độ sâu ảo - Số dấu mở đang chờ)
                mx = max(mx, S.top());
                S.pop();
            }
            if (mx < 0 || mx > k) break;
            if (mx == k && S.empty()) st.insert(get(i, j));
        }
    }
    cout << st.size() % p << "\n";
}

int main(){
    pre();
    int t; cin >> t;
    while (t--){
        string s; int k;
        cin >> s >> k;
        solve(s, k);
    }
}
