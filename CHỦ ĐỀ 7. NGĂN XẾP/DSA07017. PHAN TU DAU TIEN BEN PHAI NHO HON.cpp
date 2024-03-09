#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		for(int i = 0 ;i<n;i++) cin>>a[i];
		//s[i] luu gia tri phan tu dau tien ben phai nho hon cua moi phan tu a[i]
		stack<int>st1; int s[n];
		for(int i = n - 1;i>=0;i--){
			while(!st1.empty()&&a[i]<=a[st1.top()]) st1.pop();
			if(st1.empty()) s[i] = -1;
			else s[i] = a[st1.top()];
			st1.push(i);
		}
		//g[i] luu vi tri phan tu ben phai dau tien lon hon cua moi phan tu a[i]
		stack<int>st2; int g[n];
		for(int i = n - 1;i>=0;i--){
			while(!st2.empty()&&a[i]>=a[st2.top()]) st2.pop();
			if(st2.empty()) g[i] = -1;
			else g[i] = st2.top();
			st2.push(i);
		}
		for(int i = 0;i<n;i++){
			if(g[i]==-1) cout<<-1<<" ";
			else cout<<s[g[i]]<<" ";
		}
		cout<<endl;
	}
}