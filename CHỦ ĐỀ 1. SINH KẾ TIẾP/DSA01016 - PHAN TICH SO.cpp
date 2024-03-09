#include<bits/stdc++.h>
using namespace std;

int n, a[100], ok, cnt;

void kt(){
	cnt=1;
	a[1]=n;
}

void sinh(){
	//1. Tim vi tri dau tien tu cuoi lai ma tai do a[i] khac 1
	int i=cnt;
	while(i>=1&&a[i]==1){
		i--;
	}
	//2. Kiem tra dieu kien sinh va thuc hien
	if(i==0){
		ok=0;
	} else {
		a[i]--;
		int bu=(cnt-(i+1)+1)+1;//Vi tu [i+1;cnt] la cac so 1 da bi bo va them 1 so 1 bi bo do giam a[i]
		//Tinh phan nguyen va phan du khi chia phan bu cho a[i]
		cnt=i;//So so hang khac 1 trong day
		int q=bu/a[i];
		int r=bu%a[i];
		if(q!=0){
			while(q--){
				cnt++;
				a[cnt]=a[i];
			}
		}
		if(r!=0){
			cnt++;
			a[cnt]=r;
		}
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		ok=1;
		kt();
		while(ok==1){
			cout<<"(";
			for(int i=1;i<=cnt-1;i++){
				cout<<a[i]<<" ";
			}
			cout<<a[cnt]<<")";
			cout<<" ";
			sinh();
		}
		cout<<endl;
	}
}