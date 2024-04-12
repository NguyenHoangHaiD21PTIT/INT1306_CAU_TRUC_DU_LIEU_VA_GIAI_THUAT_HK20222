#include<bits/stdc++.h>
using namespace std;

vector<long long>v;

void gen(){
	priority_queue<long long, vector<long long>, greater<long long>>pq;
	unordered_map<long long, bool>m;
	//Bước 1: Khởi tạo
	pq.push(1);
	//Bước 2: Lặp
	while(v.size()<10004){
		long long tmp = pq.top();//Lấy số nhỏ nhất hiện tại để loang
		pq.pop();
		v.push_back(tmp);
		if(!m[tmp * 2]){
            pq.push(tmp * 2);
            m[tmp * 2] = 1;
        }
        if(!m[tmp * 3]){
            pq.push(tmp * 3);
            m[tmp * 3] = 1;
        }
        if(!m[tmp * 5]){
            pq.push(tmp * 5);
            m[tmp * 5] = 1;
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
		cout<<v[n - 1]<<endl;
	}
}