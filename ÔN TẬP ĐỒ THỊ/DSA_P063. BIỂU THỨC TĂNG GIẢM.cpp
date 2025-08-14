#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    for(int i = 1;i <= t;i++){
        string s;
        cin >> s;
        stack<int> st;
        int cur = 1;  
        cout << "Test " << i << ": ";
        for(int i = 0; i <= s.size(); i++){
            st.push(cur++);
            if (i == s.size() || s[i] == 'I') {
                while (!st.empty()) {
                    cout << st.top();
                    st.pop();
                }
            }
        }
        cout << endl;
    }
}

