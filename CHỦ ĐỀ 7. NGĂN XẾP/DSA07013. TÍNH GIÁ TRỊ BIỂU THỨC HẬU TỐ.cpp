#include<bits/stdc++.h>
using namespace std;

int cal(int a, int b, char c){
	if(c == '+') return a + b;
	if(c == '-') return a - b;
	if(c == '*') return a * b;
	if(c == '/') return a / b;
}

int f(string s){
	stack<int>st;
	for(int i = 0;i < s.size(); i++){
		if(isdigit(s[i])) st.push(s[i] - '0');
		else {
			int x = st.top(); st.pop();
			int y = st.top(); st.pop();
			int ans = cal(y, x, s[i]);
			st.push(ans);
		}
	}
	return st.top();
}
int main(){
	int t; cin >> t;
	while(t--){
		string s; cin >> s;
		cout << f(s) << endl;
	}
}
