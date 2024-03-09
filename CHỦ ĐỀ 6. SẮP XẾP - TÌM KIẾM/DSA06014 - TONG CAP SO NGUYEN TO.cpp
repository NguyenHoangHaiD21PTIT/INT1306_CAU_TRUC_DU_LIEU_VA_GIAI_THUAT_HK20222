#include<bits/stdc++.h>
using namespace std;

int a[1000005];//mang luu snt

void sangnt(){
	//1, Gia su tat ca la SNT
	for(int i=0;i<1000005;i++){
		a[i]=1;
	}
	a[1]=a[0]=0;
	//2, Xet cac so den can n. SO nao la SNT thi loai het cac boi cua no
	for(int i=0;i<=sqrt(1000005);i++){
		if(a[i]==1){
			for(int j=i*i;j<=1000005;j+=i){
				a[j]=0;
			}
		}
	}
}

int main(){
	int t;
	cin>>t;
	sangnt();
	while(t--){
		int n;
		cin>>n;
		int check =0;
		for(int i = 2;i<=n/2;i++){
			if(a[i]==1&&a[n-i]==1){
				cout<<i<<" "<<n-i;
				check = 1;
				break;
			}
		}
		if(check==0) cout<<-1;
		cout<<endl;
	}
}