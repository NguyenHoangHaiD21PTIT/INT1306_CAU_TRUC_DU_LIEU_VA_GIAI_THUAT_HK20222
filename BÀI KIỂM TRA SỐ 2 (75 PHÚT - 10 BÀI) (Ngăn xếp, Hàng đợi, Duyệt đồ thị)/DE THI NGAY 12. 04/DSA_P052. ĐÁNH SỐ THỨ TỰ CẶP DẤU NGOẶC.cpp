#include<bits/stdc++.h>
using namespace std;
int main(){
	int t; cin >> t;
	cin.ignore();
	while(t--){
		string s;
		getline(cin, s);
		int cnt = 1;
		stack <int> st;
		for(char x: s){
			if(x == '('){
				st.push(cnt);
				cout << cnt++ << " ";
			} else if (x == ')'){
				cout << st.top() << " ";
				st.pop();
			}
		}
		cout << endl;
	}
}

