#include<bits/stdc++.h>
using namespace std;

int calc(int x, int y, char z){
	if(z == '+') return x + y;
	else if (z == '-') return x - y;
	else if (z == '*') return x * y;
	else return x / y;
}

int main(){
	int t; cin >> t;
	while(t--){
		string s; cin >> s;
		stack<int>st;
		for(int i = s.size() - 1; i >= 0;i--){
			if(isdigit(s[i])) st.push(s[i] - '0');
			else { 
				int x1 = st.top(); st.pop();
				int x2 = st.top(); st.pop();
				int x3 = calc(x1, x2, s[i]);
				st.push(x3);
			}
		}
		cout<<st.top()<<endl;
	}
}
