#include<bits/stdc++.h>
using namespace std;

int n, a[100], ok;//ok: con sinh duoc hay khong

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
	for(int i = 1;i<=n/2;i++){
		if(a[i]!=a[n-i+1]) return 0;
	}
	return 1;
}

int main(){
	cin>>n;
	ok=1;
	kht();
	while(ok==1){
		if(check()==1){
			for(int i=1;i<=n;i++){
			    cout<<a[i]<<" ";
			}
			cout<<endl;
		}
		sinh();
	}
}
