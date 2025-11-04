#include<bits/stdc++.h>
using namespace std;
int f[1000006];
int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		int a[n], r[n];
		for (int i = 0; i <= 1000001; i++) f[i] = 0;
 		for(int i = 0;i<n;i++){
			cin >> a[i];
			f[a[i]]++;
		}
		stack<int>st;
		for(int i = n - 1;i >= 0; i--){
			while(!st.empty() && f[a[i]] >= f[st.top()]) st.pop();
			if(st.empty()) r[i] = -1;
			else r[i] = st.top();
			st.push(a[i]);
		}
		for(int i = 0;i < n; i++) cout << r[i] << " ";
		cout << endl;
	}
}
