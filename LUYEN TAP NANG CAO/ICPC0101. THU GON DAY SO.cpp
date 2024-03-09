#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i = 0;i<n;i++) cin>>a[i];
	stack<int>st; //stack lưu các số mà không ghép cặp được thành tổng chẵn
	for(int i = 0;i<n;i++){
		if(st.empty()){ //stack rỗng --> Phần tử đang xét hiện tại không có số để ghép cặp
			st.push(a[i]);
		} else{
			if ((st.top() + a[i]) % 2 ==0) st.pop(); //Đã có cặp
			else st.push(a[i]);
		}
	}
	cout<<st.size();
}