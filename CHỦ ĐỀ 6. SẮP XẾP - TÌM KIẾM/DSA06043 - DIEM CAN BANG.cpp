#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		int tongtrai=0, tong=0;
		for(int i=0;i<n;i++){
			cin>>a[i];
			tong+=a[i];
		}
		int tongphai=tong;
		//Ban dau voi so a[0] thi tongtrai=0, tongphai=tong-a[i]
		int check=0;
		for(int i=0;i<n;i++){
			tongphai-=a[i];
			if(tongphai==tongtrai){
				cout<<i+1;
				check=1;
				break;
			}
			tongtrai+=a[i];	
		}
		if(check==0){
			cout<<-1;
		}
		cout<<endl;
	}
}