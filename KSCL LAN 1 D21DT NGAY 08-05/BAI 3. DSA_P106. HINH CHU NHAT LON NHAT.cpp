#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        int a[n][m];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++)  cin >> a[i][j];
        }

        // Tính chiều cao của các cột chỉ khi có số 1
        int h[n][m];
        memset(h, 0, sizeof(h)); // Gán tất cả các phần tử trong h bằng 0
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i==0) h[i][j] = a[i][j];
                else{
                    if(a[i][j]==1) h[i][j] = h[i - 1][j] + 1;
                    else h[i][j] = 0;
                }
            }
        }

        // Tính diện tích lớn nhất của hình chữ nhật trên mỗi hàng chỉ xét các cột có chiều cao khác 0
        int ans = 0;
        vector<pair<int, int>>vp;
        for(int i = 0; i < n; i++){
            //Thực hiện bài toán HCN lớn nhất trên mỗi hàng
            //Như vậy, mỗi hàng ta sẽ chỉ xét các cột
            int l[m], r[m];// Tìm Vị trí phần tử đầu tiên bên trái, bên phải a[i] bé hơn a[i]
            //l, r là cận trái, phải của HCN
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
                vp.push_back({h[i][j],r[j] - l[j] + 1});
            }
            //Sau khi có HCN lớn nhất xét theo các cột chân chạm được đến hàng xét theo mỗi hàng, ta update
            ans = max(ans, res);
        }
        pair<int, int>res;
        int chenhlech = 1e9;
        for(auto x: vp){
            int S = x.first * x.second;
            if(S==ans&&abs(x.first - x.second)<chenhlech){
                chenhlech = abs(x.first - x.second);
                res = x;
            }
        }
        cout<<res.first<<" "<<res.second<<endl;
    }
    return 0;
}