#include<bits/stdc++.h>
using namespace std;

int n, a[100], ok;//ok: con sinh duoc hay khong

void kht(){
	for(int i=0;i<n;i++){
		a[i]=0;
	}
}

void sinh(){
	int i=n-1;//xet tu bit cuoi cung
	while(i>=0&&a[i]==1){
		a[i]=0;
		i--;
	}
	if(i==-1){//da den xau cuoi
	    ok=0;//
	} else {
		a[i]=1;
	}
}



int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		kht();
		ok=1;
		cout<<pow(2,n)<<endl;
		while(ok==1){
			for(int i=0;i<n;i++){
				if(a[i]==0){
					cout<<6;
				} else {
					cout<<8;
				}
			}
			cout<<" ";
			sinh();
		}
		cout<<endl;
	}
}
		