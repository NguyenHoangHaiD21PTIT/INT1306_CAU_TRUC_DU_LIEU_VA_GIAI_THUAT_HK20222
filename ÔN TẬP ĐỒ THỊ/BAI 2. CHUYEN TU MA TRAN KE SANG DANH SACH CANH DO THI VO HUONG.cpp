/*	Ngay 06/01/2023: 			Bai 3. CHUYEN TU MA TRAN KE SANG DANH SACH CANH DO THI VO HUONG
									____________________________________________ */
#include<bits/stdc++.h>
using namespace std;
int main(){
	int dinh;
	cin>>dinh;
	int a[100][100];//ma tran ke
	for(int i=0;i<dinh;i++){
		for(int j=0;j<dinh;j++){
			cin>>a[i][j];
		}
	}
	for(int i=0;i<dinh;i++){
		for(int j=0;j<dinh;j++){
			if(a[i][j]==1&&i<j){
				cout<<i+1<<" "<<j+1<<endl;
			}
		}
	}
}