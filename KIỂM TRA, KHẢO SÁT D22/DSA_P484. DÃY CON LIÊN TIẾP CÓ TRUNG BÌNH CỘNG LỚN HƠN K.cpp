#include<bits/stdc++.h>
using namespace std;   
using ll = long long;

int main(){
    int n; ll K;
    cin >> n >> K;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<ll> b (n + 1, 0);
    for (int i = 0; i < n; i++) b[i + 1] = b[i] + a[i] - K;
    stack<int>st;
    for(int i = 0; i <= n; i++){
        if (st.empty() || b[i] < b[st.top()]) st.push(i);
    }
    int res = 0;
    for(int i = n; i >= 0; i--){
        while(!st.empty() && b[i] >= b[st.top()]){
            res = max(res, i - st.top());
            st.pop();
        }
    }
    cout << res;
}
