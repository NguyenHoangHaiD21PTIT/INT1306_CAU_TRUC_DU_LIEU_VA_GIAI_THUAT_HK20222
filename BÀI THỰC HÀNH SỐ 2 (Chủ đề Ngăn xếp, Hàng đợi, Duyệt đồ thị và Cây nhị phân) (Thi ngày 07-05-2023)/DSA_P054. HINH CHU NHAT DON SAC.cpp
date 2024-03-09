#include<bits/stdc++.h>
using namespace std;

long long kq(long long a[], long long n){
	long long res = -1e18;
	stack<long long>st; //luu chi so cua cot hinh chu nhat
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
	return res;
}

int main(){
	long long m, n;
	cin>>m>>n;
	long long a[n], b[n];
	for(int i = 0;i<n;i++) cin>>a[i], b[i] = m - a[i];
	long long res = -1;
	res = max(res, kq(a, n));
	res = max(res, kq(b, n));
	cout<<res<<endl;
}