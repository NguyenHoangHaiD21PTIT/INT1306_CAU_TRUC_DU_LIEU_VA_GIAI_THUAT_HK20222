#include<bits/stdc++.h>
using namespace std;

int x[100], cot[100], xuoi[100], nguoc[100], res=0, a[10][10]; //x[i]=j tuc la dat quan hau hang i cot j

void Try(int i, int sum){
	for(int j=1;j<=8;j++){
		if(cot[j]==0&&xuoi[i+j-1]==0&&nguoc[8+i-j]==0){
			x[i] = j;
			sum+=a[i][j];
			cot[j]=1;xuoi[i+j-1]=1;nguoc[8+i-j]=1;
			if(i==8){
				res=max(res,sum);
			} else {
				Try(i+1, sum);
			}
			sum-=a[i][j];
			cot[j]=0;xuoi[i+j-1]=0;nguoc[8+i-j]=0;
		}
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		for(int i=1;i<=8;i++){
			for(int j=1;j<=8;j++) cin>>a[i][j];
		}
		Try(1,0);
		cout<<res<<endl;
	}
}