#include<bits/stdc++.h>
using namespace std;

int n, a[100], ok, b[100];//ok: con sinh duoc hay khong

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
		int n1;//So ban dau
		cin>>n1;
		int n2 =2;//Tang tu 2 den n1 theo buoc nhay 2
		while(n2<=n1){
			//Thuc hien thuat toan sinh voi moi n
			n = n2/2;
			kht();
			ok=1;
			while(ok==1){
				for(int i = 0;i<n;i++){
					b[i] = a[n-i-1];
				}
				for(int i = 0;i<n;i++) cout<<a[i];
				for(int i = 0;i<n;i++) cout<<b[i];
				cout<<" ";
				sinh();
			}
			n2+=2;
		}
		cout<<endl;
	}
}