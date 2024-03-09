#include<bits/stdc++.h>
using namespace std;

int main(){
	long long t;
	cin>>t;
	while(t--){
		long long n;
		cin>>n;
		long long a[n];
		for(long long i = 0;i<n;i++) cin>>a[i];
		stack<long long>st; //luu chi so cua cot hinh chu nhat
		long long res = -1e18;
		long long i = 0;
		while(i<n){
			if(st.empty()||a[i]>a[st.top()]){ //co the noi dai duoc them hinh chu nhat
				st.push(i);
				i++;
			} else { //Hinh chu nhat loang den i thi bi dut doan
				long long idx = st.top();
				st.pop();
				//Can phai la i, can trai la cai truoc idx strong st
				if(st.empty()) res = max(res, i * a[idx]);
				else res = max(res, a[idx] * (i - st.top()-1));
			}
		}
		while(!st.empty()){
			long long idx = st.top();
			st.pop();
			//Can phai la i, can trai la cai truoc idx strong st
			if(st.empty()) res = max(res, i * a[idx]);
			else res = max(res, a[idx] * (i - st.top()-1));
		}
		cout<<res<<endl;
	}
}