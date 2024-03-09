#include<bits/stdc++.h>
using namespace std;

int n, a[100];

void kt(){
	for(int i = 1;i<=n;i++){
		a[i] = i;
	}
}

int check(){
	for(int i = 1;i<=n-1;i++){
		if(abs(a[i]-a[i+1])==1){
			return 0;
		}
	}
	return 1;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		kt();
		while(next_permutation(a+1,a+n+1)!=false){
			if(check()==1){
				for(int i =1 ;i<=n;i++){
					cout<<a[i];
				}
				cout<<endl;
			}
		}
		cout<<endl;
	}
}