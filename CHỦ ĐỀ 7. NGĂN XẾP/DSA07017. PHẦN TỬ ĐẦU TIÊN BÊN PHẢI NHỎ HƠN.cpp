#include<bits/stdc++.h>
using namespace std;
int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		int a[n];
		for(int i = 0; i < n; i++) cin >> a[i];
		//g[i]: Lưu vị trí của phần tử đầu tiên bên phải a[i] mà > a[i]
		stack<int>st2; int g[n];
		for(int i = n - 1; i >= 0;i--){
			while(!st2.empty() && a[i] >= a[st2.top()]) st2.pop();
			if(st2.empty()) g[i] = -1;
			else g[i] = st2.top();
			st2.push(i);
		}
		//s[i]: Lưu vị trí của phần tử đầu tiên bên phải a[i] mà <>> a[i]
		stack<int>st1; int s[n];
		for(int i = n - 1;i >= 0; i--){
			while(!st1.empty() && a[i] <= a[st1.top()]) st1.pop();
			if(st1.empty()) s[i] = -1;
			else s[i] = a[st1.top()];
			st1.push(i);
		}
		for(int i = 0; i < n; i++){
			if(g[i] == -1) cout << -1 << " ";
			else cout << s[g[i]] << " ";
		}
		cout << endl;
	}
}
/*
5, 1, 9, 2, 5, 1, 9, 7. Giả sử khi ta tìm phần tử đầu tiên bên phải a[i] và lớn hơn a[i], nếu lưu giá trị. Ví dụ: Phần tử bên phải đầu tiên > 5 là 9.
Nhưng có tận 2 số 9. Vậy thì tí nữa lấy con 9 nào để tìm phần tử đầu tiên bên phải và nhỏ hơn? */
