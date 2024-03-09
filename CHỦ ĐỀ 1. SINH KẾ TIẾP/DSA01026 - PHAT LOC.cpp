#include<bits/stdc++.h>
using namespace std;

int n, a[100], ok;

void kt(){
	for(int i=0;i<n;i++) a[i] = 6;
}

void sinh(){
	int i = n-1;
	while(i>=0&&a[i]==8){
		a[i] = 6;
		i--;
	}
	if(i==-1){
		ok = 0;
	} else {
		a[i] = 8;
	}
}

int check1(){ //Dieu kien chu so dau, cuoi, k co 2 so 8 ke nhau
	if(a[0]!=8||a[n-1]!=6){
		return 0;
	} else {
		for(int i=0;i<n-1;i++){
			if(a[i]==8&&a[i+1]==8)   return 0;
		}
		return 1;
	}
}

int check2(){//Khong co 4 so 6 ke nhau
	for(int i=1;i<n-3;i++){
		if(a[i]==6&&a[i+1]==6&&a[i+2]==6&&a[i+3]==6)   return 0;
	}
	return 1;
}

int main(){
	cin>>n;
	kt();
	ok=1;
	while(ok==1){
		if(check1()==1&&check2()==1){
			for(int i=0;i<n;i++){
				cout<<a[i];
			}
			cout<<endl;
		}
		sinh();
	}
}