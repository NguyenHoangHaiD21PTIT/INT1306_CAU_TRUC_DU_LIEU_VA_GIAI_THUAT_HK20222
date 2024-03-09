#include<bits/stdc++.h>
using namespace std;

int n, a[100], b[100];//a: Mang de sinh, b: Mang ban dau

void kt(){
	for(int i = 0;i<n;i++){
		a[i] = i+1;
	}
}

int check(){
	for(int i=0;i<n;i++){
		if(a[i]!=b[i]) return 0;
	}
	return 1;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		kt();
		int stt = 0;
		for(int i=0;i<n;i++){
			cin>>b[i];
		}
		if(check()==1){
			stt = 1;
		} else {
			stt = 1;
			while(next_permutation(a,a+n)!=false){
				stt++;
				if(check()==1) break;
			}
		}
		cout<<stt<<endl;
	}
		
}