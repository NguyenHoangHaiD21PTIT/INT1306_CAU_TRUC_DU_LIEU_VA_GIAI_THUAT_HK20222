#include<bits/stdc++.h>
using namespace std;
using ll = long long; 

ll calc(ll x, ll y, string s){
	if(s == "+") return y + x;
	else if (s == "-") return y - x;
	else if (s == "*") return y * x;
	else return y / x;
}

bool toantu(string s){
	return (s == "+" || s == "-" ||s == "*" ||s == "/");
}

int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<string>v;
		for(int i = 0; i < n; i++){
			string s;
			cin>>s;
			v.push_back(s);
		}
		stack<ll>st;
		for(int i = 0; i < n; i++){
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
