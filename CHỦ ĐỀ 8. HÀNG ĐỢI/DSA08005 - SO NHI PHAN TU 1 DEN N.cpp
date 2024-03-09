#include<bits/stdc++.h>
using namespace std;

void in(int x){ //in ra dang nhi phan cua 1 so x
	string s = "";
	for(int i=15;i>=0;i--){
		if(x&(1<<i)){
			s = s+'1';
		} else {
			s = s+'0';
		}
	}
	int pos;//vi tri bit bat dau khac 0 tu phai sang cua xau tao thanh
	for(int i=0;i<=31;i++){
		if(s[i]!='0'){
			pos = i;
			break;
		}
	}
	// Day so 0 [0;pos-1]
	s.erase(0,pos);
	cout<<s<<" ";
}

int main(){
	int t;
	cin>>t;
	while (t--){
		int n;
		cin>>n;
		string s;
		for(int i=1;i<=n;i++){
			in(i);
		}
		cout<<endl;
	}
}