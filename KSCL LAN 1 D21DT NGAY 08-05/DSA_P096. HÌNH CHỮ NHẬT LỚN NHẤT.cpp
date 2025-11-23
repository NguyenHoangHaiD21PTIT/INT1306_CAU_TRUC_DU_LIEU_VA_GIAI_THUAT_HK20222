#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        int a[n][m];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++)  cin >> a[i][j];
        }
        // h[i][j]: Từ ô (i,j) đếm lên trên có bao nhiêu ô 1 liên tiếp
        int h[n][m];
        memset(h, 0, sizeof(h)); 
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!i) h[i][j] = a[i][j];
                else{
                    if(a[i][j]) h[i][j] = h[i - 1][j] + 1;
                    else h[i][j] = 0;
                }
            }
        }
        int ans = 0;
        vector<pair<int, int>>vp;
        for(int i = 0; i < n; i++){
            // Thực hiện bài toán Histogram trên mảng 1D. Mỗi hàng là một mảng 1D.
            int l[m], r[m];
            stack<int> st1, st2;
            for(int j = m - 1; j >= 0; j--){
                while(!st1.empty() && h[i][j] <= h[i][st1.top()]) st1.pop();
                if(st1.empty()) r[j] = m - 1;
                else r[j] = st1.top() - 1;
                st1.push(j);
            }
            for(int j = 0; j < m; j++){
                while(!st2.empty() && h[i][j] <= h[i][st2.top()]) st2.pop();
                if(st2.empty()) l[j] = 0;
                else l[j] = st2.top() + 1;
                st2.push(j);
            }
            int res = 0;
            for(int j = 0; j < m; j++){
                res = max(res, (r[j] - l[j] + 1) * h[i][j]);
                vp.push_back({h[i][j], r[j] - l[j] + 1});
            }
            ans = max(ans, res);
        }
        pair <int, int>res;
        int dif = 1e9;
        for(auto x: vp){
            int S = x.first * x.second;
            if(S == ans && abs(x.first - x.second) < dif){
                dif = abs(x.first - x.second);
                res = x;
            }
        }
        if(res.first > res.second) swap(res.first, res.second);
        cout << res.first << " " << res.second << endl;
    }
}
