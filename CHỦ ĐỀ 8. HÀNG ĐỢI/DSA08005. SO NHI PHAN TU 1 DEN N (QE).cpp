#include<bits/stdc++.h>
using namespace std;

vector<string>v;//tap cac xau nhi phan

void gen(){
	queue<string>q;
	//Buoc 1: Khoi tao
	q.push("1");
	v.push_back("1");
	
	/*Buoc 2: Lap
	Moi lan, lay phan tu dau hang doi va xoa no di, tao ra 2 cai moi: 1 cai them 0, cai them 1 vao duoi
	Day lai 2 so nay vao trong qe */
	while(v.size()<=10000){
		string x = q.front();
		q.pop();
		string x1 = x + "0";
		string x2 = x + "1";
		v.push_back(x1); v.push_back(x2); 
		q.push(x1); q.push(x2);
	}
}

int main(){
	gen();
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i = 0;i<n;i++) cout<<v[i]<<" ";
		cout<<endl;
	}
}