#include<bits/stdc++.h>
using namespace std;

int a[8], ok;

void kt(){
	for(int i=0;i<8;i++){
		a[i] = 0;
	}
}

void sinh(){
	int i = 7;
	while(i>=0&&a[i]==2){
		a[i] = 0;
		i--;
	}
	if(i==-1){
		ok = 0;
	} else {
		a[i] = 2;
	}
}

int check(){
	if((a[0]==0&&a[1]==0)||(a[4]==0)||(a[2]!=0||a[3]!=2)){
		return 0;
	} else {
		return 1;
	}
}


int main(){
	kt();
	ok = 1;
	while(ok==1){
		if(check()==1){
			for(int i=0;i<8;i++){
				cout<<a[i];
				if(i==1||i==3){
					cout<<"/";
				}
			}
			cout<<endl;
		}
		sinh();
	}
}