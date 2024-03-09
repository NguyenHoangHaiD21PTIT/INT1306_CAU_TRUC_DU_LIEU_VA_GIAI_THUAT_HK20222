#include<bits/stdc++.h>
using namespace std;

int n, a[100], ok, b[100], k;//Mang a: Mang nhi phan, mang b: Mang so

void kt(){
	for(int i=0;i<n;i++){
		a[i] = 0;
	}
}

void sinh(){
	int i = n -1;
	while(i>=0&&a[i]==1){
		a[i] = 0;
		i--;
	}
	if(i==-1){
		ok = 0;
	} else {
		a[i] = 1;
	}
}

int main(){
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>b[i];
	}
	kt();
	ok=1;
	int ans = 0;
	while(ok==1){
		int tong = 0;
		for(int i=0;i<n;i++){
			if(a[i]==1)  tong+=b[i];
		}
		if(tong==k){
			for(int i=0;i<n;i++){
				if(a[i]==1) cout<<b[i]<<" ";
			}
			cout<<endl;
			ans++;
		}
		sinh();
	}
	cout<<ans<<endl;
}