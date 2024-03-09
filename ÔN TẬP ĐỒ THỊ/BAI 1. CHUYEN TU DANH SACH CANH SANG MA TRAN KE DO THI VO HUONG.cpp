// Ngay 05/01/2023. DUYET DO THI:		
//				BAI 1: CHUYEN TU DANH SACH CANH SANG MA TRAN KE DO THI VO HUONG
/* INPUT: Do thi co n dinh, m canh.
m dong tiep theo la nhap cap so gom dinh dau va dinh cuoi (a,b). 
Giai: Tao mt ke KE[][], cap so (a,b) den dau thi ke[a][b]=ke[b][a]=1 den do */
#include<bits/stdc++.h>
using namespace std;
int main(){
	int dinh, canh;
	cin>>dinh>>canh;//so dinh do thi
	int ke[dinh][dinh]={};
	while(canh--){
		int dau, cuoi;
		cin>>dau>>cuoi;
		ke[dau-1][cuoi-1]=ke[cuoi-1][dau-1]=1;
	}
	for(int i=0;i<dinh;i++){
		for(int j=0;j<dinh;j++){
			cout<<ke[i][j]<<" ";
		}
		cout<<endl;
	}
}
/* Sample:
IN: 
5 9
1 4
1 3
1 2
3 5
2 4
2 5
3 4
2 3
4 5
OUT:
0 1 1 1 0 
1 0 1 1 1 
1 1 0 1 1 
1 1 1 0 1 
0 1 1 1 0 
 */