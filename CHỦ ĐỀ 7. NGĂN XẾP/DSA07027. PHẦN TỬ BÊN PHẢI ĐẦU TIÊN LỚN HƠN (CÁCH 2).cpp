#include<bits/stdc++.h>
using namespace std;
int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		int a[n];
		for(int i = 0; i < n; i++) cin >> a[i];
		stack<int>st; 
		int r[n];
		for(int i = n - 1; i >= 0; i--){
			while(!st.empty() && a[i] >= a[st.top()]) st.pop();
			if(st.empty()) r[i] = -1;
			else r[i] =  a[st.top()];
			st.push(i);
		}
		for(int i = 0;i < n; i++) cout << r[i] << " ";
		cout << endl;
	}
}
