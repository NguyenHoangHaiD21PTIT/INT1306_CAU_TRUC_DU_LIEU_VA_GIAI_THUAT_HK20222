#include <bits/stdc++.h>
using namespace std;

int priority(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    return 0;
}

long long calc(long long x, long long y, string s){
	if(s=="+") return y + x;
	else if (s=="-") return y - x;
	else if (s=="*") return y * x;
	else return y/x;
}

int toantu(string s){
	if(s=="+"||s=="-"||s=="*"||s=="/") return 1;
	else return 0;
}

vector<string> hauTo(string s) {
    stack<char> st;
    vector<string> res;
    string num = "";
    for (size_t i = 0; i < s.size(); ++i) {
        if (isdigit(s[i])) { // Toán hạng
            num += s[i];
            if (i == s.size() - 1 || !isdigit(s[i + 1])) { // Kết thúc một số
                res.push_back(num);
                num = "";
            }
        } else if (s[i] == '(') {
            st.push(s[i]);
        } else if (s[i] == ')') {
            while (!st.empty() && st.top() != '(') {
                res.push_back(string(1, st.top()));
                st.pop();
            }
            st.pop(); // Xoá nốt dấu mở ngoặc tương ứng
        } else { // Toán tử
            while (!st.empty() && priority(st.top()) >= priority(s[i])) {
                res.push_back(string(1, st.top()));
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while (!st.empty()) {
        res.push_back(string(1, st.top()));
        st.pop();
    }
    return res;
}

long long kq(vector<string>v){
    stack<long long>st;
	for(int i = 0;i<v.size();i++){
		if(!toantu(v[i])){
			long long x = stoll(v[i]);
			st.push(x);
		} else {
			long long x1 = st.top(); st.pop();
			long long x2 = st.top(); st.pop();
			long long x3 = calc(x1, x2, v[i]);
			st.push(x3);
		}
	}
    return st.top();
}

int main() {
    int t;
    cin >> t;
    cin.ignore(); 
    while (t--) {
        string s;
        cin>>s;
        cout<<kq(hauTo(s))<<endl;
    }
}
