#include<bits/stdc++.h>
using namespace std;

int C[300][300];//C[x][y]: To hop chap y cua x

void tohop(){
	//1. Chi so duoi i
	for(int i=0;i<=290;i++){
		//2. Chi so tren j
		for(int j=0;j<=i;j++){
			if(j==0||j==i){
				C[i][j]=1;
			} else {
				C[i][j] = C[i-1][j] + C[i-1][j-1];
			}
		}
	}
}

int main(){
	tohop();
	int t;
	cin>>t;
	while(t--){
		int hang, cot;
		cin>>hang>>cot;
		int a[hang][cot];
		for(int i=0;i<hang;i++){
			for(int j=0;j<cot;j++){
				cin>>a[i][j];
			}
		}
		int x = hang -1;
		int y = cot -1;
		cout<<C[x+y][x]<<endl;
	}
}