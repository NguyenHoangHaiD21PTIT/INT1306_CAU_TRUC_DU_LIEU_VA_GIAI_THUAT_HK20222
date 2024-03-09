#include<bits/stdc++.h>
using namespace std;

int main(){
	int c, n;//c: khoi luong
	cin>>c>>n;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	bool f[c+1] = {false}; //f[i] = true tuc la trong day co day con co tong bang i
	f[0] = true;
	for(int i=0;i<n;i++){
		for(int j = c;j>=a[i];j--){
			if(f[j-a[i]]==true) f[j] = true;
		}
	}
	for(int j = c; j>=0;j--){
		if(f[j]==true){
			cout<<j;
			return 0;
		}
	}
}