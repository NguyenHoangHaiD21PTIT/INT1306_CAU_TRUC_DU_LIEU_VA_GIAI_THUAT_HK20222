#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll calc(ll x, ll y, string s){
	if(s == "+") return x + y;
	else if (s == "-") return x - y;
	else if (s == "*") return x * y;
	else return x  /y;
}

int toantu(string s){
	if(s == "+" ||s == "-" ||s == "*" ||s == "/") return 1;
	else return 0;
}

int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector <string> v;
		while(n--){
			string s; cin >> s;
			v.push_back(s);
		}
		stack<ll>st;
		for(int i = v.size() - 1; i >= 0; i--){
			if(!toantu(v[i])) st.push(stoll(v[i]));
			else {
				ll x1 = st.top(); st.pop();
				ll x2 = st.top(); st.pop();
				st.push(calc(x1, x2, v[i]));
			}
		}
		cout << st.top() << endl;
	}
}
