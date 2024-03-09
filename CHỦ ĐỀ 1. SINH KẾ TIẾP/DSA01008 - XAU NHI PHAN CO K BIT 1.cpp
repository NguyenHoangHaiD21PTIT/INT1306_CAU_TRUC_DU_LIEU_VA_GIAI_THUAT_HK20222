#include<bits/stdc++.h>
using namespace std;
int n, k, a[100], ok;//ok: con sinh duoc hay khong, k: so bit 1, n: do dai

void kht(){
	for(int i=1;i<=n;i++){
		a[i]=0;
	}
}

void sinh(){
	int i=n;//xet tu bit cuoi cung
	while(i>=1&&a[i]==1){
		a[i]=0;
		i--;
	}
	if(i==0){//da den xau cuoi
	    ok=0;//
	} else {
		a[i]=1;
	}
}

int check(){
	int cnt = 0;
	for(int i=1;i<=n;i++){
		if(a[i]==1){
			cnt++;
		}
	}
	if(cnt==k){
		return 1;
	} else {
		return 0;
	}
}

int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>k;
		ok=1;
		kht();
		while(ok==1){
			if(check()==1){
			    for(int i=1;i<=n;i++){
			    	cout<<a[i];
			    }
				cout<<endl;
			}
		    sinh();
		}
	}
}
