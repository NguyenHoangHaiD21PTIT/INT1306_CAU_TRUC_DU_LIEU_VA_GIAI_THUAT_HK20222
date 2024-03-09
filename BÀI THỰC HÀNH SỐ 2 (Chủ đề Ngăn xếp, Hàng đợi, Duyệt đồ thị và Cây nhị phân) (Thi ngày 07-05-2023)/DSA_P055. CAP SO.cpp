#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, ans = 0;
    stack<int> st;
    map<int, int> cnt;
    cin >> n;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        while (!st.empty() && x > st.top()){
            cnt[st.top()]--;
            st.pop();
            ans++;
        }
        if (!st.empty()){
            if (x == st.top()){
               ans += cnt[x] + (st.size() > cnt[x]);
            }
            else ans += 1;
        }
        st.push(x);
        cnt[x]++;
    }
    cout << ans << endl;  
}