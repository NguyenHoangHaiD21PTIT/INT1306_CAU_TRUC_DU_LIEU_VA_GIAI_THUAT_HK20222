#include<bits/stdc++.h>
using namespace std;

long long f[1001]; //f[x] la so nho nhat tu 0 va 1 chia het cho x

void gen(){ //Sinh tat ca cac so tu 0 den 1
	//Buoc 1: Khoi tao
	queue<long long>q;
	vector<long long>v;
	q.push(1);
	v.push_back(1);
	
	//Buoc 2: Lap chung nao so <=1e18 --> Tao ra tap so chi chua 0 va 1
	while(1){
		long long x = q.front();
		q.pop();
		if(x==1e18) break;
		long long x1 = x*10;
		long long x2 = x*10 + 1;
		q.push(x1); q.push(x2);
		v.push_back(x1); v.push_back(x2);
	}
	for(int i = 1;i<=999;i++){
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