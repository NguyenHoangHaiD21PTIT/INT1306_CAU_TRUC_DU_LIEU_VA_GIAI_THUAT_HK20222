#include<bits/stdc++.h>
using namespace std;

long long calc(long long x, long long y, string s){
	if(s=="+") return x + y;
	else if (s=="-") return x - y;
	else if (s=="*") return x * y;
	else return x/y;
}

int toantu(string s){
	if(s=="+"||s=="-"||s=="*"||s=="/") return 1;
	else return 0;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<string>v;
		while(n--){
			string s;
			cin>>s;
			v.push_back(s);
		}
		stack<long long>st;
		for(int i = v.size()-1;i>=0;i--){
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
		cout<<st.top()<<endl;
	}
}
/*
3
7
- + 2 * 3 1 9
7
- + 8 * 7 5 9
3
+ -10 -4 */