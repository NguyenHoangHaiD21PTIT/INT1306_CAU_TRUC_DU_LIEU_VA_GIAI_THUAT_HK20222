#include<bits/stdc++.h>
using namespace std;

vector<string>v;

int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i = 0;i<n;i++){
		a[i] = i + 1;
		cout<<a[i]<<" ";
	}
	cout<<endl;
	while(next_permutation(a, a+n)){
		int tong = 0;
		for(int i = 0;i<n - 1;i++) tong+=a[i] - a[i + 1];
		if(tong<0){
			for(int i = 0;i<n;i++) cout<<a[i]<<" ";
			cout<<endl;
		}
	}
}