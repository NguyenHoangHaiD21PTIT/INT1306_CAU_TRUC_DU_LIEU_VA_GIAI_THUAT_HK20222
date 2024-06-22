#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        stack<string> st;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == ']' || isalpha(s[i])) {
                st.push(string(1, s[i]));
            } else if (s[i] == '[') {
                string tmp = "";
                while (st.top() != "]") {
                    tmp += st.top();
                    st.pop();
                }
                st.pop(); // pop ']'
                st.push(tmp);
            } else {
                string tmp = "";
                while (i >= 0 && isdigit(s[i])) {
                    tmp += string(1, s[i]);
                    i--;
                }
                i++;
                reverse(tmp.begin(), tmp.end());
                string tmp1 = st.top(); st.pop();
                string repeated_str = "";
                for (int j = 0; j < stoi(tmp); j++) repeated_str += tmp1;
                st.push(repeated_str);
            }
        }
        while(!st.empty()){
            cout<<st.top();
            st.pop();
        }
        cout<<endl;
    }
    return 0;
}
