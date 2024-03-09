#include<bits/stdc++.h>
using namespace std;

set<int>ke[20];
int a[20][20];

int main(){
	int dinh, v;//Tim chu trinh O le tu dinh v;
	cin>>dinh>>v;
	
	//Nhap ma tran va chuyen sang ds ke
	for(int i=1;i<=dinh;i++){
		for(int j=1;j<=dinh;j++){
			cin>>a[i][j];
			if(a[i][j]) ke[i].insert(j);
		}
	}
	
	//Thuat toan tim duong di Euler
	//Buoc 1: Khoi tao
	stack<int>st;
	st.push(v);
	vector<int>CE;
	//Buoc 2: Lap
	while(st.size()!=0){
		int x = st.top();
		if(ke[x].size()!=0){
			int p = *ke[x].begin();
			st.push(p);
			//Xoa canh(x,p)
			ke[x].erase(p);
			ke[p].erase(x);
		} else {
			st.pop();
			CE.push_back(x);
		}
	}
	//Buoc 3: Lat nguoc vector CE
	reverse(CE.begin(),CE.end());
	for(int i: CE) cout<<i<<" ";
}