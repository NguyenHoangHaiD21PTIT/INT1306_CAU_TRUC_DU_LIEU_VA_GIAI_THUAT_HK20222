#include<bits/stdc++.h>
using namespace std;

int main(){
	int hang, cot;
	cin>>hang>>cot;
	int a[hang][cot];
	for(int i=0;i<hang;i++){
		for(int j=0;j<cot;j++) cin>>a[i][j];
	}
	for(int i=0;i<hang;i++){
		for(int j=0;j<cot;j++){
			if(i==0&&j!=0){ 
				a[i][j]+=a[i][j-1]; 
			} else if (i!=0&&j==0){ 
				a[i][j]+=a[i-1][j];
			} else if (i!=0&&j!=0) {
				a[i][j]+=max(a[i-1][j], a[i][j-1]);
			}
		}
	}
	cout<<a[hang-1][cot-1]<<endl;
}
