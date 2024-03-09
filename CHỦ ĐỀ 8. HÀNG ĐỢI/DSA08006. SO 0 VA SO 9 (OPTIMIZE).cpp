#include<bits/stdc++.h>
using namespace std;

long long f[105]; //f[x] la so nho nhat tu 0 va 9 chia het cho x

void gen(){ //Sinh tat ca cac so tu 0 den 9
	//Buoc 1: Khoi tao
	queue<string>q;
	vector<long long>v;
	q.push("9");
	v.push_back(9);
	
	//Buoc 2: Lap chung nao do dai so <=19 --> Tao ra tap so chi chua 0 va 9
	while(1){
		string x = q.front();
		q.pop();
		if(x.size()==11) break;
		string x1 = x + "0";
		string x2 = x + "9";
		q.push(x1); q.push(x2);
		v.push_back(stoll(x1));
		v.push_back(stoll(x2));
	}
	
	for(int i = 1;i<=100;i++){
		for(auto j: v){
			if(j%i==0){
				f[i] = j;
				break;
			}
		}
	}
}

int main(){
	gen();
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		cout<<f[n]<<endl;
	}
}